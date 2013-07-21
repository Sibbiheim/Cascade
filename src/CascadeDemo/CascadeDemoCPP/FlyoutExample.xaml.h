//
// FlyoutExample.xaml.h
// Declaration of the FlyoutExample class
//

#pragma once

#include "FlyoutExample.g.h"

namespace CascadeDemoCPP
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class FlyoutExample sealed
	{
	public:
		FlyoutExample();
	private:
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
