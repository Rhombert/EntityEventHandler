#ifndef ENTITYEVENTHANDLER_INTERACTABLE_HP_H
#define ENTITYEVENTHANDLER_INTERACTABLE_HP_H

#include "components/effect.h"
#include "components/interactable_state.h"

namespace Interactables {
    class Hp : public InteractableState {

    public:
        Hp(double value = 100.0);

        void heal(double amount);
        void damage(double amount);

        void receive_effect(Effects::Effect *effect) override;

        void update() override;

        double get_health() const;
        double get_max_health() const;

    protected:
        
    private:
        double m_base_current_health {};
        double m_current_health {};

        double& m_base_max_health { get_base_value_ref() };
        double& m_max_health { get_current_value_ref() };
    };
}
#endif//ENTITYEVENTHANDLER_INTERACTABLE_HP_H
