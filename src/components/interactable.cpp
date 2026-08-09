#include "godot_cpp/core/class_db.hpp"

#include "components/interactable.h"

using namespace godot;

Interactable::Interactable() {}

Interactable::~Interactable() {}

void Interactable::process(double delta)
{
    for (auto& modifier : m_modifiers)
    {
        modifier.apply(delta, *m_state);
    }
}

double Interactable::get_mod_value() const
{
    return m_state->get_mod_value();
}

void Interactable::gd_attach_modifier(Variant modifier)
{

}

void Interactable::attach_modifier(Modifier modifier)
{

}
