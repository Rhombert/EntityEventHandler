#ifndef ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H
#define ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H

#include "components/interactable.h"
#include "components/modifier_effect.h"
#include "interactables/hp.h"

namespace Modifiers {
    class Decimate : public ModifierEffect
    {
    public:
        Decimate(double damage_value)
            : m_damage_value { damage_value }
        { }

        void apply_effect(Interactables::InteractableState& state) override;
        void apply_effect(Interactables::Hp& state) override;
            
    protected:

    private:
        double m_damage_value {};
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H
