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
* COPYRIGHT HOLD
ERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
* IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

namespace Sibbiheim
{
	namespace Cascade
	{
		partial ref class FlyoutService
		{
		private:

			static Windows::UI::Xaml::DependencyProperty^ _supportNestedFlyoutsProperty;
			static Windows::UI::Xaml::DependencyProperty^ _supportNestedFlyoutsClickedTokenProperty;

		public:

			static property Windows::UI::Xaml::DependencyProperty^ SupportNestedFlyoutsProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static Platform::Boolean GetSupportNestedFlyouts(Windows::UI::Xaml::Controls::Button^ element);
			static void SetSupportNestedFlyouts(Windows::UI::Xaml::Controls::Button^ element, Platform::Boolean value);

		private:

			static bool TryGetSupportNestedFlyoutsClickedToken(Windows::UI::Xaml::Controls::Button^ button, Windows::Foundation::EventRegistrationToken& value);
			static void SetSupportNestedFlyoutsClickedToken(Windows::UI::Xaml::Controls::Button^ button);
			static void RemoveSupportNestedFlyoutsClickedToken(Windows::UI::Xaml::Controls::Button^ button, Windows::Foundation::EventRegistrationToken value);

			static void OnSupportNestedFlyoutsChanged(Windows::UI::Xaml::DependencyObject^ d, Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e);
			static void OnButtonWithFlyoutClicked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		};
	}
}
