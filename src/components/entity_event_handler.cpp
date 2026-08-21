#include "entity_event_handler.h"

#include <iostream>
#include <memory>

#include "components/interactable.h"
#include "interactables/hp.h"
#include "interactables/armour.h"
#include "interactables/attack_speed.h"
#include "interactables/move_speed.h"
#include "interactables/turn_speed.h"
#include "types/types.h"


using ITypes = Types::Interactable;

EntityEventHandler::EntityEventHandler(
        double base_hp,
        double base_armour)
{
    m_interactables.resize(
        (unsigned long)(Types::Interactable::INTERACTABLE_TYPES_COUNT)
    );
    m_interactables[(size_t)Types::Interactable::HP] =
        std::make_unique<Interactable>(Hp { base_hp });
    m_interactables[(size_t)Types::Interactable::ARMOUR] =
        std::make_unique<Interactable>(Armour { base_armour });
    m_interactables[(size_t)Types::Interactable::ATTACK_SPEED] =
        std::make_unique<Interactable>(AttackSpeed { });
    m_interactables[(size_t)Types::Interactable::MOVE_SPEED] =
        std::make_unique<Interactable>(MoveSpeed { });
    m_interactables[(size_t)Types::Interactable::TURN_SPEED] =
        std::make_unique<Interactable>(TurnSpeed { });

    m_pipeline.resize(
        (unsigned long)(Types::Interactable::INTERACTABLE_TYPES_COUNT)
    );
}

void EntityEventHandler::_process(double delta) {
    size_t mods_initial_size { m_modifiers.size() };
    for (int i { 0 }; i < mods_initial_size; ++i)
    {
        std::shared_ptr<Modifiers::Modifier> mod = m_modifiers.front();
        m_modifiers.pop();
        mod->tick(delta); 
        if (mod->has_remaining_ticks()) m_modifiers.push(mod);
    }

    for (int i { 0 }; i < (int)ITypes::INTERACTABLE_TYPES_COUNT; ++i)
    {
        auto& queue = m_pipeline[i];
        int q_size { (int)queue.size() };
        for (int q { 0 }; q < q_size; ++q) {
            std::shared_ptr<Modifiers::Modifier> modifier = queue.front(); 
            queue.pop();
            modifier->apply(*m_interactables[i]->get_state());
            if (modifier->has_remaining_ticks()) queue.push(modifier);
        }
    }
}

void EntityEventHandler::recieve_interaction(
        Interactions::Interaction& interaction)
{
    for (const auto& modifier : interaction.get_modifiers()) {
        m_modifiers.push(
                std::make_shared<Modifiers::Modifier>(*modifier));
        auto& new_mod = m_modifiers.back();

        for (int i {0}; i < (int)ITypes::INTERACTABLE_TYPES_COUNT; ++i)
        {
            if (new_mod->get_effect()->does_target((ITypes)i)) {
                m_pipeline[i].push(new_mod);
            }
        }
    }
}

void EntityEventHandler::set_hp(double hp)
{
    auto *_hp = get_interactable_mut<Types::Interactable::HP>();
    _hp->set_value(hp);
}
