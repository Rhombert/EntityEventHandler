#ifndef ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
#define ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H

#include <vector>

#include <godot_cpp/classes/node.hpp>

#include "components/interactable.h"

namespace godot {
    using InteractablePipeline = std::vector<std::vector<Interactable>>;

    class EntityEventHandler {

    public:
        EntityEventHandler();
        ~EntityEventHandler();

        void _process(double delta);

    protected:

    private:
        InteractablePipeline m_interactable_pipeline {};

        std::vector<Interactable> m_interactables {};

        void initializePipelines();
    };
}

#endif //ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
