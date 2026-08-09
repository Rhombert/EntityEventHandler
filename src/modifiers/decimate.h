#ifndef ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H
#define ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H

#include "components/modifier_effect.h"
#include "interactables/hp.h"

class Decimate : public ModifierEffect
{
public:
    Decimate(double damage_value)
        : m_damage_value { damage_value }
    { }

    void apply_effect(InteractableState& state) override {};
    void apply_effect(Hp& state) override;
        
protected:

private:
    double m_damage_value {};
};

#endif//ENTITYEVENTHANDLER_MODIFIER_DECIMATE_H
