#ifndef ENTITYEVENTHANDLER_INTERACTABLE_ATTACK_SPEED_H
#define ENTITYEVENTHANDLER_INTERACTABLE_ATTACK_SPEED_H

#include "components/effect.h"
#include "types/types.h"
#include "components/interactable_state.h"

namespace Interactables {
    class AttackSpeed : public InteractableState {
    public:
        AttackSpeed(double base_attack_speed = 1.0)
            : InteractableState { Types::Interactable::ATTACK_SPEED }
            , m_base_attack_speed { base_attack_speed }
            , m_current_attack_speed { base_attack_speed }
        { }

        void reset();

        void receive_effect(Effects::Effect *effect) override;

        double get_attack_speed() const;
        double get_base_attack_speed() const;

        void apply_base_multiplier(double mul) override;
        void apply_additive_bonus(double mul) override;
        void apply_total_multiplier(double mul) override;

    protected:
        

    private:
        // The delay in seconds between each attack.
        // A value of 0.5 means two attacks a second.
        double m_base_attack_speed {};
        double m_current_attack_speed {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLE_ATTACK_SPEED_H
