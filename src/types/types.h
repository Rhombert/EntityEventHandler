#ifndef ENTITYEVENTHANDLER_TYPES_H
#define ENTITYEVENTHANDLER_TYPES_H

#include <bitset>

namespace Types {
    // The order of this enum also determines the order that
    //  stats are processed in.
    enum class Interactable {
        ARMOUR,
        HP,

        ATTACK_SPEED,

        MOVE_SPEED,
        TURN_SPEED,

        INTERACTABLE_TYPES_COUNT,
    };

    using InteractableBitset = std::bitset<
        (size_t)Interactable::INTERACTABLE_TYPES_COUNT>;
}

#endif//ENTITYEVENTHANDLER_TYPES_H
