#ifndef ENTITYEVENTHANDLER_INTERACTION_H
#define ENTITYEVENTHANDLER_INTERACTION_H

#include <concepts>
#include <memory>
#include <vector>

#include "components/effect.h"
#include "components/interactable.h"
#include "components/modifier.h"

namespace Interactions {

    class Interaction 
    {
    public:
        void add(Effects::Effect&);
        void add(Modifiers::Modifier&);

        void apply(Interactables::Interactable&) const;

    protected:
        static void _bind_methods();

    private:
        std::vector<std::unique_ptr<Effects::Effect>> m_effects {};
        std::vector<std::unique_ptr<Modifiers::Modifier>> m_modifiers {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTION_H
