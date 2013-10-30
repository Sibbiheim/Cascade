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
		public ref class StrategyTemplateSelectingArgs sealed
		{
		private:

			Platform::Object^ m_item;
			Windows::UI::Xaml::DependencyObject^ m_container;

		internal:

			StrategyTemplateSelectingArgs(Platform::Object^ item, Windows::UI::Xaml::DependencyObject^ container);

		public:

			property Platform::Object^ Item
			{
				Platform::Object^ get();
			}

			property Windows::UI::Xaml::DependencyObject^ Container
			{
				Windows::UI::Xaml::DependencyObject^ get();
			}

			property int TemplateIndexResult;
		};

		[Windows::Foundation::Metadata::WebHostHidden]
		public ref class StrategyTemplateSelector sealed : Windows::UI::Xaml::Controls::StyleSelector
		{
		public:

			StrategyTemplateSelector();

			event Windows::Foundation::EventHandler<StrategyTemplateSelectingArgs^>^ Selecting;

			property Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DataTemplate^>^ Templates;

		protected:

			virtual Windows::UI::Xaml::DataTemplate^ SelectTemplateCore(Platform::Object^ item, Windows::UI::Xaml::DependencyObject^ container);
		};
	}
}