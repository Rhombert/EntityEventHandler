#include "modifiers/decimate.h"
#include "components/interactable.h"

using namespace Interactables;
using namespace Modifiers;

void Decimate::apply_effect(Interactables::InteractableState& state)
{
    apply_effect(static_cast<Hp&>(state));
}

void Decimate::apply_effect(Hp& state)
{
    state.damage(m_damage_value);
}
