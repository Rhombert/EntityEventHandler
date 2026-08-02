#ifndef ENTITYEVENTHANDLER_INTERACTABLE_STATE_H
#define ENTITYEVENTHANDLER_INTERACTABLE_STATE_H

#include <godot_cpp/classes/ref_counted.hpp>

namespace godot {
    class InteractableState : public RefCounted {
        GDCLASS(InteractableState, RefCounted)

    public:
        InteractableState();
        ~InteractableState();

        void process(double delta);

        double get_mod_value() const;

    protected:
        static void _bind_methods();

    private:
        double m_value {};
    };
}

#endif // ENTITYEVENTHANDLER_INTERACTABLE_STATE_H
