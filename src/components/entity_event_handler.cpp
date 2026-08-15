#include "entity_event_handler.h"

#include "interactables/armour.h"
#include "interactables/hp.h"
#include "interactables/attack_speed.h"
#include "interactables/move_speed.h"
#include "interactables/turn_speed.h"
#include "types/types.h"


EntityEventHandler::EntityEventHandler(double hp, double turn_speed)
{
    m_interactables.resize(
        (unsigned long)(Types::Interactable::INTERACTABLE_TYPES_COUNT)
    );
    m_interactables[(size_t)Types::Interactable::HP] =
        std::make_unique<Interactable>(Hp { });
    m_interactables[(size_t)Types::Interactable::ARMOUR] =
        std::make_unique<Interactable>(Armour { });
    m_interactables[(size_t)Types::Interactable::ATTACK_SPEED] =
        std::make_unique<Interactable>(AttackSpeed { });
    m_interactables[(size_t)Types::Interactable::MOVE_SPEED] =
        std::make_unique<Interactable>(MoveSpeed { });
    m_interactables[(size_t)Types::Interactable::TURN_SPEED] =
        std::make_unique<Interactable>(TurnSpeed { });
}

void EntityEventHandler::_process(double delta) {
    for (auto& interactable : m_interactables)
    {
        interactable->process(delta);
    }
}

void EntityEventHandler::recieve_interaction(
        Interactions::Interaction& interaction)
{
    for (auto& interactable : m_interactables) {
        if (!interactable) continue;
        interaction.apply(*interactable);
    }
}
