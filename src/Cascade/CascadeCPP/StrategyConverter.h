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
		public ref class StrategyConvertingArgs sealed
		{
		private:

			Platform::Object^ m_value;
			Windows::UI::Xaml::Interop::TypeName m_targetType;
			Platform::Object^ m_parameter;
			Platform::String^ m_language;

		internal:

			StrategyConvertingArgs(Platform::Object^ value, Windows::UI::Xaml::Interop::TypeName targetType, Platform::Object^ parameter, Platform::String^ language);

		public:

			property Platform::Object^ Value
			{
				Platform::Object^ get();
			}

			property Windows::UI::Xaml::Interop::TypeName TargetType
			{
				Windows::UI::Xaml::Interop::TypeName get();
			}

			property Platform::Object^ Parameter
			{
				Platform::Object^ get();
			}

			property Platform::String^ Language
			{
				Platform::String^ get();
			}

			property Platform::Object^ Result;
		};

		[Windows::Foundation::Metadata::WebHostHidden]
		public ref class StrategyConverter sealed : Windows::UI::Xaml::Data::IValueConverter
		{
		public:

			event Windows::Foundation::EventHandler<StrategyConvertingArgs^>^ Converting;
			event Windows::Foundation::EventHandler<StrategyConvertingArgs^>^ ConvertingBack;

			virtual Platform::Object^ Convert(Platform::Object^ value, Windows::UI::Xaml::Interop::TypeName targetType, Platform::Object^ parameter, Platform::String^ language);
			virtual Platform::Object^ ConvertBack(Platform::Object^ value, Windows::UI::Xaml::Interop::TypeName targetType, Platform::Object^ parameter, Platform::String^ language);
		};
	}
}