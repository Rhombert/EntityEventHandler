#include <gtest/gtest.h>

#include "interactables/hp.h"
#include "effects/heal.h"

class ModifierRegenTest : public testing::Test
{
protected:
    ModifierRegenTest() {
        hp.damage(20.0);
    }

    Interactables::Hp hp { 100.0 };
    Effects::Heal regen { 1.0 };
};

TEST_F(ModifierRegenTest, EffectIncreasesHp) {
    regen.apply_effect(hp);
    EXPECT_EQ(hp.get_health(), 81.0);
}

TEST_F(ModifierRegenTest, EffectIncreasesHpCalledFromBase) {
    Effects::Effect* mod = &regen;
    mod->apply_effect(hp);
    EXPECT_EQ(hp.get_health(), 81.0);
}
