using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace CascadeDemoCS
{
    public sealed class CommandServiceViewModel : INotifyPropertyChanged
    {
        private sealed class SpecificCommand : ICommand
        {
            CommandServiceViewModel m_owner;

            public SpecificCommand(CommandServiceViewModel owner)
            {
                m_owner = owner;
            }

            public event EventHandler CanExecuteChanged;

            public void Execute(object parameter)
            {
                m_owner.ClickText = parameter as string;
                if (m_owner.PropertyChanged != null)
                {
                    m_owner.PropertyChanged(this, new PropertyChangedEventArgs("ClickText"));
                }
            }

            public bool CanExecute(object parameter)
            {
                return true;
            }
        }

        public CommandServiceViewModel()
        {
            ClickText = "No item";
            ItemClickCommand = new SpecificCommand(this);
        }

        public event PropertyChangedEventHandler PropertyChanged;

        public string ClickText { get; private set; }

        public ICommand ItemClickCommand { get; private set; }
    }
}
