#ifndef ENTITYEVENTHANDLER_INTERACTABLE_STATE_H
#define ENTITYEVENTHANDLER_INTERACTABLE_STATE_H

#include "components/modifier_effect.h"
#include "types/types.h"

namespace Interactables {
    class InteractableState {

    public:
        InteractableState();
        InteractableState(Types::Interactable type)
            : m_type { type }
        { };
        ~InteractableState();

        virtual void receive_effect(Modifiers::ModifierEffect *effect) = 0;
        double get_mod_value() const;

    protected:
        static void _bind_methods();

    private:
        Types::Interactable m_type;
    };
}

#endif // ENTITYEVENTHANDLER_INTERACTABLE_STATE_H
