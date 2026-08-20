#include "binding/effect_gd.h"

using namespace godot;

EffectGd::EffectGd() 
    : m_effect_instance { nullptr }
{};

Effects::Effect* EffectGd::get_effect_instance()
{
    return m_effect_instance;
}

void EffectGd::_bind_methods()
{
}
