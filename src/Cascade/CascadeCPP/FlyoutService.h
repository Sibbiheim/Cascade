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

#pragma once

namespace Sibbiheim
{
	namespace Cascade
	{
		[Windows::Foundation::Metadata::WebHostHidden]
		public ref class FlyoutService : Windows::UI::Xaml::DependencyObject
		{
#pragma region Flyout

		private:

			static Windows::UI::Xaml::DependencyProperty^ _flyoutProperty;
			static Windows::UI::Xaml::DependencyProperty^ _flyoutOwnerTappedTokenProperty;
			
		public:

			static property Windows::UI::Xaml::DependencyProperty^ FlyoutProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static Windows::UI::Xaml::Controls::Primitives::FlyoutBase^ GetFlyout(Windows::UI::Xaml::FrameworkElement^ element);
			static void SetFlyout(Windows::UI::Xaml::FrameworkElement^ element, Windows::UI::Xaml::Controls::Primitives::FlyoutBase^ value);

		private:

			static bool TryGetFlyoutOwnerTappedToken(Windows::UI::Xaml::FrameworkElement^ element, Windows::Foundation::EventRegistrationToken& value);
			static void SetFlyoutOwnerTappedToken(Windows::UI::Xaml::FrameworkElement^ element);
			static void RemoveFlyoutOwnerTappedToken(Windows::UI::Xaml::FrameworkElement^ element, Windows::Foundation::EventRegistrationToken value);

			static void OnFlyoutChanged(Windows::UI::Xaml::DependencyObject^ d, Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e);
			static void OnFlyoutOwnerTapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e);
			
#pragma endregion

#pragma region SettingsFlyout

		private:

			static Windows::UI::Xaml::DependencyProperty^ _settingsFlyoutProperty;
			static Windows::UI::Xaml::DependencyProperty^ _settingsFlyoutOwnerTappedTokenProperty;

		public:

			static property Windows::UI::Xaml::DependencyProperty^ SettingsFlyoutProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static Windows::UI::Xaml::Controls::SettingsFlyout^ GetSettingsFlyout(Windows::UI::Xaml::FrameworkElement^ element);
			static void SetSettingsFlyout(Windows::UI::Xaml::FrameworkElement^ element, Windows::UI::Xaml::Controls::SettingsFlyout^ value);

		private:

			static void OnSettingsFlyoutChanged(Windows::UI::Xaml::DependencyObject^ d, Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e);
			static void OnSettingsFlyoutOwnerTapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e);

#pragma endregion

#pragma region Popup

		private:

			static Windows::UI::Xaml::DependencyProperty^ _popupProperty;
			static Windows::UI::Xaml::DependencyProperty^ _popupOwnerTappedTokenProperty;

		public:

			static property Windows::UI::Xaml::DependencyProperty^ PopupProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static Windows::UI::Xaml::Controls::Primitives::Popup^ GetPopup(Windows::UI::Xaml::FrameworkElement^ element);
			static void SetPopup(Windows::UI::Xaml::FrameworkElement^ element, Windows::UI::Xaml::Controls::Primitives::Popup^ value);

		private:

			static void OnPopupChanged(Windows::UI::Xaml::DependencyObject^ d, Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e);
			static void OnPopupOwnerTapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e);

#pragma endregion

#pragma region SupportNestedFlyouts

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

#pragma endregion

#pragma region FlyoutContext

		private:

			static Windows::UI::Xaml::DependencyProperty^ _flyoutContextProperty;

		public:

			static Windows::UI::Xaml::FrameworkElement^ GetFlyoutContext(Windows::UI::Xaml::DependencyObject^ obj);
			static void SetFlyoutContext(Windows::UI::Xaml::DependencyObject^ obj, Windows::UI::Xaml::FrameworkElement^ value);

#pragma endregion
		};
	}
}