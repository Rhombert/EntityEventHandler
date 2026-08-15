#include "interactable_state.h"

using namespace Interactables;

InteractableState::InteractableState() {}

InteractableState::InteractableState(Types::Interactable type)
    : m_type { type }
{ }

InteractableState::InteractableState(
        Types::Interactable type, double base_value)
    : m_type { type }
    , m_base_value { base_value }
    , m_current_value { base_value }
{ }

InteractableState::~InteractableState() {}

void InteractableState::update()
{
    m_current_value = (m_base_value * m_base_multiplier + m_flat_bonus)
                      * m_total_multiplier;
}

double InteractableState::get_current_value()
{
    return m_current_value;
}

void InteractableState::apply_base_multiplier(double mul)
{
    m_base_multiplier += mul;
}

void InteractableState::apply_additive_bonus(double add)
{
    m_flat_bonus += add;
}

void InteractableState::apply_total_multiplier(double mul)
{
    m_total_multiplier += mul;
}

double& InteractableState::get_base_value_ref() 
{ return m_base_value; }
double& InteractableState::get_current_value_ref() 
{ return m_current_value; }
double& InteractableState::get_base_multiplier_ref()
{ return m_base_multiplier; }
double& InteractableState::get_flat_bonus_ref() 
{ return m_flat_bonus; }
double& InteractableState::get_total_multiplier_ref() 
{ return m_total_multiplier; }

void InteractableState::_bind_methods() {}
