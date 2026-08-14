#include "interactables/armour.h"

using namespace Interactables;

void Armour::receive_effect(Effects::Effect *effect)
{
    effect->apply_effect(this);
}

double Armour::get_current_armour() const { return m_current_armour; }
double Armour::get_base_armour() const { return m_base_armour; }


void Armour::apply_base_multiplier(double mul) {};
void Armour::apply_additive_bonus(double add) {};
void Armour::apply_total_multiplier(double mul) {};
