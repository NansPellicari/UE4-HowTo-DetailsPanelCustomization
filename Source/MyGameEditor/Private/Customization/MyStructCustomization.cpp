
#include "Customization/MyStructCustomization.h"

TSharedRef<IPropertyTypeCustomization> FMyStructCustomization::MakeInstance()
{
	// Create the instance and returned a SharedRef
	return MakeShareable(new FMyStructCustomization());
}

void FMyStructCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle,
	class FDetailWidgetRow& HeaderRow,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), ANSI_TO_TCHAR(__FUNCTION__));
	// Should customize here soon
}

void FMyStructCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle,
	class IDetailChildrenBuilder& StructBuilder,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	// Should customize here soon
}
