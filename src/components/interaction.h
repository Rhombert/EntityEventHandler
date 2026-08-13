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
        template<typename... M>
                requires (std::derived_from<M, Modifiers::Modifier> && ...)
        Interaction(M&... modifiers)
            : m_effects { }
            , m_modifiers { }
        { 
            (m_modifiers.emplace_back(std::make_unique<M>(
                modifiers
            )), ...);
        }
        
        // template<typename... E, typename... M>
        //     requires(std::derived_from<E, Effects::Effect> && ...)
        //          && (std::derived_from<M, Modifiers::Modifier> && ...)
        // Interaction(E... effects, M... modifiers)
        //     : m_effects { effects... }
        //     , m_modifiers { modifiers... }
        // { }

        void apply(Interactables::Interactable& interactable) const;

    protected:
        static void _bind_methods();

    private:
        std::vector<std::unique_ptr<Effects::Effect>> m_effects {};
        std::vector<std::unique_ptr<Modifiers::Modifier>> m_modifiers {};
    };
}

#endif//ENTITYEVENTHANDLER_INTERACTION_H
