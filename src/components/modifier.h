#ifndef ENTITYEVENTHANDLER_MODIFIER_H
#define ENTITYEVENTHANDLER_MODIFIER_H

#include <memory>

#include "components/modifier_effect.h"

namespace Modifiers {
    class Modifier 
    {
    public:
        Modifier() = default;
        Modifier(ModifierEffect* effect, double tick_rate, int tick_num);
        ~Modifier();

        virtual void apply(double delta, 
                           Interactables::InteractableState& state);

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
        // The current accumulated time, determines when the threshold
        // is passed for another tick.
        double m_time_acc { 0.0 };

        std::unique_ptr<ModifierEffect> m_effect { nullptr };
    };


}


#endif //ENTITYEVENTHANDLER_MODIFIER_H
