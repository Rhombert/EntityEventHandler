#ifndef ENTITYEVENHANDLER_MODIFIER_DAMAGE_GD_H
#define ENTITYEVENHANDLER_MODIFIER_DAMAGE_GD_H

#include "binding/effect_gd.h"
#include "effects/damage.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {
    class DamageGd : public EffectGd
    {
        GDCLASS(DamageGd, EffectGd)

    public:
        DamageGd();
        DamageGd(double damage_value);

        Effects::Damage get_damage_instance();

    protected:
        static void _bind_methods();

    private:
        Effects::Damage m_damage_instance;
    };
}

#endif//ENTITYEVENHANDLER_MODIFIER_DAMAGE_GD_H
