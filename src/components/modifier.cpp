#include "components/modifier.h"
#include "components/interactable_state.h"

using namespace godot;

Modifier::Modifier() {}
Modifier::Modifier(double tick_rate, int tick_num)
    : m_tick_rate { tick_rate }
    , m_tick_num { tick_num }
{ }
Modifier::~Modifier() {}

void Modifier::apply(double delta, InteractableState& state)
{
    m_time_acc += delta;
    if (m_time_acc >= m_tick_rate)
    {
        m_time_acc -= m_tick_rate;
        apply_effect(state);
    }
}

void Modifier::apply_effect(InteractableState& state) {}

void Modifier::_bind_methods() {}

