/*
* The MIT License (MIT)
*
* Copyright (c) 2013 Sibbiheim, LLC.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of
* this software and associated documentation files (the "Software"), to deal in
* the Software without restriction, including without limitation the rights to
* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
* the Software, and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
* FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
* IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <pch.h>
#include "CommandService.h"

using namespace Sibbiheim::Cascade;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Input;

DependencyProperty^ CommandService::_itemClickCommandProperty = DependencyProperty::RegisterAttached(
	"ItemClickCommand", ICommand::typeid, CommandService::typeid, ref new PropertyMetadata(nullptr, ref new PropertyChangedCallback(&CommandService::OnItemClickCommandChanged)));
DependencyProperty^ CommandService::_itemClickTokenProperty = DependencyProperty::RegisterAttached(
	"ItemClickToken", EventRegistrationToken::typeid, CommandService::typeid, ref new PropertyMetadata(nullptr));

DependencyProperty^ CommandService::ItemClickCommandProperty::get()
{
	return _itemClickCommandProperty;
}

ICommand^ CommandService::GetItemClickCommand(ListViewBase^ element)
{
	return dynamic_cast<ICommand^>(element->GetValue(_itemClickCommandProperty));
}

void CommandService::SetItemClickCommand(ListViewBase^ element, ICommand^ value)
{
	element->SetValue(_itemClickCommandProperty, value);
}

EventRegistrationToken CommandService::GetItemClickToken(ListViewBase^ element)
{
	auto tokenBox = dynamic_cast<IBox<EventRegistrationToken>^>(element->GetValue(_itemClickTokenProperty));
	if (tokenBox != nullptr)
	{
		return tokenBox->Value;
	}
	else
	{
		return EventRegistrationToken();
	}
}

void CommandService::SetItemClickToken(ListViewBase^ element, EventRegistrationToken value)
{
	element->SetValue(_itemClickTokenProperty, value);
}

void CommandService::OnItemClickCommandChanged(DependencyObject^ d, DependencyPropertyChangedEventArgs^ e)
{
	ListViewBase^ element = dynamic_cast<ListViewBase^>(d);
	ICommand^ command = dynamic_cast<ICommand^>(e->NewValue);

	if (element != nullptr)
	{
		EventRegistrationToken itemClickToken = GetItemClickToken(element);
		bool eventIsRegistered = itemClickToken.Value == 0;

		if (command != nullptr && !eventIsRegistered)
		{
			itemClickToken = element->ItemClick += ref new Windows::UI::Xaml::Controls::ItemClickEventHandler(&CommandService::OnItemClicked);
			SetItemClickToken(element, itemClickToken);
		}
		else if (command == nullptr && eventIsRegistered)
		{
			element->ItemClick -= itemClickToken;
			SetItemClickToken(element, EventRegistrationToken());
		}
	}
}

void CommandService::OnItemClicked(Object^ sender, ItemClickEventArgs^ e)
{
	ListViewBase^ element = dynamic_cast<ListViewBase^>(sender);

	if (element != nullptr)
	{
		ICommand^ command = GetItemClickCommand(element);

		if (command != nullptr)
		{
			if (command->CanExecute(e->ClickedItem))
			{
				command->Execute(e->ClickedItem);
			}
		}
	}
}