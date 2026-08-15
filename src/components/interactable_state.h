#ifndef ENTITYEVENTHANDLER_INTERACTABLE_STATE_H
#define ENTITYEVENTHANDLER_INTERACTABLE_STATE_H

#include "components/effect.h"
#include "types/types.h"

namespace Interactables {
    class InteractableState {

    public:
        InteractableState();
        InteractableState(Types::Interactable type);
        InteractableState(Types::Interactable type, double base_value);
        ~InteractableState();

        Types::Interactable get_type() const { return m_type; }

        virtual void receive_effect(Effects::Effect *effect) = 0;

        virtual void update();
        double get_current_value();

        virtual void apply_base_multiplier(double mul);
        virtual void apply_additive_bonus(double add);
        virtual void apply_total_multiplier(double mul);

    protected:
        double& get_base_value_ref();
        double& get_current_value_ref();
        double& get_base_multiplier_ref();
        double& get_flat_bonus_ref();
        double& get_total_multiplier_ref();

        static void _bind_methods();

    private:
        Types::Interactable m_type;

        double m_base_value {};
        double m_current_value {};

        double m_base_multiplier { 1.0 };
        double m_flat_bonus { 0.0 };
        double m_total_multiplier { 1.0 };
    };
}

#endif // ENTITYEVENTHANDLER_INTERACTABLE_STATE_H
