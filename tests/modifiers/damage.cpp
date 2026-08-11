#include <gtest/gtest.h>

#include "interactables/hp.h"
#include "effects/damage.h"

class ModifierDamageTest : public testing::Test
{
protected:
    ModifierDamageTest() {}

    Interactables::Hp hp { 100.0 };
    Effects::Damage decimate { 1.0 };
};

TEST_F(ModifierDamageTest, EffectReduceHp) {
    decimate.apply_effect(hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}

TEST_F(ModifierDamageTest, EffectReducesHpCalledFromBase) {
    Effects::Effect* mod = &decimate;
    mod->apply_effect(hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}
