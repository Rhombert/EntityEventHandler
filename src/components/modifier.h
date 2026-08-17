#ifndef ENTITYEVENTHANDLER_MODIFIER_H
#define ENTITYEVENTHANDLER_MODIFIER_H

#include <memory>

#include "components/effect.h"
#include "types/types.h"

namespace Modifiers {
    class Modifier 
    {
    public:
        Modifier(Effects::Effect* effect, 
                 double tick_rate, 
                 int tick_num,
                 bool instant_activation = true);
        Modifier(const Modifier& modifier);

        Effects::Effect* get_effect() const;

        // Modifiers need to operate over states in a particular order,
        // with a variable number of ticks occuring each frame.
        // The pipeline wants to call the modifier on each state
        // once per frame. This creates the following scenario:
        //  The modifier may need to tick multiple times within a frame.
        //  This means that if damage is ticking 3 times in one frame,
        //  and it's being affected by armour, it needs to deal its
        //  damage-armour three times.
        //  This is 3(damage-armour), NOT 3(damage-3armour), which is
        //  the current behaviour.
        // A potential solution is for the modifier to maintain
        //  prepared instances that it sets up during each tick,
        //  and expends through subsequent calls to each state.

        void apply(double delta, Interactables::InteractableState& state);

        void tick();
        bool has_remaining_ticks();

    protected:
        double get_tick_rate() const { return m_tick_rate; };
        void set_tick_rate(double rate) { m_tick_rate = rate; };

        int get_tick_num() const { return m_tick_num; }
        void set_num_ticks(int num) { m_tick_num = num; }

    private:
        // The rate (in seconds) at which the Modifier ticks
        double m_tick_rate { 0.2 };
        // The number of ticks before the Modifier self destructs
        int m_tick_num { 1 };
        int m_tick_count { 0 };
        // The current accumulated time, determines when the threshold
        //  is passed for another tick.
        double m_time_acc { 0.0 };
        bool m_instant_activation { };

        std::unique_ptr<Effects::Effect> m_effect { nullptr };
    };
}


#endif//ENTITYEVENTHANDLER_MODIFIER_H
