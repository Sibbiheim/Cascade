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

#include "pch.h"
#include "StrategyStyleSelector.h"
#include <collection.h>

using namespace Sibbiheim::Cascade;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::Foundation::Collections;

StrategyStyleSelectingArgs::StrategyStyleSelectingArgs(Object^ item, DependencyObject^ container) :
m_item(item),
m_container(container)
{
	StyleIndexResult = -1;
}

Object^ StrategyStyleSelectingArgs::Item::get()
{
	return m_item;
}

DependencyObject^ StrategyStyleSelectingArgs::Container::get()
{
	return m_container;
}

StrategyStyleSelector::StrategyStyleSelector()
{
	Styles = ref new Vector<Style^>();
}

Style^ StrategyStyleSelector::SelectStyleCore(Object^ item, DependencyObject^ container)
{
	auto args = ref new StrategyStyleSelectingArgs(item, container);
	Selecting(this, args);
	
	if (args->StyleIndexResult >= 0 && args->StyleIndexResult < (int)Styles->Size)
	{
		return Styles->GetAt(args->StyleIndexResult);
	}
	else
	{
		return nullptr;
	}
}