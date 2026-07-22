#ifndef ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
#define ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H

#include <vector>

#include <godot_cpp/classes/node.hpp>

#include "interactables.h"

namespace godot {
    using InteractablePipeline = std::vector<std::vector<Interactable>>;

    class EntityEventHandler : public Node {
        GDCLASS(EntityEventHandler, Node);

    public:
        EntityEventHandler();
        ~EntityEventHandler();

        void _process(double delta) override;

    protected:
        static void _bind_methods();

    private:
        InteractablePipeline m_interactable_pipeline {};

        std::vector<Interactable> m_interactables {};

        void initializePipelines();
    };
}

#endif //ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
