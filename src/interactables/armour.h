#ifndef ENTITYEVENTHANDLER_INTERACTABLES_ARMOUR_H
#define ENTITYEVENTHANDLER_INTERACTABLES_ARMOUR_H

#include "components/effect.h"
#include "components/interactable_state.h"
#include "types/types.h"

namespace Interactables {
    class Armour : public InteractableState
    {
    public:
        Armour(double base_armour = DEFAULT_ARMOUR)
            : InteractableState { Types::Interactable::ARMOUR, base_armour }
        { }

        void receive_effect(Effects::Effect *effect) override;

        double get_current_armour() const;

    protected:

    private:
        constexpr static double DEFAULT_ARMOUR { 0.0 };
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLES_ARMOUR_H
