#include <gtest/gtest.h>

#include "interactables/hp.h"
#include "effects/damage.h"
#include "components/modifier.h"

class ModifierTest : public testing::Test
{
protected:
    ModifierTest() {}

    Interactables::Hp hp { 100.0 };
    Modifiers::Modifier decimate { 
        new Effects::Damage { 1.0 },
        0.2,
        10
    };
};

TEST_F(ModifierTest, DecimateTicksImmediatelyWithNoDelta) {
    decimate.tick(0.0);
    decimate.apply(hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}

TEST_F(ModifierTest, DecimateDeltaOneTick) {
    decimate.tick(0.2);
    decimate.apply(hp);
    EXPECT_EQ(hp.get_health(), 98.0);
}

TEST_F(ModifierTest, DecimateDeltaOneTickSplit) {
    decimate.tick(0.1);
    decimate.apply(hp);
    decimate.tick(0.1);
    decimate.apply(hp);
    EXPECT_EQ(hp.get_health(), 98.0);
}

TEST_F(ModifierTest, DecimateDeltaTenTicksIndividual) {
    for (int i { 0 }; i < 9; ++i) {
        // First tick ticks twice, instant by default.
        decimate.tick(0.2);
        decimate.apply(hp);
    }
    EXPECT_EQ(hp.get_health(), 90.0);
}

TEST_F(ModifierTest, DecimateDeltaTenTicksGrouped) {
    decimate.tick(0.2*9.0);
    decimate.apply(hp);
    EXPECT_EQ(hp.get_health(), 90.0);
}
