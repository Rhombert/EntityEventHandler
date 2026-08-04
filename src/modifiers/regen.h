#ifndef ENTITYEVENTHANDLER_MODIFIER_REGEN_H
#define ENTITYEVENTHANDLER_MODIFIER_REGEN_H

#include "components/modifier.h"
#include "interactables/hp.h"

namespace godot {
    class Regen : public Modifier {
        GDCLASS(Regen, Modifier)

    public:
        Regen();
        Regen(double heal_value, double tick_rate, int tick_num);
        ~Regen();

        void apply_effect(Hp& state);

    protected:
        static void _bind_methods();

    private:
        double m_heal_value {};
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_REGEN_H
