#include "effects/heal.h"
#include "components/interactable_state.h"

using namespace Interactables;
using namespace Effects;

void Heal::apply_effect(InteractableState& state)
{
    apply_effect(static_cast<Hp&>(state));
}

void Heal::apply_effect(Hp& state)
{
    state.heal(m_heal_value);
}
