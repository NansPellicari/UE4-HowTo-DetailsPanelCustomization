#include "Customization/MyStructCustomization.h"

#include "IDetailChildrenBuilder.h"
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
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	// First we need to retrieve every Property handles
	const TSharedPtr<IPropertyHandle> AmountPropertyHandle =
		StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMyStruct, Amount));
	const TSharedPtr<IPropertyHandle> LhRangePropertyHandle =
		StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMyStruct, RangeMin));
	const TSharedPtr<IPropertyHandle> RhRangePropertyHandle =
		StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMyStruct, RangeMax));
	const TSharedPtr<IPropertyHandle> TypePropertyHandle = StructPropertyHandle->GetChildHandle(
		GET_MEMBER_NAME_CHECKED(FMyStruct, Type)
	);

	// and check them before using them
	check(
		AmountPropertyHandle.IsValid()
		&& LhRangePropertyHandle.IsValid()
		&& RhRangePropertyHandle.IsValid()
		&& TypePropertyHandle.IsValid()
	);

	// clang-format off
	StructBuilder.AddCustomRow(LOCTEXT("MyStructRow", "MyStruct"))
	[
		SNew(SBorder)
		.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
		.BorderBackgroundColor(FLinearColor(255.f, 152.f, 0))
		.Content()
		[
			SNew(SWrapBox)
			.UseAllottedWidth(true)
			+ SWrapBox::Slot()
			.Padding(5.f, 0.f)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					TypePropertyHandle->CreatePropertyNameWidget()
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					TypePropertyHandle->CreatePropertyValueWidget()
				]
			]
			+ SWrapBox::Slot()
			.Padding(5.f, 0.f)
			[
				SNew(SBox)
				.IsEnabled(MakeAttributeLambda([=] { return ChosenType == EValueType::AMOUNT; }))
				.MinDesiredWidth(70.f)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						AmountPropertyHandle->CreatePropertyNameWidget()
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						AmountPropertyHandle->CreatePropertyValueWidget()
					]
				]
			]
			+ SWrapBox::Slot()
			.Padding(5.f, 0.f)
			[
				SNew(SBox)
				.IsEnabled(MakeAttributeLambda([=] { return ChosenType == EValueType::RANGE; }))
				.MinDesiredWidth(70.f)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						LhRangePropertyHandle->CreatePropertyNameWidget()
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						LhRangePropertyHandle->CreatePropertyValueWidget()
					]
				]
			]
			+ SWrapBox::Slot()
			.Padding(5.f, 0.f)
			[
				SNew(SBox)
				.IsEnabled(MakeAttributeLambda([=] { return ChosenType == EValueType::RANGE; }))
				.MinDesiredWidth(70.f)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						RhRangePropertyHandle->CreatePropertyNameWidget()
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						RhRangePropertyHandle->CreatePropertyValueWidget()
					]
				]
			]
		]
	];
	// clang-format on
}

void FMyStructCustomization::OnTypeChanged(TSharedPtr<IPropertyHandle> TypePropertyHandle)
{
	if (TypePropertyHandle.IsValid() && TypePropertyHandle->IsValidHandle())
	{
		TypePropertyHandle->GetValueAsDisplayText(ChosenTypeText);
		uint8 ValueAsByte;
		TypePropertyHandle->GetValue(ValueAsByte);
		ChosenType = static_cast<EValueType>(ValueAsByte);
	}
}

#undef LOCTEXT_NAMESPACE
