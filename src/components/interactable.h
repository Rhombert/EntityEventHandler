#ifndef ENTITYEVENTHANDLER_INTERACTABLE_H
#define ENTITYEVENTHANDLER_INTERACTABLE_H

#include <memory>
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
        template<typename S>
        Interactable(S state)
            : m_state { std::make_unique<S>( state ) }
        { }

        // Handle the lifecycle of interactables. This primarily exists to
        // facilitate `Modifier`s, which occur over time.
        void process(double delta);

        Types::Interactable get_type() const;
        double get_value() const;

        const InteractableState* get_state();

        void attach(const Modifiers::Modifier& modifier);
        void attach(const Modifiers::Modifier* modifier);
        void attach(const Effects::Effect& effect);
        void attach(const Effects::Effect* effect);

    protected:

    private:
        std::unique_ptr<Interactables::InteractableState> m_state {};
        std::vector<std::unique_ptr<Modifiers::Modifier>> m_modifiers {};
        std::vector<std::unique_ptr<Effects::Effect>> m_effect_queue {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLE_H
