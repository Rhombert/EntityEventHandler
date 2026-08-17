#ifndef ENTITYEVENTHANDLER_MODIFIER_EFFECT_H
#define ENTITYEVENTHANDLER_MODIFIER_EFFECT_H

#include <bitset>
#include <iostream>
#include <memory>

#include "types/types.h"

namespace Interactables {
    class InteractableState;
    class Hp;
    class Armour;
    class AttackSpeed;
    class MoveSpeed;
    class TurnSpeed;
}

namespace Effects {
    class Effect 
    {
    public:
        Effect() { }
        Effect(Types::Interactable target) {
            m_targets.set((size_t)target);
        };

        //TODO: Figure this one out, replace the base constructor.
        // template<typename... T>
        // Effect(T... targets)
        // {
        //     f(m_targets.set(targets)...);
        // };

        // virtual ~Effect() = default;

        virtual void apply_effect(Interactables::InteractableState* state) {};
        virtual void apply_effect(Interactables::Hp* state) {};
        virtual void apply_effect(Interactables::Armour* state) {};
        virtual void apply_effect(Interactables::AttackSpeed* state) {};
        virtual void apply_effect(Interactables::MoveSpeed* state) {};
        virtual void apply_effect(Interactables::TurnSpeed* state) {};

        virtual void reset() {};

        const Types::InteractableBitset& get_targets() const { 
            return m_targets;
        }

        void set_targets(Types::InteractableBitset targets)
        {
            m_targets = targets;
        }

        void add_target(Types::Interactable target) 
        {
            m_targets.set((size_t)target);
        }

        bool does_target(Types::Interactable target)
        {
            return m_targets.test((size_t)target);
        }

        virtual std::unique_ptr<Effect> clone() const = 0;

    private:
        Types::InteractableBitset m_targets {};
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_EFFECT_H
