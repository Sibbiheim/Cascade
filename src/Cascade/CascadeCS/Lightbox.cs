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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Media;

namespace Sibbiheim.Cascade
{
    public sealed class Lightbox
    {
        public static DependencyProperty BackgroundProperty = DependencyProperty.RegisterAttached(
            "Background", typeof(Brush), typeof(Lightbox), new PropertyMetadata(null));

        public static DependencyProperty ContentMarginProperty = DependencyProperty.RegisterAttached(
            "ContentMargin", typeof(Thickness), typeof(Lightbox), new PropertyMetadata(new Thickness(0)));

        public static DependencyProperty ContentMinWidthProperty = DependencyProperty.RegisterAttached(
            "ContentMinWidth", typeof(double), typeof(Lightbox), new PropertyMetadata(0));

        public static DependencyProperty ContentMaxWidthProperty = DependencyProperty.RegisterAttached(
            "ContentMaxWidth", typeof(double), typeof(Lightbox), new PropertyMetadata(0));

        public static DependencyProperty ContentMinHeightProperty = DependencyProperty.RegisterAttached(
            "ContentMinHeight", typeof(double), typeof(Lightbox), new PropertyMetadata(0));

        public static DependencyProperty ContentMaxHeightProperty = DependencyProperty.RegisterAttached(
            "ContentMaxHeight", typeof(double), typeof(Lightbox), new PropertyMetadata(0));

        private Lightbox()
        {
        }

        public static Brush GetBackground(FlyoutPresenter element)
        {
            return element.GetValue(BackgroundProperty) as Brush;
        }

        public static void SetBackground(FlyoutPresenter element, Brush value)
        {
            element.SetValue(BackgroundProperty, value);
        }

        public static Thickness GetContentMargin(FlyoutPresenter element)
        {
            return (Thickness)element.GetValue(ContentMarginProperty);
        }

        public static void SetContentMargin(FlyoutPresenter element, Thickness value)
        {
            element.SetValue(ContentMarginProperty, value);
        }

        public static double GetContentMinWidth(FlyoutPresenter element)
        {
            return (double)element.GetValue(ContentMinWidthProperty);
        }

        public static void SetContentMinWidth(FlyoutPresenter element, double value)
        {
            element.SetValue(ContentMinWidthProperty, value);
        }

        public static double GetContentMaxWidth(FlyoutPresenter element)
        {
            return (double)element.GetValue(ContentMaxWidthProperty);
        }

        public static void SetContentMaxWidth(FlyoutPresenter element, double value)
        {
            element.SetValue(ContentMaxWidthProperty, value);
        }

        public static double GetContentMinHeight(FlyoutPresenter element)
        {
            return (double)element.GetValue(ContentMinHeightProperty);
        }

        public static void SetContentMinHeight(FlyoutPresenter element, double value)
        {
            element.SetValue(ContentMinHeightProperty, value);
        }

        public static double GetContentMaxHeight(FlyoutPresenter element)
        {
            return (double)element.GetValue(ContentMaxHeightProperty);
        }

        public static void SetContentMaxHeight(FlyoutPresenter element, double value)
        {
            element.SetValue(ContentMaxHeightProperty, value);
        }
    }
}
