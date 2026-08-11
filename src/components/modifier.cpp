#include "components/modifier.h"

using namespace Modifiers;


Modifier::Modifier(Effects::Effect* effect, double tick_rate, int tick_num)
    : m_effect { std::unique_ptr<Effects::Effect>(effect) }
    , m_tick_rate { tick_rate }
    , m_tick_num { tick_num }
{ }

Modifier::~Modifier() {}

void Modifier::apply(double delta, 
                           Interactables::InteractableState& state)
{
    m_time_acc += delta;
    while (m_time_acc >= m_tick_rate)
    {
        m_time_acc -= m_tick_rate;
        m_effect->apply_effect(state);
    }
}
