#ifndef ENTITYEVENTHANDLER_INTERACTABLE_HP_H
#define ENTITYEVENTHANDLER_INTERACTABLE_HP_H

#include "types/types.h"
#include "components/interactable_state.h"

namespace godot {
    // Hp is bound to its maximum value and 0
    class Hp : public InteractableState {
        GDCLASS(Hp, InteractableState)

    public:
        Hp(double value = 100.0)
            : InteractableState { Types::Interactable::HP }
            , m_current_health { value }
            , m_max_health { value }
        { };
        ~Hp() {};

        static Ref<Hp> create(double value);
        static int test() { return 5; }

        void heal(double amount);
        void damage(double amount);

        double get_health() const { return m_current_health; }
        double get_max_health() const { return m_max_health; }

    protected:
        static void _bind_methods();
        
    private:
        double m_current_health {};
        double m_max_health {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTABLE_HP_H
