#include "interaction.h"

using namespace Interactions;

void Interaction::apply(
        Interactables::Interactable& interactable) const
{
    for (const auto& modifier : m_modifiers)
    {
        interactable.attach(*modifier);
    }
    for (const auto& effect : m_effects)
    {
        interactable.attach(*effect);
    }
}

void Interaction::_bind_methods() {

}
