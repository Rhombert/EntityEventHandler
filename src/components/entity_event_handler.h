#ifndef ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
#define ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H

#include <vector>
#include <memory>

#include "components/interactable.h"
#include "components/interaction.h"

#include "interactables/hp.h"
#include "interactables/attack_speed.h"
#include "interactables/turn_speed.h"

#include "types/types.h"
#include "types/type_to_class.h"

using namespace Interactables;

class EntityEventHandler {
public:
    EntityEventHandler(double hp, double turn_speed)
    {
        m_interactables.resize(
            (unsigned long)(Types::Interactable::INTERACTABLE_TYPES_COUNT)
        );
        m_interactables[(size_t)Types::Interactable::HP] =
            std::make_unique<Interactable>(Hp { 100.0 });
        m_interactables[(size_t)Types::Interactable::ATTACK_SPEED] =
            std::make_unique<Interactable>(AttackSpeed { 1.0 });
        m_interactables[(size_t)Types::Interactable::TURN_SPEED] =
            std::make_unique<Interactable>(TurnSpeed { 1.0 });
    }

    void _process(double delta);

    void recieve_interaction(Interactions::Interaction& interaction)
    {
        for (auto& interactable : m_interactables) {
            if (!interactable) continue;
            interaction.apply(*interactable);
        }
    }

    template<Types::Interactable I>
    const Types::InteractableTypeT<I>* get_interactable() const
    { 
        return static_cast<const Types::InteractableTypeT<I>*>(
            m_interactables.at((size_t)I).get()->get_state()
        );
    }

protected:

private:
    std::vector<std::unique_ptr<Interactable>> m_interactables {};
};

#endif //ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
