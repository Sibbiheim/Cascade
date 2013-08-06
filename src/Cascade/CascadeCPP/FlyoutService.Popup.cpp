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
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Input;

DependencyProperty^ FlyoutService::_popupProperty = DependencyProperty::RegisterAttached(
	"Popup", Popup::typeid, FlyoutService::typeid, ref new PropertyMetadata(nullptr, ref new PropertyChangedCallback(&FlyoutService::OnPopupChanged)));
DependencyProperty^ FlyoutService::_popupOwnerTappedTokenProperty = DependencyProperty::RegisterAttached(
	"PopupOwnerTappedToken", EventRegistrationToken::typeid, FlyoutService::typeid, ref new PropertyMetadata(nullptr));

DependencyProperty^ FlyoutService::PopupProperty::get()
{
	return _popupProperty;
}

Popup^ FlyoutService::GetPopup(FrameworkElement^ element)
{
	return dynamic_cast<Popup^>(element->GetValue(PopupProperty));
}

void FlyoutService::SetPopup(FrameworkElement^ element, Popup^ value)
{
	element->SetValue(PopupProperty, value);
}

void FlyoutService::OnPopupChanged(DependencyObject^ d, DependencyPropertyChangedEventArgs^ e)
{
	FrameworkElement^ element = dynamic_cast<FrameworkElement^>(d);
	Popup^ popup = dynamic_cast<Popup^>(e->NewValue);

	if (element != nullptr)
	{
		Box<EventRegistrationToken>^ tokenBox = dynamic_cast<Box<EventRegistrationToken>^>(element->GetValue(_popupOwnerTappedTokenProperty));
		if (popup != nullptr && tokenBox == nullptr)
		{
			EventRegistrationToken token = element->Tapped += ref new Windows::UI::Xaml::Input::TappedEventHandler(&FlyoutService::OnPopupOwnerTapped);
			element->SetValue(_popupOwnerTappedTokenProperty, token);
		}
		else
		{
			element->Tapped -= tokenBox->Value;
			element->SetValue(_popupOwnerTappedTokenProperty, nullptr);
		}
	}
}

void FlyoutService::OnPopupOwnerTapped(Object^ sender, TappedRoutedEventArgs^ e)
{
	FrameworkElement^ element = dynamic_cast<FrameworkElement^>(sender);

	if (element != nullptr)
	{
		Popup^ popup = GetPopup(element);

		if (popup != nullptr)
		{
			popup->IsOpen = true;
		}
	}
}