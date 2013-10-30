﻿/*
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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Data;

namespace Sibbiheim.Cascade
{
    public sealed class StrategyConvertingArgs : EventArgs
    {
        internal StrategyConvertingArgs(object value, Type targetType, object parameter, string language)
        {
            Value = value;
            TargetType = targetType;
            Parameter = parameter;
            Language = language;
        }

        public object Value { get; private set; }

        public Type TargetType { get; private set; }

        public object Parameter { get; private set; }

        public string Language { get; private set; }

        public object Result { get; set; }
    }

    public sealed class StrategyConverter : IValueConverter
    {
        public event EventHandler<StrategyConvertingArgs> Converting;

        public event EventHandler<StrategyConvertingArgs> ConvertingBack;

        public object Convert(object value, Type targetType, object parameter, string language)
        {
            if (Converting != null)
            {
                StrategyConvertingArgs args = new StrategyConvertingArgs(value, targetType, parameter, language);
                Converting(this, args);
                return args.Result;
            }
            else
            {
                throw new InvalidOperationException();
            }
        }

        public object ConvertBack(object value, Type targetType, object parameter, string language)
        {
            if (ConvertingBack != null)
            {
                StrategyConvertingArgs args = new StrategyConvertingArgs(value, targetType, parameter, language);
                ConvertingBack(this, args);
                return args.Result;
            }
            else
            {
                throw new InvalidOperationException();
            }
        }
    }
}
