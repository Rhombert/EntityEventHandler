#include "effects/heal.h"

using namespace Interactables;
using namespace Effects;

void Heal::reset()
{

}

void Heal::apply_effect(Hp* state)
{
    state->heal(m_heal_value);
}

std::unique_ptr<Effect> Heal::clone() const
{
    return std::make_unique<Heal>(*this);
}
