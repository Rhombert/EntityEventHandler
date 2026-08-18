#include "components/effect.h"
#include "effects/damage.h"
#include "types/types.h"
#include <gtest/gtest.h>
#include <memory>

class EffectImpl : public Effects::Effect
{
public:
    EffectImpl()
        : Effects::Effect { Types::Interactable::HP }
    { }

    std::unique_ptr<Effect> clone() const
    {
        return std::make_unique<EffectImpl>(*this);
    }
};

class EffectTest : public testing::Test
{
protected:
EffectTest() {}
};

TEST_F(EffectTest, SingleTargetConstructor) {
    EffectImpl effect {};
    ASSERT_TRUE(effect.does_target(Types::Interactable::HP));
    ASSERT_FALSE(effect.does_target(Types::Interactable::ARMOUR));
    ASSERT_FALSE(effect.does_target(Types::Interactable::MOVE_SPEED));
    ASSERT_FALSE(effect.does_target(Types::Interactable::TURN_SPEED));
}

TEST_F(EffectTest, MultipleTargetConstructor) {
    Effects::Damage damage { 1.0 };
    ASSERT_TRUE(damage.does_target(Types::Interactable::HP));
    ASSERT_TRUE(damage.does_target(Types::Interactable::ARMOUR));
    ASSERT_FALSE(damage.does_target(Types::Interactable::MOVE_SPEED));
    ASSERT_FALSE(damage.does_target(Types::Interactable::TURN_SPEED));
}
