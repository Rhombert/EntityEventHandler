#ifndef ENTITYEVENTHANDLER_MODIFIER_EFFECT_H
#define ENTITYEVENTHANDLER_MODIFIER_EFFECT_H

#include "types/types.h"
#include <memory>

namespace Interactables {
    class InteractableState;
    class Hp;
    class AttackSpeed;
}

namespace Effects {
    class Effect 
    {
    public:
        Effect(Types::Interactable target)
            : m_target { target }
        { }
        virtual ~Effect() = default;

        virtual void apply_effect(Interactables::InteractableState* state) {};
        virtual void apply_effect(Interactables::Hp* state) {};
        virtual void apply_effect(Interactables::AttackSpeed& state) {};

        Types::Interactable get_target() const { return m_target; }

        virtual std::unique_ptr<Effect> clone() const = 0;

    private:
        Types::Interactable m_target {};
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_EFFECT_H
