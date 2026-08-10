#ifndef ENTITYEVENTHANDLER_MODIFIER_EFFECT_H
#define ENTITYEVENTHANDLER_MODIFIER_EFFECT_H

#include <iostream>

namespace Interactables {
    class InteractableState;
    class Hp;
    class AttackSpeed;
}

namespace Modifiers {
    class ModifierEffect 
    {
    public:
        virtual ~ModifierEffect() = default;

        virtual void apply_effect(Interactables::InteractableState& state) {}
        virtual void apply_effect(Interactables::Hp& state) {}
        virtual void apply_effect(Interactables::AttackSpeed& state) {}

    private:
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_EFFECT_H
