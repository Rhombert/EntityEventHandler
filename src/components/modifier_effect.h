#ifndef ENTITYEVENTHANDLER_MODIFIER_EFFECT_H
#define ENTITYEVENTHANDLER_MODIFIER_EFFECT_H

class InteractableState;
class Hp;

class ModifierEffect 
{
public:
    virtual ~ModifierEffect() = default;

    virtual void apply_effect(InteractableState& state) = 0;
    virtual void apply_effect(Hp& state) = 0;

private:
};

#endif//ENTITYEVENTHANDLER_MODIFIER_EFFECT_H
