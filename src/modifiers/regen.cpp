#include "modifiers/regen.h"

using namespace godot;

Regen::Regen() {}
Regen::Regen(double heal_value, double tick_rate, int tick_num)
    : Modifier { tick_rate, tick_num }
    , m_heal_value { heal_value }
{ }
Regen::~Regen() {}

void Regen::apply_effect(Hp& state)
{
    state.heal(m_heal_value); 
}

void Regen::_bind_methods()
{
}
