#ifndef ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
#define ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H

#include <vector>
#include <memory>

#include "components/interactable.h"
#include "interactables/hp.h"
#include "interactables/turn_speed.h"

using namespace Interactables;

class EntityEventHandler {
using InteractablePipeline = std::vector<std::vector<Interactable>>;

public:
    EntityEventHandler(double hp, double turn_speed)
    {
        m_interactables.push_back(
            std::make_unique<Interactable>(Hp { 100.0 })
        );
        m_interactables.push_back(
            std::make_unique<Interactable>(TurnSpeed { 1.0 })
        );
    }

    void _process(double delta);

protected:

private:
    InteractablePipeline m_interactable_pipeline {};

    std::vector<std::unique_ptr<Interactable>> m_interactables {};
};

#endif //ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
