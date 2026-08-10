#include <gtest/gtest.h>
#include <memory>

#include "interactables/hp.h"
#include "modifiers/decimate.h"
#include "components/modifier.h"

class ModifierTest : public testing::Test
{
protected:
    ModifierTest() {
    }

    Interactables::Hp hp { 100.0 };
    Modifiers::Modifier decimate { 
        new Modifiers::Decimate { 1.0 },
        0.2,
        10
    };
};

TEST_F(ModifierTest, DoesNothingWithNoDelta) {
    decimate.apply(0.0, hp);
    EXPECT_EQ(hp.get_health(), 100.0);
}

TEST_F(ModifierTest, DeltaOneTick) {
    decimate.apply(0.2, hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}

TEST_F(ModifierTest, DeltaOneTickSplit) {
    decimate.apply(0.1, hp);
    decimate.apply(0.1, hp);
    EXPECT_EQ(hp.get_health(), 99.0);
}

TEST_F(ModifierTest, DeltaTenTicksIndividual) {
    for (int i { 0 }; i < 10; ++i) {
        decimate.apply(0.2, hp);
    }
    EXPECT_EQ(hp.get_health(), 90.0);
}

TEST_F(ModifierTest, DeltaTenTicksGrouped) {
    decimate.apply(0.2*10.0, hp);
    EXPECT_EQ(hp.get_health(), 90.0);
}
