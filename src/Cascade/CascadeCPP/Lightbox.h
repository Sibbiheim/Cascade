/*
* The MIT License (MIT)
*
* Copyright (c) 2014 Sibbiheim, LLC.
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
		public ref class Lightbox sealed
		{
		private:

			static Windows::UI::Xaml::DependencyProperty^ _backgroundProperty;

			static Windows::UI::Xaml::DependencyProperty^ _contentMarginProperty;

			static Windows::UI::Xaml::DependencyProperty^ _contentMinWidthProperty;
			static Windows::UI::Xaml::DependencyProperty^ _contentMaxWidthProperty;

			static Windows::UI::Xaml::DependencyProperty^ _contentMinHeightProperty;
			static Windows::UI::Xaml::DependencyProperty^ _contentMaxHeightProperty;

		private:

			Lightbox();

		public:

			static property Windows::UI::Xaml::DependencyProperty^ BackgroundProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static property Windows::UI::Xaml::DependencyProperty^ ContentMarginProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static property Windows::UI::Xaml::DependencyProperty^ ContentMinWidthProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static property Windows::UI::Xaml::DependencyProperty^ ContentMaxWidthProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static property Windows::UI::Xaml::DependencyProperty^ ContentMinHeightProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static property Windows::UI::Xaml::DependencyProperty^ ContentMaxHeightProperty
			{
				Windows::UI::Xaml::DependencyProperty^ get();
			}

			static Windows::UI::Xaml::Media::Brush^ GetBackground(Windows::UI::Xaml::Controls::FlyoutPresenter^ element);
			static void SetBackground(Windows::UI::Xaml::Controls::FlyoutPresenter^ element, Windows::UI::Xaml::Media::Brush^ value);

			static Windows::UI::Xaml::Thickness GetContentMargin(Windows::UI::Xaml::Controls::FlyoutPresenter^ element);
			static void SetContentMargin(Windows::UI::Xaml::Controls::FlyoutPresenter^ element, Windows::UI::Xaml::Thickness value);

			static double GetContentMinWidth(Windows::UI::Xaml::Controls::FlyoutPresenter^ element);
			static void SetContentMinWidth(Windows::UI::Xaml::Controls::FlyoutPresenter^ element, double value);

			static double GetContentMaxWidth(Windows::UI::Xaml::Controls::FlyoutPresenter^ element);
			static void SetContentMaxWidth(Windows::UI::Xaml::Controls::FlyoutPresenter^ element, double value);

			static double GetContentMinHeight(Windows::UI::Xaml::Controls::FlyoutPresenter^ element);
			static void SetContentMinHeight(Windows::UI::Xaml::Controls::FlyoutPresenter^ element, double value);

			static double GetContentMaxHeight(Windows::UI::Xaml::Controls::FlyoutPresenter^ element);
			static void SetContentMaxHeight(Windows::UI::Xaml::Controls::FlyoutPresenter^ element, double value);
		};
	}
}