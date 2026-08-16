#include "interactables/armour.h"

using namespace Interactables;

void Armour::receive_effect(Effects::Effect *effect)
{
    effect->apply_effect(this);
}

double Armour::get_current_armour() const { 
    return get_current_value(); 
}
