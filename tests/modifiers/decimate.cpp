#include <gtest/gtest.h>

#include "interactables/hp.h"
#include "modifiers/decimate.h"

class ModifierDecimateTest : public testing::Test
{
protected:
    ModifierDecimateTest() {}

    Interactables::Hp hp { 100.0 };
    Modifiers::Decimate decimate { 1.0 };
};

TEST_F(ModifierDecimateTest, EffectReduceHp) {
    decimate.apply_effect(hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}

TEST_F(ModifierDecimateTest, EffectReducesHpCalledFromBase) {
    Modifiers::ModifierEffect* mod = &decimate;
    mod->apply_effect(hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}
