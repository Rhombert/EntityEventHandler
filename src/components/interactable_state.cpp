#include "interactable_state.h"

using namespace godot;

double InteractableState::get_mod_value() const
{
    return m_value;
}

void InteractableState::_bind_methods() {}

InteractableState::InteractableState() {}

InteractableState::~InteractableState() {}
