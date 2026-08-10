#include "modifiers/regen.h"

using namespace Interactables;
using namespace Modifiers;

void Regen::apply_effect(Hp& state)
{
    state.heal(m_heal_value);
}
