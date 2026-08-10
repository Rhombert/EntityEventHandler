#ifndef ENTITYEVENTHANDLER_INTERACTABLE_ATTACK_SPEED_H
#define ENTITYEVENTHANDLER_INTERACTABLE_ATTACK_SPEED_H

#include "types/types.h"
#include "components/interactable_state.h"

class AttackSpeed : public InteractableState {
public:
    AttackSpeed(double base_attack_speed = 1.0)
        : InteractableState { Types::Interactable::ATTACK_SPEED }
        , m_base_attack_speed { base_attack_speed }
        , m_current_attack_speed { base_attack_speed }
    { }

    void reset() { m_current_attack_speed = m_base_attack_speed; }

    void receive_effect(Modifiers::ModifierEffect *effect)
    {
        effect->apply_effect(*this);
    }

    double get_mod_value() const { return m_current_attack_speed; }

protected:
    

private:
    double m_base_attack_speed {};
    double m_current_attack_speed {};
};

#endif//ENTITYEVENTHANDLER_INTERACTABLE_ATTACK_SPEED_H
