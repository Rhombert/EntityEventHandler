#ifndef ENTITYEVENTHANDLER_INTERACTION_H
#define ENTITYEVENTHANDLER_INTERACTION_H

#include <vector>

#include <godot_cpp/classes/ref_counted.hpp>

#include "./modifier.h"

namespace godot {
    class Interaction {

    public:
        Interaction();
        ~Interaction();

    protected:
        static void _bind_methods();

    private:
        // std::vector<Modifiers::Modifier> modifiers {};
    };
}

#endif //ENTITYEVENTHANDLER_INTERACTION_H
