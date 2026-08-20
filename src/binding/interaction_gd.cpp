#include "binding/interaction_gd.h"
#include "binding/modifier_gd.h"

using namespace godot;

InteractionGd::InteractionGd()
    : m_interaction { }
{ }

Interactions::Interaction& InteractionGd::get_interaction()
{
    return m_interaction;
}

void InteractionGd::add(Variant modifier)
{
    auto* object = modifier.get_validated_object();
    auto c_modifier = Object::cast_to<ModifierGd>(object);
    m_interaction.add(c_modifier->get_modifier());
}

void InteractionGd::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("add", "modifier"),
                         &InteractionGd::add);
}
