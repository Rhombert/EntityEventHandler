#ifndef ENTITYEVENTHANDLER_TYPE_TO_CLASS_H
#define ENTITYEVENTHANDLER_TYPE_TO_CLASS_H

#include "types/types.h"
#include "interactables/hp.h"
#include "interactables/armour.h"
#include "interactables/attack_speed.h"
#include "interactables/move_speed.h"
#include "interactables/turn_speed.h"

namespace Types {
    using namespace Interactables;

    template<Types::Interactable>
    struct InteractableType;

    template<>
    struct InteractableType<Types::Interactable::HP> {
        using type = Hp;
    };

    template<>
    struct InteractableType<Types::Interactable::ARMOUR> {
        using type = Armour;
    };

    template<>
    struct InteractableType<Types::Interactable::ATTACK_SPEED> {
        using type = AttackSpeed;
    };

    template<>
    struct InteractableType<Types::Interactable::MOVE_SPEED> {
        using type = MoveSpeed;
    };

    template<>
    struct InteractableType<Types::Interactable::TURN_SPEED> {
        using type = TurnSpeed;
    };

    template<Types::Interactable I>
    using InteractableTypeT = typename InteractableType<I>::type;
}

#endif//ENTITYEVENTHANDLER_TYPE_TO_CLASS_H
