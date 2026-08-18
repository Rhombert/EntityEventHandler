#include "interactables/armour.h"

using namespace Interactables;

Armour::Armour(double base_armour)
    : InteractableState { Types::Interactable::ARMOUR, base_armour }
{ }

void Armour::receive_effect(Effects::Effect *effect)
{
    effect->apply_effect(this);
}

void Armour::update() {};

double Armour::get_current_armour() const { 
    return get_current_value(); 
}
