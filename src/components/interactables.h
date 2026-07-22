#ifndef ENTITYEVENTHANDLER_INTERACTABLES_H
#define ENTITYEVENTHANDLER_INTERACTABLES_H

#include <godot_cpp/classes/ref_counted.hpp>

namespace godot {
    /**
     * An Interactable representing a modifier to an Entity's behaviour.
     *
     * These can most easily be thought of as stats. An HP interactable
     * can be interacted with by damage, and modifies the Entity in that
     * it destroys it when it reaches 0.
     */
    class Interactable : public RefCounted{
        GDCLASS(Interactable, RefCounted);

    public:
        Interactable();
        ~Interactable();

        double getModValue() const;

    protected:
        static void _bind_methods();

    private:
    };
}

#endif //ENTITYEVENTHANDLER_INTERACTABLES_H
