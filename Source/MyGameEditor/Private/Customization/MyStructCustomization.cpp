#include "Customization/MyStructCustomization.h"

#include "SlateBasics.h"
#include "MyGame/MyStruct.h"
#include "PropertyEditor/Public/DetailLayoutBuilder.h"
#include "PropertyEditor/Public/DetailWidgetRow.h"
#include "PropertyEditor/Public/PropertyHandle.h"

#define LOCTEXT_NAMESPACE "MyGameEditor"

TSharedRef<IPropertyTypeCustomization> FMyStructCustomization::MakeInstance()
{
	// Create the instance and returned a SharedRef
	return MakeShareable(new FMyStructCustomization());
}

void FMyStructCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle,
	class FDetailWidgetRow& HeaderRow,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	// Get the property handler of the type property:
	TSharedPtr<IPropertyHandle> TypePropertyHandle = StructPropertyHandle->GetChildHandle(
		GET_MEMBER_NAME_CHECKED(FMyStruct, Type)
	);
	check(TypePropertyHandle.IsValid());

	// retrieve its value as a text to display
	OnTypeChanged(TypePropertyHandle);

	// attached an event when the property value changed
	TypePropertyHandle->SetOnPropertyValueChanged(
		FSimpleDelegate::CreateSP(this, &FMyStructCustomization::OnTypeChanged, TypePropertyHandle)
	);

	// then change the HeaderRow to add some Slate widget
	// @formatter:off
	// clang-format off
	HeaderRow.NameContent()[StructPropertyHandle->CreatePropertyNameWidget()]
	.ValueContent()[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(STextBlock)
			.Font(FEditorStyle::GetFontStyle("PropertyWindow.NormalFont"))
			.Text(MakeAttributeLambda([=] { return FText::Format(LOCTEXT("ValueType", "The value type is \"{0}\""), ChosenTypeText); }))
		]
	];
	// clang-format on
	// @formatter:on
}

void FMyStructCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle,
	class IDetailChildrenBuilder& StructBuilder,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils) {}

void FMyStructCustomization::OnTypeChanged(TSharedPtr<IPropertyHandle> TypePropertyHandle)
{
	if (TypePropertyHandle.IsValid() && TypePropertyHandle->IsValidHandle())
	{
		TypePropertyHandle->GetValueAsDisplayText(ChosenTypeText);
	}
}

#undef LOCTEXT_NAMESPACE
