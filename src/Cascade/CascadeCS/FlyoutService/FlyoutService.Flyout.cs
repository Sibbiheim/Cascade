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
