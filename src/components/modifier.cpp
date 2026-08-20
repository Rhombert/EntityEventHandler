#include "components/modifier.h"
#include <memory>

using namespace Modifiers;

Modifier::Modifier()
    : m_effect { nullptr }
    , m_tick_rate { 0.2 }
    , m_tick_num { 1 }
    , m_time_acc { 0.2 }
    , m_instant_activation { true }
{ }

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
{ }

Modifier::Modifier(const Modifier& modifier)
    : m_effect (modifier.m_effect->clone())
    , m_tick_rate { modifier.m_tick_rate }
    , m_tick_num { modifier.m_tick_num }
    , m_tick_count { modifier.m_tick_count }
    , m_time_acc { modifier.m_instant_activation ? modifier.m_tick_rate : 0.0 }
    , m_instant_activation { modifier.m_instant_activation }
{ }

void Modifier::set_effect(Effects::Effect* effect) {
    m_effect = std::unique_ptr<Effects::Effect>(effect->clone());
}
Effects::Effect* Modifier::get_effect() const { return m_effect.get(); }

void Modifier::apply(Interactables::InteractableState& state)
{
    for (auto& effect : m_effect_instances) {
        //TODO: This likely needs to be made to call the explicit
        // implementation, not InteractableState&. ie call
        // Hp& instead.
        effect->apply_effect(&state);
    }
}

void Modifier::tick(double delta) { 
    m_effect_instances.clear();
    m_time_acc += delta;
    while (m_time_acc >= m_tick_rate)
    {
        if (!has_remaining_ticks()) break;
        m_time_acc -= m_tick_rate;
        m_effect_instances.push_back(m_effect->clone());
        m_tick_count++;
    }
}

bool Modifier::has_remaining_ticks() { 
    return m_tick_count < m_tick_num; 
}
