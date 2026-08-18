#include "effects/damage.h"
#include "types/types.h"
#include <algorithm>
#include <memory>
#include <iostream>

using namespace Interactables;
using namespace Effects;

void Damage::reset()
{
    m_current_damage_value = m_base_damage_value;
}

void Damage::apply_effect(InteractableState* state)
{
    switch (state->get_type()) {
    case Types::Interactable::HP:
        apply_effect(static_cast<Hp*>(state));
        break;
    case Types::Interactable::ARMOUR:
        apply_effect(static_cast<Armour*>(state));
        break;
    default:
        break;
    }
}

void Damage::apply_effect(Hp* state)
{
    state->damage(m_current_damage_value);
}

void Damage::apply_effect(Armour* state)
{
    m_current_damage_value = std::max(
            m_current_damage_value - state->get_current_armour(), 
            0.0);
}

std::unique_ptr<Effect> Damage::clone() const
{
    return std::make_unique<Damage>(*this);
}
