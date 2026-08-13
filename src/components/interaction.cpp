#include "interaction.h"
#include <memory>

using namespace Interactions;

void Interaction::add(Effects::Effect& effect)
{
    m_effects.emplace_back(effect.clone());
}

void Interaction::add(Modifiers::Modifier& modifier)
{
    m_modifiers.emplace_back(std::make_unique<Modifiers::Modifier>(modifier));
}

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
