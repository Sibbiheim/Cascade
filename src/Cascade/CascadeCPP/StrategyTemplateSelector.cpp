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
#include "StrategyTemplateSelector.h"
#include <collection.h>

using namespace Sibbiheim::Cascade;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::Foundation::Collections;

StrategyTemplateSelectingArgs::StrategyTemplateSelectingArgs(Object^ item, DependencyObject^ container) :
m_item(item),
m_container(container)
{
	TemplateIndexResult = -1;
}

Object^ StrategyTemplateSelectingArgs::Item::get()
{
	return m_item;
}

DependencyObject^ StrategyTemplateSelectingArgs::Container::get()
{
	return m_container;
}

StrategyTemplateSelector::StrategyTemplateSelector()
{
	Templates = ref new Vector<DataTemplate^>();
}

DataTemplate^ StrategyTemplateSelector::SelectTemplateCore(Object^ item, DependencyObject^ container)
{
	auto args = ref new StrategyTemplateSelectingArgs(item, container);
	Selecting(this, args);

	if (args->TemplateIndexResult >= 0 && args->TemplateIndexResult < (int)Templates->Size)
	{
		return Templates->GetAt(args->TemplateIndexResult);
	}
	else
	{
		return nullptr;
	}
}