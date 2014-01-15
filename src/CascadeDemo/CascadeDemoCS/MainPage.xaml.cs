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

namespace CascadeDemoCS
{
    public sealed class Topic
    {
        public string Title { get; set; }

        public string Description { get; set; }
        public Type Page { get; set; }
    }

    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
            topicList.Items.Add(new Topic() { Title = "Using the library", Description = "Include Sibbiheim.Cascade in your project and get started using it", Page = typeof(ProjectUsage) });
            topicList.Items.Add(new Topic() { Title = "FlyoutService", Description = "Construct complex, functional Flyout interactions entirely in XAML", Page = typeof(FlyoutService) });
            topicList.Items.Add(new Topic() { Title = "CommandService", Description = "Handle Events with ICommands instead of code-behind handlers", Page = typeof(CommandService) });
            topicList.Items.Add(new Topic() { Title = "CascadeConverter", Description = "Combine converters together to create more specific ones", Page = typeof(CascadeConverter) });
            topicList.Items.Add(new Topic() { Title = "Strategy Pattern Tools", Description = "Implement very specific converters and selectors without creating new files and classes", Page = typeof(StrategyTools) });
            topicList.Items.Add(new Topic() { Title = "Feedback", Description = "Alert us to bugs and suggest new features", Page = typeof(Feedback) });
        }

        private void OnScenarioSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var topic = topicList.SelectedItem as Topic;
            if (topic != null && topic.Page != null)
            {
                topicFrame.Navigate(topic.Page);
            }
        }
    }
}
