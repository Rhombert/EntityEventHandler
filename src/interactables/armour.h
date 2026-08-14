#ifndef ENTITYEVENTHANDLER_INTERACTABLES_ARMOUR_H
#define ENTITYEVENTHANDLER_INTERACTABLES_ARMOUR_H

#include "components/effect.h"
#include "components/interactable_state.h"
#include "types/types.h"

namespace Interactables {
    class Armour : public InteractableState
    {
    public:
        Armour(double value = 0.0)
            : InteractableState { Types::Interactable::ARMOUR }
            , m_base_armour { value }
            , m_current_armour { value }
        { }

        void receive_effect(Effects::Effect *effect) override;

        double get_current_armour() const;
        double get_base_armour() const;

        void apply_base_multiplier(double mul) override;
        void apply_additive_bonus(double add) override;
        void apply_total_multiplier(double mul) override;

    protected:

    private:
        double m_base_armour {};
        double m_current_armour {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLES_ARMOUR_H
