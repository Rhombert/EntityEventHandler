#include "binding/damage_gd.h"

using namespace godot;

DamageGd::DamageGd()
    : m_damage_instance {}
{ 
    m_effect_instance = &m_damage_instance;
}

DamageGd::DamageGd(double damage_value)
    : m_damage_instance { damage_value }
{
    m_effect_instance = &m_damage_instance;
}

Effects::Damage DamageGd::get_damage_instance()
{
    return m_damage_instance;
}

void DamageGd::_bind_methods() {}
