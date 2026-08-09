#ifndef ENTITYEVENTHANDLER_MODIFIER_H
#define ENTITYEVENTHANDLER_MODIFIER_H

#include <godot_cpp/classes/ref_counted.hpp>

#include "components/interactable_state.h"

namespace godot {
    class Modifier {

    public:
        Modifier();
        Modifier(double tick_rate, int tick_num);
        ~Modifier();

        virtual void apply(double delta, InteractableState& state);

    protected:
        void apply_effect(InteractableState& state);

        double get_tick_rate() const { return m_tick_rate; };
        void set_tick_rate(double rate) { m_tick_rate = rate; };

        int get_tick_num() const { return m_tick_num; }
        void set_num_ticks(int num) { m_tick_num = num; }

        static void _bind_methods();

    private:
        // The rate (in seconds) at which the Modifier ticks
        double m_tick_rate {};
        // The number of ticks before the Modifier self destructs
        int m_tick_num {};
        // The current accumulated time, determines when the threshold
        // is passed for another tick.
        double m_time_acc { 0.0 };
    };
}

#endif //ENTITYEVENTHANDLER_MODIFIER_H
