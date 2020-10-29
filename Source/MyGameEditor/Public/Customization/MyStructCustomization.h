#pragma once

#include "PropertyEditor/Public/IPropertyTypeCustomization.h"
#include "MyGame/MyStruct.h"

class FMyStructCustomization : public IPropertyTypeCustomization
{
public:
	/**
	 * It is just a convenient helpers which will be used
	 * to register our customization. When the propertyEditor module
	 * find our FMyStruct property, it will use this static method
	 * to instanciate our customization object.
	 */
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	// BEGIN IPropertyTypeCustomization interface
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle,
		class FDetailWidgetRow& HeaderRow,
		IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle,
		class IDetailChildrenBuilder& StructBuilder,
		IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	// END IPropertyTypeCustomization interface

protected:
	FText ChosenTypeText;
	EValueType ChosenType;

	/**
	 * This method is bind to the SetOnPropertyValueChanged on the "Type" property.
	 * It retrieves the Type's value and store it to the "ChosenTypeText" property here.
	 */
	void OnTypeChanged(TSharedPtr<IPropertyHandle> TypePropertyHandle);
};
