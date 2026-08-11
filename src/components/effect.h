#ifndef ENTITYEVENTHANDLER_MODIFIER_EFFECT_H
#define ENTITYEVENTHANDLER_MODIFIER_EFFECT_H

namespace Interactables {
    class InteractableState;
    class Hp;
    class AttackSpeed;
}

namespace Effects {
    class Effect 
    {
    public:
        virtual ~Effect() = default;

        virtual void apply_effect(Interactables::InteractableState& state) {}
        virtual void apply_effect(Interactables::Hp& state) {}
        virtual void apply_effect(Interactables::AttackSpeed& state) {}

    private:
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_EFFECT_H
