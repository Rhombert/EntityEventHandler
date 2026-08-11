#ifndef ENTITYEVENTHANDLER_INTERACTION_H
#define ENTITYEVENTHANDLER_INTERACTION_H

#include <memory>
#include <vector>

#include "components/modifier.h"

namespace godot {
    class Interaction {

    public:
        Interaction();
        ~Interaction();

    protected:
        static void _bind_methods();

    private:
        std::vector<std::unique_ptr<Effects::Effect>> effects {};
        std::vector<Modifiers::Modifier> modifiers {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTION_H
