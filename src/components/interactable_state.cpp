#include "interactable_state.h"

using namespace Interactables;

InteractableState::InteractableState() {}
InteractableState::~InteractableState() {}

double InteractableState::get_mod_value() const 
{
    return 1.0;
}

void InteractableState::_bind_methods() {}
