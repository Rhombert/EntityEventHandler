#include "interactables/attack_speed.h"

using namespace Interactables;

void AttackSpeed::receive_effect(Effects::Effect *effect)
{ 
    effect->apply_effect(*this); 
}

double AttackSpeed::get_attack_speed() const 
    { return get_current_value(); }
