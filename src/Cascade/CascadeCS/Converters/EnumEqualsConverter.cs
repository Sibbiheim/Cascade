using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI.Xaml.Data;

namespace Sibbiheim.Cascade
{
    public sealed class EnumEqualsConverter : IValueConverter
    {
        public object Value { get; set; }

        public object Convert(object value, Type targetType, object parameter, string language)
        {
            object compareValue = Enum.Parse(value.GetType(), Value.ToString());
            return value.Equals(compareValue);
        }

        public object ConvertBack(object value, Type targetType, object parameter, string language)
        {
            throw new InvalidOperationException();
        }
    }
}
