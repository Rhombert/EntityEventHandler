#include <gtest/gtest.h>

#include "interactables/hp.h"

class InteractableHpTest : public testing::Test
{
protected:
    InteractableHpTest() {};

    double DEFAULT_HP { 100.0 };
    Interactables::Hp hp { DEFAULT_HP };
};

TEST_F(InteractableHpTest, CurrentHpMaintainsRatioOnMaxHpChange){
    hp.damage(50.0);
    hp.apply_additive_bonus(20.0);
    hp.update();

    EXPECT_EQ(hp.get_current_value(), 120.0);
    EXPECT_EQ(hp.get_health(), 60.0);
}
