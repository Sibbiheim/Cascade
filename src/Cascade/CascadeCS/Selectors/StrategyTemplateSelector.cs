using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace Sibbiheim.Cascade
{
    public sealed class StrategyTemplateSelectingArgs : EventArgs
    {
        public StrategyTemplateSelectingArgs(object item, DependencyObject container)
        {
            Item = item;
            Container = container;
        }

        public object Item { get; private set; }

        public DependencyObject Container { get; private set; }

        public int TemplateIndexResult { get; set; }
    }

    public sealed class StrategyTemplateSelector : DataTemplateSelector
    {
        public List<DataTemplate> Templates { get; set; }

        public event EventHandler<StrategyTemplateSelectingArgs> Selecting;

        protected override DataTemplate SelectTemplateCore(object item, DependencyObject container)
        {
            if (Selecting != null)
            {
                var args = new StrategyTemplateSelectingArgs(item, container);
                Selecting(this, args);
                return Templates[args.TemplateIndexResult];
            }

            throw new ArgumentException();
        }
    }
}
