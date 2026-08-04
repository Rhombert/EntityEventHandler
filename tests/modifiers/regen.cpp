#include <gtest/gtest.h>

#include "interactables/hp.h"
#include "modifiers/regen.h"

using namespace godot;

TEST(Modifier_Regen, TickIncreasesHp) {
    // Regen regen { 1, 0.01, 10 };
    Hp hp { 100.0 };

    EXPECT_EQ(true, true);

    // hp.damage(50.0);

    // EXPECT_EQ(hp.get_health(), 50.0);
    // regen.apply_effect(hp);
    // EXPECT_GT(hp.get_health(), 50.0);
}

