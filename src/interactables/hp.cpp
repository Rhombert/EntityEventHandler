#include <algorithm>

#include "interactables/hp.h"

#include "types/types.h"

using namespace Interactables;

Hp::Hp(double value)
    : InteractableState { Types::Interactable::HP, value }
    , m_current_health { value }
    , m_max_health { get_current_value_ref() }
{ }

void Hp::heal(double amount)
{
    m_current_health = std::min(m_current_health + amount, m_max_health);
}

void Hp::damage(double amount)
{
    m_current_health = std::max(m_current_health - amount, 0.0);
}

void Hp::receive_effect(Effects::Effect *effect)
{
    effect->apply_effect(this);
}

double Hp::get_health() const { return m_current_health; }
double Hp::get_max_health() const { return m_max_health; }

void Hp::update()
{
    double old_max_hp = m_max_health;
    InteractableState::update();
    double difference = m_max_health - old_max_hp;
    double shift = 0.0;
    if (old_max_hp != 0) shift = m_current_health / old_max_hp;
    m_current_health += difference * shift;
}

void Hp::set_value(double value)
{
    InteractableState::set_value(value);
    m_base_current_health = value;
    m_current_health = value;
}
