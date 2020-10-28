#include "MyGameEditor.h"

#include "Customization/MyStructCustomization.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "MyGame/MyStruct.h"
#include "PropertyEditor/Public/PropertyEditorModule.h"

IMPLEMENT_GAME_MODULE(FMyGameEditorModule, MyGameEditor);

#define LOCTEXT_NAMESPACE "MyGameEditor"

void FMyGameEditorModule::StartupModule()
{
	// import the PropertyEditor module...
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	// to register our custom property
	PropertyModule.RegisterCustomPropertyTypeLayout(
		// This is the name of the Struct (we can also use "MyStruct" instead)
		// this tells the property editor which is the struct property our customization will applied on.
		FMyStruct::StaticStruct()->GetFName(),
		// this is where our MakeInstance() method is usefull
		FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FMyStructCustomization::MakeInstance));

	PropertyModule.NotifyCustomizationModuleChanged();
}

void FMyGameEditorModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		// unregister properties when the module is shutdown
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.UnregisterCustomPropertyTypeLayout("MyStruct");

		PropertyModule.NotifyCustomizationModuleChanged();
	}
}

#undef LOCTEXT_NAMESPACE
