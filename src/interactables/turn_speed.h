#ifndef ENTITYEVENTHANDLER_INTERACTABLE_TURNSPEED_H
#define ENTITYEVENTHANDLER_INTERACTABLE_TURNSPEED_H

#include "components/effect.h"
#include "types/types.h"
#include "components/interactable_state.h"

namespace Interactables {
    class TurnSpeed : public InteractableState {

    public:
        TurnSpeed(double value = DEFAULT_TURN_SPEED)
            : InteractableState { Types::Interactable::TURN_SPEED }
            , m_base_turn_speed { value }
            , m_current_turn_speed { value }
        { }

        void receive_effect(Effects::Effect *effect) override
        {
            effect -> apply_effect(this);
        }

        double get_turn_speed() const { return m_current_turn_speed; }
        double get_mod_value() const { return 1.0; }

        void apply_base_multiplier(double mul) override;
        void apply_additive_bonus(double add) override;
        void apply_total_multiplier(double mul) override;
 
    protected:

    private:
        constexpr static double DEFAULT_TURN_SPEED { 1.0 };
        double m_base_turn_speed { DEFAULT_TURN_SPEED };
        double m_current_turn_speed { DEFAULT_TURN_SPEED };
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLE_TURNSPEED_H
