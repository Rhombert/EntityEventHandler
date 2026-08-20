#ifndef ENTITYEVENTHANDLER_MODIFIER_EFFECTGD_H
#define ENTITYEVENTHANDLER_MODIFIER_EFFECTGD_H

#include "components/effect.h"

#include "godot_cpp/classes/ref_counted.hpp"
namespace godot {
    class EffectGd : public RefCounted
    {
        GDCLASS(EffectGd, RefCounted)

        public:
            EffectGd();

            Effects::Effect* get_effect_instance();

        protected:
            static void _bind_methods();

            Effects::Effect* m_effect_instance;

        private:
    };
}

#endif//ENTITYEVENTHANDLER_MODIFIER_EFFECTGD_H
