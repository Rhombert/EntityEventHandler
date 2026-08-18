#include "interaction.h"

using namespace Interactions;

void Interaction::add(Modifiers::Modifier&& modifier)
{
    m_modifiers.push_back(std::make_unique<Modifiers::Modifier>(modifier));
}

void Interaction::add(Modifiers::Modifier& modifier)
{
    m_modifiers.emplace_back(std::make_unique<Modifiers::Modifier>(modifier));
}

const Interaction::ModifierVector& Interaction::get_modifiers() const
{
    return m_modifiers;
}

void Interaction::_bind_methods() {

}
