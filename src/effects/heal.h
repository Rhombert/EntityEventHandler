#ifndef ENTITYEVENTHANDLER_MODIFIER_REGEN_H
#define ENTITYEVENTHANDLER_MODIFIER_REGEN_H

#include "components/effect.h"
#include "interactables/hp.h"

namespace Effects {
    class Heal : public Effect
    {

    public:
        Heal(double heal_value)
            : m_heal_value { heal_value }
        { }

        void apply_effect(Interactables::InteractableState& state) override;
        void apply_effect(Interactables::Hp& state) override;

    protected:

    private:
        double m_heal_value {};
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_REGEN_H
