#include "effects/damage.h"
#include <algorithm>
#include <iostream>
#include <memory>

using namespace Interactables;
using namespace Effects;

void Damage::reset()
{
    m_current_damage_value = m_base_damage_value;
}

void Damage::apply_effect(InteractableState* state)
{
    apply_effect(static_cast<Hp*>(state));
}

void Damage::apply_effect(Hp* state)
{
    state->damage(m_current_damage_value);
}

void Damage::apply_effect(Armour* state)
{
    m_current_damage_value = std::max(
            m_current_damage_value - state->get_current_armour(), 0.0);
}

std::unique_ptr<Effect> Damage::clone() const
{
    return std::make_unique<Damage>(*this);
}
