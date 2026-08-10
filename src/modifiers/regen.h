#ifndef ENTITYEVENTHANDLER_MODIFIER_REGEN_H
#define ENTITYEVENTHANDLER_MODIFIER_REGEN_H

#include "components/modifier_effect.h"
#include "interactables/hp.h"

namespace Modifiers {
    class Regen : public ModifierEffect 
    {

    public:
        Regen(double heal_value)
            : m_heal_value { heal_value }
        { }

        void apply_effect(Interactables::Hp& state) override;

    protected:

    private:
        double m_heal_value {};
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_REGEN_H
