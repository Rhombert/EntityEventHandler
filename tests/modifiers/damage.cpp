#include <gtest/gtest.h>

#include "components/interactable.h"
#include "interactables/hp.h"
#include "effects/damage.h"

class ModifierDamageTest : public testing::Test
{
protected:
    ModifierDamageTest() {}

    Interactables::Hp hp { 100.0 };
    Effects::Damage damage { 1.0 };
};

TEST_F(ModifierDamageTest, EffectReduceHp) {
    damage.apply_effect(&hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}

TEST_F(ModifierDamageTest, EffectReducesHpCalledFromBase) {
    Effects::Effect* mod = &damage;
    mod->apply_effect(&hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}

// TEST_F(ModifierDamageTest, EffectReducesInteractableHp) {
//     Effects::Effect* effect_ptr = &damage;
//     Interactables::Interactable int_hp { hp };
//     int_hp.attach(effect_ptr);
//     int_hp.process(100.0);
//     const Interactables::Hp* int_hp_state { 
//         static_cast<const Interactables::Hp*>(int_hp.get_state()) 
//     };
//     EXPECT_LT(int_hp_state->get_health(), 100.0);
// }
