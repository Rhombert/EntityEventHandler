#ifndef ENTITYEVENTHANDLER_INTERACTABLE_TURNSPEED_H
#define ENTITYEVENTHANDLER_INTERACTABLE_TURNSPEED_H

#include "components/effect.h"
#include "types/types.h"
#include "components/interactable_state.h"

namespace Interactables {
    class TurnSpeed : public InteractableState {

    public:
        TurnSpeed(double base_turn_speed = DEFAULT_TURN_SPEED)
            : InteractableState { 
                Types::Interactable::TURN_SPEED, base_turn_speed }
        { }

        void receive_effect(Effects::Effect *effect) override;

        double get_turn_speed() const;

    protected:

    private:
        constexpr static double DEFAULT_TURN_SPEED { 1.0 };
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLE_TURNSPEED_H
