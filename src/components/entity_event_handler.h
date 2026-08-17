#ifndef ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
#define ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H

#include <vector>
#include <queue>
#include <memory>

#include "components/interactable.h"
#include "components/interaction.h"

#include "types/types.h"
#include "types/type_to_class.h"

using namespace Interactables;

class EntityEventHandler {
public:
    EntityEventHandler(
        double base_hp,
        double base_armour
    );

    void _process(double delta);

    void recieve_interaction(Interactions::Interaction& interaction);

    template<Types::Interactable I>
    const Types::InteractableTypeT<I>* get_interactable() const
    { 
        return static_cast<const Types::InteractableTypeT<I>*>(
            m_interactables.at((size_t)I).get()->get_state()
        );
    }

protected:

private:
    std::vector<std::unique_ptr<Interactable>> m_interactables {};
    std::queue<std::shared_ptr<Modifiers::Modifier>> m_modifiers {};

    std::vector<std::queue<
                std::shared_ptr<Modifiers::Modifier>>> m_pipeline {};
};

#endif //ENTITYEVENTHANDLER_ENTITY_EVENT_HANDLER_H
