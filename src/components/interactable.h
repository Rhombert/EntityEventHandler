#ifndef ENTITYEVENTHANDLER_INTERACTABLE_H
#define ENTITYEVENTHANDLER_INTERACTABLE_H

#include <memory>

#include "components/interactable_state.h"

namespace Interactables {
    /**
     * An Interactable representing a modifier to an Entity's behaviour.
     *
     * These can most easily be thought of as stats. An HP interactable
     * can be interacted with by damage, and modifies the Entity in that
     * it destroys it when it reaches 0.
     */
    class Interactable {
    public:
        template<typename S>
        Interactable(S state)
            : m_state { std::make_unique<S>( state ) }
        { }

        Types::Interactable get_type() const;
        double get_value() const;

        InteractableState* get_state();

    protected:

    private:
        std::unique_ptr<Interactables::InteractableState> m_state {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLE_H
