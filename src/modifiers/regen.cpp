#include "modifiers/regen.h"


void Regen::apply_effect(Hp& state)
{
    state.heal(m_heal_value);
}
