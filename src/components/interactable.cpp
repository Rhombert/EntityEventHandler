#include "components/interactable.h"
#include <memory>

using namespace Interactables;

void Interactable::process(double delta)
{
    for (auto& modifier : m_modifiers) {
        modifier->apply(delta, *m_state);
    }
    for (auto& effect : m_effect_queue) {
        effect->apply_effect(m_state.get());
    }
}

Types::Interactable Interactable::get_type() const 
{ 
    return m_state->get_type(); 
}

double Interactable::get_mod_value() const 
{ 
    return m_state->get_mod_value(); 
};

const InteractableState* Interactable::get_state() 
{ 
    return m_state.get(); 
}

void Interactable::attach(const Modifiers::Modifier& modifier)
{
    if (modifier.get_target() != m_state->get_type()) return;

    m_modifiers.push_back(
            std::make_unique<Modifiers::Modifier>(modifier)
    );
}

void Interactable::attach(const Modifiers::Modifier* modifier)
{
    if (modifier->get_target() != m_state->get_type()) return;

    m_modifiers.push_back(
            std::make_unique<Modifiers::Modifier>(*modifier)
    );
}

void Interactable::attach(const Effects::Effect& effect)
{
    if (effect.get_target() != m_state->get_type()) return;


    m_effect_queue.push_back(
        effect.clone()
    );
}

void Interactable::attach(const Effects::Effect* effect)
{
    if (effect->get_target() != m_state->get_type()) return;


    m_effect_queue.push_back(
        effect->clone()
    );
}
