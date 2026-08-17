#include "components/modifier.h"
#include <iostream>

using namespace Modifiers;


Modifier::Modifier(Effects::Effect* effect, 
                   double tick_rate, 
                   int tick_num,
                   bool instant_activation)
    : m_effect { std::unique_ptr<Effects::Effect>(effect) }
    , m_tick_rate { tick_rate }
    , m_tick_num { tick_num }
    , m_tick_count { 0 }
    , m_time_acc { instant_activation ? tick_rate : 0.0 }
    , m_instant_activation { instant_activation }
{ 
    std::cout << "Created modifier with count/num "
              << m_tick_count << " / " << m_tick_num << '\n';
}

Modifier::Modifier(const Modifier& modifier)
    : m_effect (modifier.m_effect->clone())
    , m_tick_rate { modifier.m_tick_rate }
    , m_tick_num { modifier.m_tick_num }
    , m_tick_count { modifier.m_tick_count }
    , m_time_acc { modifier.m_instant_activation ? modifier.m_tick_rate : 0.0 }
    , m_instant_activation { modifier.m_instant_activation }
{ }

Effects::Effect* Modifier::get_effect() const { return m_effect.get(); }

void Modifier::apply(double delta, 
                           Interactables::InteractableState& state)
{
    if (!has_remaining_ticks()) return;
    m_time_acc += delta;
    while (m_time_acc >= m_tick_rate)
    {
        m_time_acc -= m_tick_rate;
        m_effect->apply_effect(&state);
    }
}

void Modifier::tick() { 
    std::cout << "Tick!\n";
    m_tick_count++; 
}

bool Modifier::has_remaining_ticks() { 
    std::cout << "Has remaining: " << m_tick_count << " < "
              << m_tick_num << " = " << (m_tick_count < m_tick_num)
              << '\n';
    return m_tick_count <= m_tick_num; 
}
