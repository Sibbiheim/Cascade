/*
* The MIT License (MIT)
*
* Copyright (c) 2014 Sibbiheim, LLC.
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
#include "Lightbox.h"

using namespace Sibbiheim::Cascade;

using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

DependencyProperty^ Lightbox::_backgroundProperty = DependencyProperty::RegisterAttached(
	"Background", Brush::typeid, Lightbox::typeid, ref new PropertyMetadata(nullptr));

DependencyProperty^ Lightbox::_contentMarginProperty = DependencyProperty::RegisterAttached(
	"ContentMargin", Thickness::typeid, Lightbox::typeid, ref new PropertyMetadata(Thickness(0,0,0,0)));

DependencyProperty^ Lightbox::_contentMinWidthProperty = DependencyProperty::RegisterAttached(
	"ContentMinWidth", double::typeid, Lightbox::typeid, ref new PropertyMetadata(0.0));
DependencyProperty^ Lightbox::_contentMaxWidthProperty = DependencyProperty::RegisterAttached(
	"ContentMaxWidth", double::typeid, Lightbox::typeid, ref new PropertyMetadata(0.0));
DependencyProperty^ Lightbox::_contentMinHeightProperty = DependencyProperty::RegisterAttached(
	"ContentMinHeight", double::typeid, Lightbox::typeid, ref new PropertyMetadata(0.0));
DependencyProperty^ Lightbox::_contentMaxHeightProperty = DependencyProperty::RegisterAttached(
	"ContentMaxHeight", double::typeid, Lightbox::typeid, ref new PropertyMetadata(0.0));

DependencyProperty^ Lightbox::BackgroundProperty::get()
{
	return _backgroundProperty;
}

DependencyProperty^ Lightbox::ContentMarginProperty::get()
{
	return _contentMarginProperty;
}

DependencyProperty^ Lightbox::ContentMinWidthProperty::get()
{
	return _contentMinWidthProperty;
}

DependencyProperty^ Lightbox::ContentMaxWidthProperty::get()
{
	return _contentMaxWidthProperty;
}

DependencyProperty^ Lightbox::ContentMinHeightProperty::get()
{
	return _contentMinHeightProperty;
}

DependencyProperty^ Lightbox::ContentMaxHeightProperty::get()
{
	return _contentMaxHeightProperty;
}

Brush^ Lightbox::GetBackground(FlyoutPresenter^ element)
{
	return dynamic_cast<Brush^>(element->GetValue(_backgroundProperty));
}

void Lightbox::SetBackground(FlyoutPresenter^ element, Brush^ value)
{
	element->SetValue(_backgroundProperty, value);
}

Thickness Lightbox::GetContentMargin(FlyoutPresenter^ element)
{
	auto box = dynamic_cast<IBox<Thickness>^>(element->GetValue(_contentMarginProperty));
	return box != nullptr ? box->Value : Thickness(0, 0, 0, 0);
}

void Lightbox::SetContentMargin(FlyoutPresenter^ element, Thickness value)
{
	element->SetValue(_contentMarginProperty, value);
}

double Lightbox::GetContentMinWidth(FlyoutPresenter^ element)
{
	auto box = dynamic_cast<IBox<double>^>(element->GetValue(_contentMinWidthProperty));
	return box != nullptr ? box->Value : 0;
}

void Lightbox::SetContentMinWidth(FlyoutPresenter^ element, double value)
{
	element->SetValue(_contentMinWidthProperty, value);
}

double Lightbox::GetContentMaxWidth(FlyoutPresenter^ element)
{
	auto box = dynamic_cast<IBox<double>^>(element->GetValue(_contentMaxWidthProperty));
	return box != nullptr ? box->Value : 0;
}

void Lightbox::SetContentMaxWidth(FlyoutPresenter^ element, double value)
{
	element->SetValue(_contentMaxWidthProperty, value);
}

double Lightbox::GetContentMinHeight(FlyoutPresenter^ element)
{
	auto box = dynamic_cast<IBox<double>^>(element->GetValue(_contentMinHeightProperty));
	return box != nullptr ? box->Value : 0;
}

void Lightbox::SetContentMinHeight(FlyoutPresenter^ element, double value)
{
	element->SetValue(_contentMinHeightProperty, value);
}

double Lightbox::GetContentMaxHeight(FlyoutPresenter^ element)
{
	auto box = dynamic_cast<IBox<double>^>(element->GetValue(_contentMaxHeightProperty));
	return box != nullptr ? box->Value : 0;
}

void Lightbox::SetContentMaxHeight(FlyoutPresenter^ element, double value)
{
	element->SetValue(_contentMaxHeightProperty, value);
}