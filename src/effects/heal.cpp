#include "effects/heal.h"

using namespace Interactables;
using namespace Effects;

void Heal::reset()
{
    m_current_heal_value = m_base_heal_value;
}

void Heal::apply_effect(Hp* state)
{
    state->heal(m_current_heal_value);
}

std::unique_ptr<Effect> Heal::clone() const
{
    return std::make_unique<Heal>(*this);
}
