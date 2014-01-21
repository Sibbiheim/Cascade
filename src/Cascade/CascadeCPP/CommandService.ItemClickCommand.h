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
		partial ref class CommandService
		{
		private:

			static Windows::UI::Xaml::DependencyProperty^ _itemClickCommandProperty;
			static Windows::UI::Xaml::DependencyProperty^ _itemClickTokenProperty;

		public:

			static property Windows::UI::Xaml::DependencyProperty^ ItemClickCommandProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static Windows::UI::Xaml::Input::ICommand^ GetItemClickCommand(Windows::UI::Xaml::Controls::ListViewBase^ element);
			static void SetItemClickCommand(Windows::UI::Xaml::Controls::ListViewBase^ element, Windows::UI::Xaml::Input::ICommand^ value);

		private:

			static Windows::Foundation::EventRegistrationToken GetItemClickToken(Windows::UI::Xaml::Controls::ListViewBase^ element);
			static void SetItemClickToken(Windows::UI::Xaml::Controls::ListViewBase^ element, Windows::Foundation::EventRegistrationToken value);

			static void OnItemClickCommandChanged(Windows::UI::Xaml::DependencyObject^ d, Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e);
			static void OnItemClicked(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		};
	}
}
