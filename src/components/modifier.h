#ifndef ENTITYEVENTHANDLER_MODIFIER_H
#define ENTITYEVENTHANDLER_MODIFIER_H

#include <godot_cpp/classes/ref_counted.hpp>

namespace godot {
    class Modifier : public RefCounted {
        GDCLASS(Modifier, RefCounted)

    public:
        Modifier();
        ~Modifier();

    protected:
        static void _bind_methods();

    private:
    };
}

#endif //ENTITYEVENTHANDLER_MODIFIER_H
