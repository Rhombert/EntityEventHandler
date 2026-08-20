#ifndef ENTITYEVENTHANDLER_MODIFIER_H
#define ENTITYEVENTHANDLER_MODIFIER_H

#include <memory>
#include <vector>

#include "components/effect.h"
#include "types/types.h"

namespace Modifiers {
    class Modifier 
    {
    public:
        Modifier();
        Modifier(Effects::Effect* effect, 
                 double tick_rate, 
                 int tick_num,
                 bool instant_activation = true);
        Modifier(const Modifier& modifier);

        void set_effect(Effects::Effect* effect);
        Effects::Effect* get_effect() const;

        void tick(double delta);

        void apply(Interactables::InteractableState& state);

        bool has_remaining_ticks();

        double get_tick_rate() const { return m_tick_rate; };
        void set_tick_rate(double rate) { m_tick_rate = rate; };

        int get_tick_num() const { return m_tick_num; }
        void set_num_ticks(int num) { m_tick_num = num; }

        void set_is_instant(bool is_instant) {
            m_instant_activation = is_instant;
            if (is_instant) m_time_acc = m_tick_rate;
            else m_time_acc = 0.0;
        }

    protected:

    private:
        // The rate (in seconds) at which the Modifier ticks
        double m_tick_rate { 0.2 };
        // The number of ticks before the Modifier self destructs
        int m_tick_num { 1 };
        int m_tick_count { 0 };

        std::vector<std::unique_ptr<Effects::Effect>> m_effect_instances {};
        // The current accumulated time, determines when the threshold
        //  is passed for another tick.
        double m_time_acc { 0.0 };
        bool m_instant_activation { };

        std::unique_ptr<Effects::Effect> m_effect { nullptr };
    };
}


#endif//ENTITYEVENTHANDLER_MODIFIER_H
