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

Ref<DamageGd> DamageGd::create(double damage_value)
{
    return Ref<DamageGd> { memnew(
                DamageGd { damage_value }
            ) };
}

Effects::Damage DamageGd::get_damage_instance()
{
    return m_damage_instance;
}

void DamageGd::_bind_methods() {
    ClassDB::bind_static_method("DamageGd",
                                D_METHOD("create", "damage_value"),
                                &DamageGd::create);
}
