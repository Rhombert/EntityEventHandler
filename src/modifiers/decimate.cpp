#include "modifiers/decimate.h"

void Decimate::apply_effect(Hp& state)
{
    state.damage(m_damage_value);
}
