#include "binding/modifier_gd.h"
#include "binding/effect_gd.h"
#include "godot_cpp/core/class_db.hpp"

using namespace godot;

ModifierGd::ModifierGd()
    : m_modifier {
        nullptr,
        0.2, 1
    }
{}

ModifierGd::ModifierGd(Variant effect,
                       double tick_rate,
                       int tick_num,
                       bool instant_activation)
    : m_modifier { nullptr, tick_rate, tick_num, instant_activation }
{ }

Modifiers::Modifier& ModifierGd::get_modifier()
{
    return m_modifier;
}

void ModifierGd::set_effect(Variant effect)
{ 
    auto* object = effect.get_validated_object();
    auto c_effect = Object::cast_to<EffectGd>(object);
    m_modifier.set_effect(c_effect->get_effect_instance());
}

void ModifierGd::set_tick_rate(double tick_rate)
{
    m_modifier.set_tick_rate(tick_rate);
}

void ModifierGd::set_tick_num(int tick_num)
{
    m_modifier.set_num_ticks(tick_num);
}

void ModifierGd::set_is_instant(bool is_instant)
{
    m_modifier.set_is_instant(is_instant);
}

void ModifierGd::_bind_methods() { 
    ClassDB::bind_method(D_METHOD("set_effect", "effect"),
                         &ModifierGd::set_effect);
    ClassDB::bind_method(D_METHOD("set_tick_rate", "tick_rate"),
                         &ModifierGd::set_tick_rate);
    ClassDB::bind_method(D_METHOD("set_tick_num", "tick_num"),
                         &ModifierGd::set_tick_num);
    ClassDB::bind_method(D_METHOD("set_is_instant", "is_instant"),
                         &ModifierGd::set_is_instant);
}
