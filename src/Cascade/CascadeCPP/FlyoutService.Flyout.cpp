/*
* The MIT License (MIT)
*
* Copyright (c) 2013 Sibbiheim, LLC.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of
* this software and associated documentation files (the "Software"), to deal in
* the Software without restriction, including without limitation the rights to
* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
* the Software, and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
* FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
* IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <pch.h>
#include "FlyoutService.h"

using namespace Sibbiheim::Cascade;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Input;

DependencyProperty^ FlyoutService::_flyoutProperty = DependencyProperty::RegisterAttached(
	"Flyout", FlyoutBase::typeid, FlyoutService::typeid, ref new PropertyMetadata(nullptr, ref new PropertyChangedCallback(&FlyoutService::OnFlyoutChanged)));
DependencyProperty^ FlyoutService::_flyoutOwnerTappedTokenProperty = DependencyProperty::RegisterAttached(
	"FlyoutOwnerTappedToken", EventRegistrationToken::typeid, FlyoutService::typeid, ref new PropertyMetadata(nullptr));

DependencyProperty^ FlyoutService::FlyoutProperty::get()
{
	return _flyoutProperty;
}

FlyoutBase^ FlyoutService::GetFlyout(FrameworkElement^ element)
{
	return dynamic_cast<FlyoutBase^>(element->GetValue(_flyoutProperty));
}

void FlyoutService::SetFlyout(FrameworkElement^ element, FlyoutBase^ value)
{
	element->SetValue(_flyoutProperty, value);
}

bool FlyoutService::TryGetFlyoutOwnerTappedToken(FrameworkElement^ element, EventRegistrationToken& value)
{
	Box<EventRegistrationToken>^ box = dynamic_cast<Box<EventRegistrationToken>^>(element->GetValue(_flyoutOwnerTappedTokenProperty));
	if (box != nullptr)
	{
		value = box->Value;
		return true;
	}

	return false;
}

void FlyoutService::SetFlyoutOwnerTappedToken(FrameworkElement^ element)
{
	EventRegistrationToken value = element->Tapped += ref new TappedEventHandler(&FlyoutService::OnFlyoutOwnerTapped);
	element->SetValue(_flyoutOwnerTappedTokenProperty, value);
}

void FlyoutService::RemoveFlyoutOwnerTappedToken(FrameworkElement^ element, EventRegistrationToken value)
{
	element->Tapped -= value;
	element->SetValue(_flyoutOwnerTappedTokenProperty, nullptr);
}

void FlyoutService::OnFlyoutChanged(DependencyObject^ d, DependencyPropertyChangedEventArgs^ e)
{
	FrameworkElement^ element = dynamic_cast<FrameworkElement^>(d);
	FlyoutBase^ flyout = dynamic_cast<FlyoutBase^>(e->NewValue);

	if (element != nullptr)
	{
		EventRegistrationToken tappedToken;
		bool eventIsRegistered = TryGetFlyoutOwnerTappedToken(element, tappedToken);

		if (flyout != nullptr && !eventIsRegistered)
		{
			SetFlyoutOwnerTappedToken(element);
		}
		else if (flyout == nullptr && eventIsRegistered)
		{
			RemoveFlyoutOwnerTappedToken(element, tappedToken);
		}
	}
}

void FlyoutService::OnFlyoutOwnerTapped(Object^ sender, TappedRoutedEventArgs^ e)
{
	FrameworkElement^ element = dynamic_cast<FrameworkElement^>(sender);

	if (element != nullptr)
	{
		FlyoutBase^ flyout = GetFlyout(element);
		
		if (flyout != nullptr)
		{
			FrameworkElement^ flyoutContext = GetFlyoutContext(element);
			if (flyoutContext == nullptr)
			{
				flyoutContext = element;
			}

			SetFlyoutContext(flyout, flyoutContext);
			flyout->ShowAt(flyoutContext);
		}
	}
}