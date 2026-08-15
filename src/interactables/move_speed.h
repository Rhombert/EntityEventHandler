#ifndef ENTITYEVENTHANDLER_INTERACTABLE_MOVE_SPEED_H
#define ENTITYEVENTHANDLER_INTERACTABLE_MOVE_SPEED_H

#include "components/effect.h"
#include "components/interactable_state.h"

namespace Interactables {
    class MoveSpeed: public InteractableState {

    public:
        MoveSpeed(double value = DEFAULT_MOVE_SPEED);

        void receive_effect(Effects::Effect *effect) override;

        double get_move_speed() const;
 
    protected:

    private:
        constexpr static double DEFAULT_MOVE_SPEED { 1.0 };
        double m_base_move_speed { DEFAULT_MOVE_SPEED };
        double m_current_move_speed { DEFAULT_MOVE_SPEED };
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLE_MOVESPEED_H
