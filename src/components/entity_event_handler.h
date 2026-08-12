#ifndef ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
#define ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H

#include <vector>
#include <memory>

#include "components/interactable.h"
#include "interactables/hp.h"
#include "interactables/turn_speed.h"
#include "types/types.h"

using namespace Interactables;

//TODO: MOVE THIS
template<Types::Interactable>
struct InteractableType;

template<>
struct InteractableType<Types::Interactable::HP> {
    using type = Hp;
};

template<>
struct InteractableType<Types::Interactable::TURN_SPEED> {
    using type = TurnSpeed;
};

template<Types::Interactable I>
using InteractableTypeT = typename InteractableType<I>::type;

class EntityEventHandler {
using InteractablePipeline = std::vector<std::vector<Interactable>>;

public:
    EntityEventHandler(double hp, double turn_speed)
    {
        m_interactables.resize(
                (unsigned long)(Types::Interactable::INTERACTABLE_TYPES_COUNT)
        );
        m_interactables[(size_t)Types::Interactable::HP] =
            std::make_unique<Interactable>(Hp { 100.0 });
        m_interactables[(size_t)Types::Interactable::TURN_SPEED] =
            std::make_unique<Interactable>(TurnSpeed { 1.0 });
    }

    void _process(double delta);

    template<Types::Interactable I>
    const InteractableTypeT<I>* get_interactable() const
    { 
        return static_cast<const Hp*>(
            m_interactables.at((size_t)I).get()->get_state()
        );
    }

protected:

private:
    InteractablePipeline m_interactable_pipeline {};

    std::vector<std::unique_ptr<Interactable>> m_interactables {};
};

#endif //ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
