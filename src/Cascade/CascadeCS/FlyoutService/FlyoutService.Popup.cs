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
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Input;

namespace Sibbiheim.Cascade
{
    public partial class FlyoutService
    {
        private static DependencyProperty _popupProperty = DependencyProperty.RegisterAttached(
            "Popup", typeof(Popup), typeof(FlyoutService), new PropertyMetadata(null, OnPopupChanged));

        public static DependencyProperty PopupProperty
        {
            get { return _popupProperty; }
        }

        public static Popup GetPopup(FrameworkElement element)
        {
            return element.GetValue(PopupProperty) as Popup;
        }

        public static void SetPopup(FrameworkElement element, Popup value)
        {
            element.SetValue(PopupProperty, value);
        }

        private static void OnPopupChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            FrameworkElement element = d as FrameworkElement;
            Popup popup = e.NewValue as Popup;

            if (element != null)
            {
                if (popup != null)
                {
                    element.Tapped += OnPopupOwnerTapped;
                }
                else
                {
                    element.Tapped -= OnPopupOwnerTapped;
                }
            }
        }

        private static void OnPopupOwnerTapped(object sender, TappedRoutedEventArgs e)
        {
            FrameworkElement element = sender as FrameworkElement;

            if (element != null)
            {
                Popup popup = GetPopup(element);

                if (popup != null)
                {
                    popup.IsOpen = true;
                }
            }
        }
    }
}