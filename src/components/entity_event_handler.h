#ifndef ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
#define ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H

#include <vector>

#include "components/interactable.h"

using namespace Interactables;

class EntityEventHandler {
using InteractablePipeline = std::vector<std::vector<Interactable>>;

public:
    EntityEventHandler();
    ~EntityEventHandler();

    void _process(double delta);

    void add_interactable(Interactable& interactable);

protected:

private:
    InteractablePipeline m_interactable_pipeline {};

    std::vector<Interactable> m_interactables {};

    void initializePipelines();
};

#endif //ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
