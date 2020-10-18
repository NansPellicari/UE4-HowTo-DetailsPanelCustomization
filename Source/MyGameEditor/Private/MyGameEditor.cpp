#include "MyGameEditor.h"

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_GAME_MODULE(FMyGameEditorModule, MyGameEditor);

#define LOCTEXT_NAMESPACE "MyGameEditor"

void FMyGameEditorModule::StartupModule() {}

void FMyGameEditorModule::ShutdownModule() {}

#undef LOCTEXT_NAMESPACE
