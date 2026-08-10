#ifndef ENTITYEVENTHANDLER_INTERACTABLE_H
#define ENTITYEVENTHANDLER_INTERACTABLE_H

#include <vector>

#include "components/interactable_state.h"
#include "components/modifier.h"

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
        Interactable() = default;
        ~Interactable() = default;

        // Handle the lifecycle of interactables. This primarily exists to
        // facilitate `Modifier`s, which occur over time.
        void process(double delta);

        double get_mod_value() const { return m_state->get_mod_value(); };

        // void attach_modifier(Modifiers::Modifier modifier);

    protected:

    private:
        Interactables::InteractableState *m_state {};
        std::vector<Modifiers::Modifier*> m_modifiers {};
    };

}

#endif//ENTITYEVENTHANDLER_INTERACTABLE_H
