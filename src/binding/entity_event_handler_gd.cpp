#include "binding/entity_event_handler_gd.h"

#include "binding/interaction_gd.h"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/print_string.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "types/types.h"

using namespace godot;

EntityEventHandlerGd::EntityEventHandlerGd()
    : m_event_handler { 100.0, 0.0 }
{ }

EntityEventHandlerGd::EntityEventHandlerGd(
        double base_hp,
        double base_armour
        )
    : m_event_handler { base_hp, base_armour }
{ }

void EntityEventHandlerGd::_process(double delta)
{
    m_event_handler._process(delta);
}

void EntityEventHandlerGd::receive_interaction(
        Variant interaction) 
{
    print_line("receive_interaction received: ", interaction.get_type());
    auto* object = interaction.get_validated_object();
    auto* c_interaction = Object::cast_to<InteractionGd>(object);
    m_event_handler.recieve_interaction(c_interaction->get_interaction());
}

void EntityEventHandlerGd::print_state()
{
    print_line("HP: ", m_event_handler.get_interactable<
            Types::Interactable::HP>()->get_health());
    print_line("ARMOUR: ", m_event_handler.get_interactable<
            Types::Interactable::ARMOUR>()->get_current_armour());
    print_line("ATTACK SPEED: ", m_event_handler.get_interactable<
            Types::Interactable::ATTACK_SPEED>()->get_attack_speed());
}

void EntityEventHandlerGd::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_process", "delta"),
                         &EntityEventHandlerGd::_process);
    ClassDB::bind_method(D_METHOD("receive_interaction", "interaction"),
                         &EntityEventHandlerGd::receive_interaction);
    ClassDB::bind_method(D_METHOD("print_state"),
                         &EntityEventHandlerGd::print_state);
}
