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
    public partial class FlyoutService : DependencyObject
    {
        public static readonly DependencyProperty SupportNestedFlyoutsProperty = DependencyProperty.RegisterAttached(
            "SupportNestedFlyouts", typeof(Boolean), typeof(FlyoutService), new PropertyMetadata(false, OnSupportNestedFlyoutsChanged));

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
                    button.Click += OnButtonWithFlyoutClick;
                }
                else
                {
                    button.Click -= OnButtonWithFlyoutClick;
                }
            }
        }

        private static void OnButtonWithFlyoutClick(object sender, RoutedEventArgs e)
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
