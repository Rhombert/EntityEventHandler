#ifndef ENTITYEVENTHANDLER_TYPES_H
#define ENTITYEVENTHANDLER_TYPES_H

#include <bitset>

namespace Types {
    enum class Interactable {
        HP,
        ARMOUR,
        ATTACK_SPEED,
        MOVE_SPEED,
        TURN_SPEED,
        INTERACTABLE_TYPES_COUNT,
    };

    using InteractableBitset = std::bitset<
        (size_t)Interactable::INTERACTABLE_TYPES_COUNT>;
}

#endif//ENTITYEVENTHANDLER_TYPES_H
