#include "components/interactable.h"

using namespace Interactables;

Types::Interactable Interactable::get_type() const 
{ 
    return m_state->get_type(); 
}

double Interactable::get_value() const 
{ 
    return m_state->get_current_value(); 
};

InteractableState* Interactable::get_state() 
{ 
    return m_state.get(); 
}
