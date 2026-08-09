#include "components/modifier.h"
#include "components/interactable_state.h"
#include <iostream>

using namespace godot;

Modifier::Modifier() {}
Modifier::Modifier(double tick_rate, int tick_num)
    : m_tick_rate { tick_rate }
    , m_tick_num { tick_num }
{ }
Modifier::~Modifier() {}

void Modifier::apply(double delta, InteractableState& state)
{
    std::cout << "Modifier::apply\n";
    m_time_acc += delta;
    if (m_time_acc >= m_tick_rate)
    {
        m_time_acc -= m_tick_rate;
        apply_effect(state);
    }
}

void Modifier::apply_effect(InteractableState& state) {
    std::cout << "Modifier::apply_effect\n";
}

void Modifier::_bind_methods() {}

