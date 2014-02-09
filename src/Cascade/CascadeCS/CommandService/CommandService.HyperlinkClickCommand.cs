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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Documents;

namespace Sibbiheim.Cascade
{
    public partial class CommandService
    {
        private static readonly DependencyProperty _hyperlinkClickCommandProperty = DependencyProperty.RegisterAttached(
            "HyperlinkClickCommand", typeof(ICommand), typeof(CommandService), new PropertyMetadata(null, OnHyperlinkClickCommandChanged));

        public static DependencyProperty HyperlinkClickCommandProperty
        {
            get { return _itemClickCommandProperty; }
        }

        public static ICommand GetHyperlinkClickCommand(Hyperlink element)
        {
            return element.GetValue(HyperlinkClickCommandProperty) as ICommand;
        }

        public static void SetHyperlinkClickCommand(Hyperlink element, ICommand value)
        {
            element.SetValue(HyperlinkClickCommandProperty, value);
        }

        public static void OnHyperlinkClickCommandChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            Hyperlink element = d as Hyperlink;
            ICommand command = e.NewValue as ICommand;

            if (element != null)
            {
                if (command != null)
                {
                    element.Click += OnHyperlinkClicked;
                }
                else
                {
                    element.Click -= OnHyperlinkClicked;
                }
            }
        }

        static void OnHyperlinkClicked(Hyperlink sender, HyperlinkClickEventArgs args)
        {
            Hyperlink element = sender as Hyperlink;

            if (element != null)
            {
                ICommand command = GetHyperlinkClickCommand(element);

                if (command != null && command.CanExecute(null))
                {
                    command.Execute(null);
                }
            }
        }
    }
}