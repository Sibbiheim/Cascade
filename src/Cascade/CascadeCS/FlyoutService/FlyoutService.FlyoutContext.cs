using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;

namespace Sibbiheim.Cascade
{
    public partial class FlyoutService : DependencyObject
    {
        public static readonly DependencyProperty FlyoutContextProperty = DependencyProperty.RegisterAttached(
            "FlyoutContext", typeof(FrameworkElement), typeof(FlyoutService), new PropertyMetadata(null));

        public static FrameworkElement GetFlyoutContext(DependencyObject obj)
        {
            return obj.GetValue(FlyoutContextProperty) as FrameworkElement;
        }

        public static void SetFlyoutContext(DependencyObject obj, FrameworkElement value)
        {
            obj.SetValue(FlyoutContextProperty, value);
        }

        private static void SetFlyoutContext(FlyoutBase flyout, FrameworkElement value)
        {
            flyout.SetValue(FlyoutContextProperty, value);

            MenuFlyout menu = flyout as MenuFlyout;
            if (menu != null)
            {
                foreach (MenuFlyoutItemBase menuItem in menu.Items)
                {
                    menuItem.SetValue(FlyoutContextProperty, value);
                }
            }
        }
    }
}
