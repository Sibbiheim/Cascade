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
using namespace Windows::UI::Xaml::Input;

DependencyProperty^ FlyoutService::_settingsFlyoutProperty = DependencyProperty::RegisterAttached(
	"SettingsFlyout", SettingsFlyout::typeid, FlyoutService::typeid, ref new PropertyMetadata(nullptr, ref new PropertyChangedCallback(&FlyoutService::OnSettingsFlyoutChanged)));
DependencyProperty^ FlyoutService::_settingsFlyoutOwnerTappedTokenProperty = DependencyProperty::RegisterAttached(
	"SettingsFlyoutOwnerTappedToken", EventRegistrationToken::typeid, FlyoutService::typeid, ref new PropertyMetadata(nullptr));

DependencyProperty^ FlyoutService::SettingsFlyoutProperty::get()
{
	return _settingsFlyoutProperty;
}

SettingsFlyout^ FlyoutService::GetSettingsFlyout(FrameworkElement^ element)
{
	return dynamic_cast<SettingsFlyout^>(element->GetValue(SettingsFlyoutProperty));
}

void FlyoutService::SetSettingsFlyout(FrameworkElement^ element, SettingsFlyout^ value)
{
	element->SetValue(SettingsFlyoutProperty, value);
}

void FlyoutService::OnSettingsFlyoutChanged(DependencyObject^ d, DependencyPropertyChangedEventArgs^ e)
{
	FrameworkElement^ element = dynamic_cast<FrameworkElement^>(d);
	SettingsFlyout^ flyout = dynamic_cast<SettingsFlyout^>(e->NewValue);

	if (element != nullptr)
	{
		Box<EventRegistrationToken>^ tokenBox = dynamic_cast<Box<EventRegistrationToken>^>(element->GetValue(_settingsFlyoutOwnerTappedTokenProperty));
		if (flyout != nullptr && tokenBox == nullptr)
		{
			EventRegistrationToken token = element->Tapped += ref new TappedEventHandler(&FlyoutService::OnSettingsFlyoutOwnerTapped);
			element->SetValue(_settingsFlyoutOwnerTappedTokenProperty, token);
		}
		else if (flyout == nullptr && tokenBox != nullptr)
		{
			element->Tapped -= tokenBox->Value;
			element->SetValue(_settingsFlyoutOwnerTappedTokenProperty, nullptr);
		}
	}
}

void FlyoutService::OnSettingsFlyoutOwnerTapped(Object^ sender, TappedRoutedEventArgs^ e)
{
	FrameworkElement^ element = dynamic_cast<FrameworkElement^>(sender);

	if (element != nullptr)
	{
		SettingsFlyout^ flyout = GetSettingsFlyout(element);

		if (flyout != nullptr)
		{
			flyout->ShowIndependent();
		}
	}
}