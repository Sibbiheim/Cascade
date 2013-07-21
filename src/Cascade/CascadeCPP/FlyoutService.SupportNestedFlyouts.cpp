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

DependencyProperty^ FlyoutService::_supportNestedFlyoutsProperty = DependencyProperty::RegisterAttached(
	"SupportNestedFlyouts", Boolean::typeid, FlyoutService::typeid, ref new PropertyMetadata(nullptr, ref new PropertyChangedCallback(&FlyoutService::OnSupportNestedFlyoutsChanged)));
DependencyProperty^ FlyoutService::_supportNestedFlyoutsClickedTokenProperty = DependencyProperty::RegisterAttached(
	"SupportNestedFlyoutsClickedToken", EventRegistrationToken::typeid, FlyoutService::typeid, ref new PropertyMetadata(nullptr));

DependencyProperty^ FlyoutService::SupportNestedFlyoutsProperty::get()
{
	return _supportNestedFlyoutsProperty;
}

Boolean FlyoutService::GetSupportNestedFlyouts(Button^ element)
{
	Box<Boolean>^ box = dynamic_cast<Box<Boolean>^>(element->GetValue(_supportNestedFlyoutsProperty));
	return box == nullptr || box->Value;
}

void FlyoutService::SetSupportNestedFlyouts(Button^ element, Boolean value)
{
	element->SetValue(_supportNestedFlyoutsProperty, value);
}

bool FlyoutService::TryGetSupportNestedFlyoutsClickedToken(Button^ button, EventRegistrationToken& value)
{
	Box<EventRegistrationToken>^ box = dynamic_cast<Box<EventRegistrationToken>^>(button->GetValue(_supportNestedFlyoutsClickedTokenProperty));
	if (box != nullptr)
	{
		value = box->Value;
		return true;
	}

	return false;
}

void FlyoutService::SetSupportNestedFlyoutsClickedToken(Button^ button)
{
	EventRegistrationToken value = button->Click += ref new RoutedEventHandler(&FlyoutService::OnButtonWithFlyoutClicked);
	button->SetValue(_supportNestedFlyoutsClickedTokenProperty, value);
}

void FlyoutService::RemoveSupportNestedFlyoutsClickedToken(Button^ button, EventRegistrationToken value)
{
	button->Click -= value;
	button->SetValue(_supportNestedFlyoutsClickedTokenProperty, nullptr);
}

void FlyoutService::OnSupportNestedFlyoutsChanged(DependencyObject^ d, DependencyPropertyChangedEventArgs^ e)
{
	Button^ button = dynamic_cast<Button^>(d);
	Box<Boolean>^ box = dynamic_cast<Box<Boolean>^>(e->NewValue);
	bool supportNestedFlyouts = box == nullptr || box->Value;

	if (button != nullptr)
	{
		EventRegistrationToken clickedToken;
		bool eventIsRegistered = TryGetSupportNestedFlyoutsClickedToken(button, clickedToken);

		if (supportNestedFlyouts && !eventIsRegistered)
		{
			SetSupportNestedFlyoutsClickedToken(button);
		}
		else if (!supportNestedFlyouts && eventIsRegistered)
		{
			RemoveSupportNestedFlyoutsClickedToken(button, clickedToken);
		}
	}
}

void FlyoutService::OnButtonWithFlyoutClicked(Object^ sender, RoutedEventArgs^ e)
{
	Button^ button = dynamic_cast<Button^>(sender);

	if (button != nullptr)
	{
		FlyoutBase^ flyout = button->Flyout;

		if (flyout != nullptr)
		{
			SetFlyoutContext(flyout, button);
		}
	}
}