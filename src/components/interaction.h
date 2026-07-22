#ifndef ENTITYEVENTHANDLER_INTERACTION_H
#define ENTITYEVENTHANDLER_INTERACTION_H

#include <godot_cpp/classes/ref_counted.hpp>

namespace godot {
    class Interaction : public RefCounted {
        GDCLASS(Interaction, RefCounted)

    public:
        Interaction();
        ~Interaction();

    protected:
        static void _bind_methods();

    private:
    };
}

#endif //ENTITYEVENTHANDLER_INTERACTION_H
