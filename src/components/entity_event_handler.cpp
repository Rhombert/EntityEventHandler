#include "entity_event_handler.h"

void EntityEventHandler::_process(double delta) {
    for (auto& interactable : m_interactables)
    {
        interactable->process(delta);
    }
}

