#ifndef ENTITYEVENTHANDLER_MODIFIER_REGEN_H
#define ENTITYEVENTHANDLER_MODIFIER_REGEN_H

#include "components/effect.h"
#include "interactables/hp.h"
#include "types/types.h"
#include <memory>

namespace Effects {
    class Heal : public Effect
    {

    public:
        Heal(double heal_value)
            : Effect { Types::Interactable::HP }
            , m_heal_value { heal_value }
        { }

        void apply_effect(Interactables::InteractableState* state) override;
        void apply_effect(Interactables::Hp* state) override;

        std::unique_ptr<Effect> clone() const override;

    protected:

    private:
        double m_heal_value {};
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_REGEN_H
