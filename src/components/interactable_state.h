#ifndef ENTITYEVENTHANDLER_INTERACTABLE_STATE_H
#define ENTITYEVENTHANDLER_INTERACTABLE_STATE_H

#include <godot_cpp/classes/ref_counted.hpp>

#include "types/types.h"

namespace godot {
    class InteractableState : public RefCounted {
        GDCLASS(InteractableState, RefCounted)

    public:
        InteractableState();
        InteractableState(Types::Interactable type)
            : m_type { type }
        { };
        ~InteractableState();

        static Ref<InteractableState> create() { return { }; }

        double get_mod_value() const;

    protected:
        static void _bind_methods();

    private:
        Types::Interactable m_type;
    };
}

#endif // ENTITYEVENTHANDLER_INTERACTABLE_STATE_H
