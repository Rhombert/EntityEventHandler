#ifndef ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H
#define ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H

#include "components/effect.h"
#include "interactables/hp.h"
#include "interactables/armour.h"
#include "types/types.h"
#include <memory>

namespace Effects {
    class Damage : public Effect
    {
    public:
        Damage(double damage_value)
            : Effect { 
                Types::Interactable::HP,
                Types::Interactable::ARMOUR,
            }
            , m_base_damage_value { damage_value }
            , m_current_damage_value { damage_value }
        { }
        Damage(const Damage& damage)
            : Effect { 
                Types::Interactable::HP,
                Types::Interactable::ARMOUR,
            }
            , m_base_damage_value { damage.m_base_damage_value }
            , m_current_damage_value { damage.m_current_damage_value }
        { }

        ~Damage() = default;

        void reset() override;

        void apply_effect(Interactables::InteractableState* state) override;
        void apply_effect(Interactables::Hp* state) override;
        void apply_effect(Interactables::Armour* state) override;

        std::unique_ptr<Effect> clone() const override;
            
    protected:

    private:
        double m_base_damage_value {};
        double m_current_damage_value {};
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H
