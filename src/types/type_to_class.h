#ifndef ENTITYEVENTHANDLER_TYPE_TO_CLASS_H
#define ENTITYEVENTHANDLER_TYPE_TO_CLASS_H

#include "types/types.h"
#include "interactables/hp.h"
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
    struct InteractableType<Types::Interactable::TURN_SPEED> {
        using type = TurnSpeed;
    };

    template<Types::Interactable I>
    using InteractableTypeT = typename InteractableType<I>::type;
}

#endif//ENTITYEVENTHANDLER_TYPE_TO_CLASS_H
