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
using namespace Windows::UI::Xaml::Documents;
using namespace Windows::UI::Xaml::Input;

DependencyProperty^ CommandService::_hyperlinkClickCommandProperty = DependencyProperty::RegisterAttached(
	"HyperlinkClickCommand", ICommand::typeid, CommandService::typeid, ref new PropertyMetadata(nullptr, ref new PropertyChangedCallback(&CommandService::OnHyperlinkClickCommandChanged)));
DependencyProperty^ CommandService::_hyperlinkClickTokenProperty = DependencyProperty::RegisterAttached(
	"HyperlinkClickToken", EventRegistrationToken::typeid, CommandService::typeid, ref new PropertyMetadata(nullptr));

DependencyProperty^ CommandService::HyperlinkClickCommandProperty::get()
{
	return _itemClickCommandProperty;
}

ICommand^ CommandService::GetHyperlinkClickCommand(Hyperlink^ element)
{
	return dynamic_cast<ICommand^>(element->GetValue(_hyperlinkClickCommandProperty));
}

void CommandService::SetHyperlinkClickCommand(Hyperlink^ element, ICommand^ value)
{
	element->SetValue(_hyperlinkClickCommandProperty, value);
}

EventRegistrationToken CommandService::GetHyperlinkClickToken(Hyperlink^ element)
{
	auto tokenBox = dynamic_cast<IBox<EventRegistrationToken>^>(element->GetValue(_hyperlinkClickTokenProperty));
	if (tokenBox != nullptr)
	{
		return tokenBox->Value;
	}
	else
	{
		return EventRegistrationToken();
	}
}

void CommandService::SetHyperlinkClickToken(Hyperlink^ element, EventRegistrationToken value)
{
	element->SetValue(_hyperlinkClickTokenProperty, value);
}

void CommandService::OnHyperlinkClickCommandChanged(DependencyObject^ d, DependencyPropertyChangedEventArgs^ e)
{
	Hyperlink^ element = dynamic_cast<Hyperlink^>(d);
	ICommand^ command = dynamic_cast<ICommand^>(e->NewValue);

	if (element != nullptr)
	{
		EventRegistrationToken itemClickToken = GetHyperlinkClickToken(element);
		bool eventIsRegistered = itemClickToken.Value == 0;

		if (command != nullptr && !eventIsRegistered)
		{
			itemClickToken = element->Click += ref new TypedEventHandler<Hyperlink^, HyperlinkClickEventArgs^>(&CommandService::OnHyperlinkClicked);
			SetHyperlinkClickToken(element, itemClickToken);
		}
		else if (command == nullptr && eventIsRegistered)
		{
			element->Click -= itemClickToken;
			SetHyperlinkClickToken(element, EventRegistrationToken());
		}
	}
}

void CommandService::OnHyperlinkClicked(Hyperlink^ sender, HyperlinkClickEventArgs^ e)
{
	ICommand^ command = GetHyperlinkClickCommand(sender);

	if (command != nullptr)
	{
		if (command->CanExecute(nullptr))
		{
			command->Execute(nullptr);
		}
	}
}