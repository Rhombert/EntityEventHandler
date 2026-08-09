#include <gtest/gtest.h>

#include "interactables/hp.h"
#include "modifiers/decimate.h"

class ModifierDecimateTest : public testing::Test
{
protected:
    ModifierDecimateTest() {}

    Hp hp { 100.0 };
    Decimate decimate { 1.0 };
};

TEST_F(ModifierDecimateTest, EffectReduceHp) {
    decimate.apply_effect(hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}
