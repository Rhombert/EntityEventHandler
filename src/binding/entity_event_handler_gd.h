#ifndef ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_GD_H
#define ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_GD_H

#include "godot_cpp/classes/ref_counted.hpp"

#include "components/entity_event_handler.h"

namespace godot {
    class EntityEventHandlerGd : public RefCounted {
        GDCLASS(EntityEventHandlerGd, RefCounted)
    public:
        EntityEventHandlerGd();
        EntityEventHandlerGd(
            double base_hp,
            double base_armour
        );

        static Ref<EntityEventHandlerGd> create(
            double base_hp,
            double base_armour
        );

        void _process(double delta);

        void receive_interaction(Variant interaction);

        void print_state();

    protected:
        static void _bind_methods();

    private:
        EntityEventHandler m_event_handler;
    };
}

#endif//ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_GD_H
