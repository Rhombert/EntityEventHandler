#ifndef ENTITYEVENTHANDLER_INTERACTABLE_H
#define ENTITYEVENTHANDLER_INTERACTABLE_H

#include <vector>

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>

#include "components/interactable_state.h"
#include "components/modifier.h"

namespace godot {
    /**
     * An Interactable representing a modifier to an Entity's behaviour.
     *
     * These can most easily be thought of as stats. An HP interactable
     * can be interacted with by damage, and modifies the Entity in that
     * it destroys it when it reaches 0.
     */
    class Interactable {

    public:
        Interactable();
        ~Interactable();

        // Handle the lifecycle of interactables. This primarily exists to
        // facilitate `Modifier`s, which occur over time.
        void process(double delta);

        double get_mod_value() const;

        void gd_attach_modifier(Variant modifier);
        void attach_modifier(Modifier modifier);

    protected:

    private:
        InteractableState *m_state {};
        std::vector<Modifier> m_modifiers {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLE_H
