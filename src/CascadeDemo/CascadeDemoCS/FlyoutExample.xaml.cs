using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The User Control item template is documented at http://go.microsoft.com/fwlink/?LinkId=234236

namespace CascadeDemoCS
{
    public sealed partial class FlyoutExample : Flyout
    {
        public FlyoutExample()
        {
            this.InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MenuFlyout flyout = new MenuFlyout() { Placement = FlyoutPlacementMode.Bottom };
            flyout.Items.Add(new MenuFlyoutItem() { Text = "From a design perspective, though, I wouldn't recommend it." });

            FrameworkElement flyoutContext = Sibbiheim.Cascade.FlyoutService.GetFlyoutContext(this);
            Sibbiheim.Cascade.FlyoutService.SetFlyoutContext(flyout, flyoutContext);
            flyout.ShowAt(flyoutContext);
        }
    }
}
