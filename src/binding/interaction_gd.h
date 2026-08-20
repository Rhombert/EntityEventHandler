#ifndef ENTITYEVENTHANDLER_INTERACTION_GD_H
#define ENTITYEVENTHANDLER_INTERACTION_GD_H

#include "components/interaction.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"

namespace godot {
    class InteractionGd : public RefCounted
    {
        GDCLASS(InteractionGd, RefCounted)

        public:
            InteractionGd();

            Interactions::Interaction& get_interaction();

            void add(Variant modifier);

        protected:
            static void _bind_methods();

        private:
            Interactions::Interaction m_interaction {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTION_GD_H
