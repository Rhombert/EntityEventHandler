#include "effects/damage.h"
#include <memory>

using namespace Interactables;
using namespace Effects;

void Damage::apply_effect(InteractableState* state)
{
    apply_effect(static_cast<Hp*>(state));
}

void Damage::apply_effect(Hp* state)
{
    state->damage(m_damage_value);
}

std::unique_ptr<Effect> Damage::clone() const
{
    return std::make_unique<Damage>(*this);
}
