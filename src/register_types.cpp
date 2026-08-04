#include "register_types.h"

#include "godot_cpp/core/class_db.hpp"

#include "components/modifier.h"
#include "components/interactable_state.h"
#include "components/interactable.h"
#include "components/interaction.h"
#include "components/entity_event_handler.h"

#include "interactables/hp.h"

#include "modifiers/regen.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;


void initialize_entity_event_handler_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_CLASS(Modifier);
	GDREGISTER_CLASS(Interaction);
    GDREGISTER_CLASS(InteractableState);
	GDREGISTER_CLASS(Interactable);
    GDREGISTER_CLASS(Hp);
    GDREGISTER_CLASS(Regen);

	GDREGISTER_CLASS(EntityEventHandler);
}

void uninitialize_entity_event_handler_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT entity_event_handler_lib_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_entity_event_handler_module);
	init_obj.register_terminator(uninitialize_entity_event_handler_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
