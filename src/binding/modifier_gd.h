#ifndef ENTITYEVENTHANDLER_MODIFIERGD_H
#define ENTITYEVENTHANDLER_MODIFIERGD_H

#include "components/modifier.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {
    class ModifierGd : public RefCounted
    {
        GDCLASS(ModifierGd, RefCounted)

    public:
        ModifierGd();
        ModifierGd(Variant effect,
                   double tick_rate,
                   int tick_num,
                   bool instant_activation = true);

        Modifiers::Modifier& get_modifier();

        void set_effect(Variant effect);
        void set_tick_rate(double);
        void set_tick_num(int);
        void set_is_instant(bool);

    protected:
        static void _bind_methods();

    private:
        Modifiers::Modifier m_modifier;
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIERGD_H
