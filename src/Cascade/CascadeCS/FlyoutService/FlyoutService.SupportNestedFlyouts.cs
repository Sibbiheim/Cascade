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
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;

namespace Sibbiheim.Cascade
{
    public partial class FlyoutService
    {
        private static readonly DependencyProperty _supportNestedFlyoutsProperty = DependencyProperty.RegisterAttached(
            "SupportNestedFlyouts", typeof(Boolean), typeof(FlyoutService), new PropertyMetadata(false, OnSupportNestedFlyoutsChanged));

        public static DependencyProperty SupportNestedFlyoutsProperty
        {
            get { return _supportNestedFlyoutsProperty; }
        }

        public static Boolean GetSupportNestedFlyouts(Button element)
        {
            return (Boolean)element.GetValue(SupportNestedFlyoutsProperty);
        }

        public static void SetSupportNestedFlyouts(Button element, Boolean value)
        {
            element.SetValue(SupportNestedFlyoutsProperty, value);
        }

        private static void OnSupportNestedFlyoutsChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            Button button = d as Button;
            bool supportNestedFlyouts = (Boolean)e.NewValue;

            if (button != null)
            {
                if (supportNestedFlyouts)
                {
                    button.Click += OnButtonWithFlyoutClicked;
                }
                else
                {
                    button.Click -= OnButtonWithFlyoutClicked;
                }
            }
        }

        private static void OnButtonWithFlyoutClicked(object sender, RoutedEventArgs e)
        {
            Button button = sender as Button;
            if (button != null)
            {
                FlyoutBase flyout = button.Flyout;
                if (flyout != null)
                {
                    SetFlyoutContext(flyout, button);
                }
            }
        }
    }
}
