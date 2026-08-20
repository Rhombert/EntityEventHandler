#ifndef ENTITYEVENTHANDLER_INTERACTION_H
#define ENTITYEVENTHANDLER_INTERACTION_H

#include <memory>
#include <vector>

#include "components/modifier.h"
#include "components/interactable_state.h"


namespace Interactions {

    class Interaction 
    {
    public:
        using ModifierVector = 
            std::vector<std::unique_ptr<Modifiers::Modifier>>;

        void add(Modifiers::Modifier&&);
        void add(Modifiers::Modifier&);

        const ModifierVector& get_modifiers() const;

    protected:

    private:
        ModifierVector m_modifiers {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTION_H
