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
using Windows.Foundation;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;

namespace Sibbiheim.Cascade
{
    public partial class FlyoutService : DependencyObject
    {
        public static readonly DependencyProperty FlyoutProperty = DependencyProperty.RegisterAttached(
            "Flyout", typeof(FlyoutBase), typeof(FlyoutService), new PropertyMetadata(null, OnFlyoutChanged));

        public static FlyoutBase GetFlyout(FrameworkElement element)
        {
            return element.GetValue(FlyoutProperty) as FlyoutBase;
        }

        public static void SetFlyout(FrameworkElement element, FlyoutBase value)
        {
            element.SetValue(FlyoutProperty, value);
        }

        private static void OnFlyoutChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            FrameworkElement element = d as FrameworkElement;
            FlyoutBase flyout = e.NewValue as FlyoutBase;

            if (element != null)
            {
                if (flyout != null)
                {
                    element.Tapped += OnFlyoutOwnerTapped;
                }
                else
                {
                    element.Tapped -= OnFlyoutOwnerTapped;
                }
            }
        }

        private static void OnFlyoutOwnerTapped(object sender, RoutedEventArgs e)
        {
            FrameworkElement element = sender as FrameworkElement;

            if (element != null)
            {
                FlyoutBase flyout = GetFlyout(element);

                if (flyout != null)
                {
                    FrameworkElement flyoutContext = GetFlyoutContext(element);
                    if (flyoutContext == null)
                    {
                        flyoutContext = element;
                    }

                    SetFlyoutContext(flyout, flyoutContext);
                    flyout.ShowAt(flyoutContext);
                }
            }
        }
    }
}
