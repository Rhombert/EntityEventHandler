#ifndef ENTITYEVENTHANDLER_INTERACTABLE_ATTACK_SPEED_H
#define ENTITYEVENTHANDLER_INTERACTABLE_ATTACK_SPEED_H

#include "components/effect.h"
#include "types/types.h"
#include "components/interactable_state.h"

namespace Interactables {
    class AttackSpeed : public InteractableState {
    public:
        AttackSpeed(double base_attack_speed = DEFAULT_ATTACK_SPEED)
            : InteractableState { 
                Types::Interactable::ATTACK_SPEED, base_attack_speed }
        { }

        ~AttackSpeed() {}

        void receive_effect(Effects::Effect *effect) override;

        double get_attack_speed() const;

    protected:

    private:
        constexpr static double DEFAULT_ATTACK_SPEED { 1.0 };
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLE_ATTACK_SPEED_H
