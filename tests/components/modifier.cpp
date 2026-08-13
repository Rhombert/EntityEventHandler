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
    decimate.apply(0.0, hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}

TEST_F(ModifierTest, DecimateDeltaOneTick) {
    decimate.apply(0.2, hp);
    EXPECT_EQ(hp.get_health(), 98.0);
}

TEST_F(ModifierTest, DecimateDeltaOneTickSplit) {
    decimate.apply(0.1, hp);
    decimate.apply(0.1, hp);
    EXPECT_EQ(hp.get_health(), 98.0);
}

TEST_F(ModifierTest, DecimateDeltaTenTicksIndividual) {
    for (int i { 0 }; i < 10; ++i) {
        decimate.apply(0.2, hp);
    }
    EXPECT_EQ(hp.get_health(), 89.0);
}

TEST_F(ModifierTest, DecimateDeltaTenTicksGrouped) {
    decimate.apply(0.2*10.0, hp);
    EXPECT_EQ(hp.get_health(), 89.0);
}
