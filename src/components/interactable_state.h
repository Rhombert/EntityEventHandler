#ifndef ENTITYEVENTHANDLER_INTERACTABLE_STATE_H
#define ENTITYEVENTHANDLER_INTERACTABLE_STATE_H

#include "components/effect.h"
#include "types/types.h"

namespace Interactables {
    class InteractableState {

    public:
        InteractableState();
        InteractableState(Types::Interactable type)
            : m_type { type }
        { };
        ~InteractableState();

        Types::Interactable get_type() const { return m_type; }

        virtual void receive_effect(Effects::Effect *effect) = 0;
        double get_mod_value() const;

        // Multiplicative base bonus, gets applied in layer 0.
        //  This should generally be an additive bonus that is
        //  resolved to base*mul.
        virtual void apply_base_multiplier(double mul) = 0;
        // Additive bonus, gets applied in layer 0.
        virtual void apply_additive_bonus(double add) = 0;
        // Multiplicative bonus, gets applied in layer 1.
        //  This should be resolved, with the end result of
        //  layer 0 being l0, as l0*mul.
        //TODO: 
        // Currently deciding whether or not these should
        //  apply one after another, such that multiple
        //  total multiplier bonuses compound off eachother,
        //  of if they should be calculated independently
        //  and added together.
        virtual void apply_total_multiplier(double mul) = 0;

    protected:
        static void _bind_methods();

    private:
        Types::Interactable m_type;
    };
}

#endif // ENTITYEVENTHANDLER_INTERACTABLE_STATE_H
