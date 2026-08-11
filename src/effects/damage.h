#ifndef ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H
#define ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H

#include "components/effect.h"
#include "interactables/hp.h"

namespace Effects {
    class Damage : public Effects::Effect
    {
    public:
        Damage(double damage_value)
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
