#ifndef ENTITYEVENTHANDLER_MODIFIER_H
#define ENTITYEVENTHANDLER_MODIFIER_H

#include <godot_cpp/classes/ref_counted.hpp>

#include "./interactable_state.h"

namespace godot {
    class Modifier : public RefCounted {
        GDCLASS(Modifier, RefCounted)

    public:
        Modifier();
        ~Modifier();

        void apply(double delta, InteractableState& state);

    protected:
        static void _bind_methods();

        void apply_effect(InteractableState& state);

    private:
        // The rate (in seconds) at which the Modifier ticks
        double m_tick_rate {};
        // The number of ticks before the Modifier self destructs
        double m_tick_num {};
        // The current accumulated time, determines when the threshold
        // is passed for another tick.
        double m_time_acc { 0.0 };
    };
}

#endif //ENTITYEVENTHANDLER_MODIFIER_H
