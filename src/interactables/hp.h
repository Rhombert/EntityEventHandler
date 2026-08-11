#ifndef ENTITYEVENTHANDLER_INTERACTABLE_HP_H
#define ENTITYEVENTHANDLER_INTERACTABLE_HP_H

#include "components/effect.h"
#include "types/types.h"
#include "components/interactable_state.h"

namespace Interactables {
    // Hp is bound to its maximum value and 0
    // 
    // This is a `flat` state, the value assigned
    // is the literal value.
    class Hp : public InteractableState {

    public:
        Hp(double value = 100.0)
            : InteractableState { Types::Interactable::HP }
            , m_current_health { value }
            , m_max_health { value }
        { }

        void heal(double amount);
        void damage(double amount);

        void receive_effect(Effects::Effect *effect) override
        {
            effect->apply_effect(*this);
        }

        double get_health() const { return m_current_health; }
        double get_max_health() const { return m_max_health; }

        void apply_base_multiplier(double mul) override;
        void apply_additive_bonus(double add) override;
        void apply_total_multiplier(double mul) override;

    protected:
        
    private:
        double m_current_health {};
        double m_max_health {};
    };
}
#endif//ENTITYEVENTHANDLER_INTERACTABLE_HP_H
