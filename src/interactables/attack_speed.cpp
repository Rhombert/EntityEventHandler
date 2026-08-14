#include "interactables/attack_speed.h"

using namespace Interactables;

void AttackSpeed::reset() { m_current_attack_speed = m_base_attack_speed; }

void AttackSpeed::receive_effect(Effects::Effect *effect)
    { effect->apply_effect(*this); }

double AttackSpeed::get_attack_speed() const 
    { return m_current_attack_speed; }
double AttackSpeed::get_base_attack_speed() const 
    { return m_base_attack_speed; }


void AttackSpeed::apply_base_multiplier(double mul) { }
void AttackSpeed::apply_additive_bonus(double mul) { }
void AttackSpeed::apply_total_multiplier(double mul) { }
