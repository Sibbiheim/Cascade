//
// FlyoutExample.xaml.cpp
// Implementation of the FlyoutExample class
//

#include "pch.h"
#include "FlyoutExample.xaml.h"

using namespace CascadeDemoCPP;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The User Control item template is documented at http://go.microsoft.com/fwlink/?LinkId=234236

FlyoutExample::FlyoutExample()
{
	InitializeComponent();
}


void CascadeDemoCPP::FlyoutExample::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	MenuFlyout^ flyout = ref new MenuFlyout();
	flyout->Placement = FlyoutPlacementMode::Bottom;
	
	MenuFlyoutItem^ item = ref new MenuFlyoutItem();
	item->Text = "From a design perspective, though, I wouldn't recommend it.";

	flyout->Items->Append(item);

	FrameworkElement^ flyoutContext = Sibbiheim::Cascade::FlyoutService::GetFlyoutContext(this);
	Sibbiheim::Cascade::FlyoutService::SetFlyoutContext(flyout, flyoutContext);
	flyout->ShowAt(flyoutContext);
}
