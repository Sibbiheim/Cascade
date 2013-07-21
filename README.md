#Cascade

Cascade is a library targeting Windows 8.1 'Metro' that aims to provide tools that reduce the amount of code and codebehind necessary to implement features in XAML.

##Features
The `FlyoutService` class provides attached properties that extend the new Flyout and Button.Flyout features of Windows 8.1 and allow developers to create more complex Flyout behavior without requiring trivial event handlers in the codebehind. It exposes the following attached properties.

###`Flyout`
The FlyoutService.Flyout attached property enables Flyouts to be attached to any FrameworkElement, and automatically handles that FrameworkElement's Tapped event to show the Flyout. This can be used, for example, to add a flyout to a TextBlock as well as to add a secondary flyout to a MenuFlyoutItem. It uses the `FlyoutContext` attached property to ensure that every cascading Flyout control appears on the screen correctly relative to the original control.

###`SupportNestedFlyouts`
The FlyoutService.SupportNestedFlyout attached property provides support for secondary flyouts when using the built-in Button.Flyout property. It provides a way for the `FlyoutService` to correctly propagate the `FlyoutContext` to the cascading Flyouts. Alternatively using FlyoutService.Flyout instead of Button.Flyout on Buttons does not require using this attached property.

###Internal properties
####`FlyoutContext`
The FlyoutService.FlyoutContext attached property is used internally to correctly position cascading Flyouts. The getter and setter are made public to provide a way for custom Flyout implementations to programmaticaly show subsequent flyouts. It is not supported to set this value in XAML.

##How to use
Developers have the option of including CascadeCS as a reference to their Windows 8.1 XAML app project, or including the code files directly in their own project. Equally functional C# and C++ versions of the library are provided.

##Questions, Suggestions, Issues
Please [file a bug](https://github.com/Sibbiheim/Cascade/issues/new), or [contact us](mailto:github@sibbiheim.com)
