#include "interactable_state.h"
#include "modifier.h"

using namespace godot;

Modifier::Modifier() {}

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

void Modifier::apply_effect(InteractableState& state)
{
}

void Modifier::_bind_methods() {

}

