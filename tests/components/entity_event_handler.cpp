#include "components/entity_event_handler.h"
#include "components/interaction.h"
#include "effects/damage.h"
#include "types/types.h"
#include <gtest/gtest.h>

class EntityEventHandlerTest : public testing::Test
{
protected:
    EntityEventHandlerTest() {}

    const double MAX_HP { 100.0 };
    const double TICK_TIME { 0.2 };
    const double DAMAGE_AMOUNT { 1.0 };

    EntityEventHandler event_handler { MAX_HP, 1.0 };
    Modifiers::Modifier mod_decimate {
        new Effects::Damage { DAMAGE_AMOUNT },
        TICK_TIME,
        10
    };
};

TEST_F(EntityEventHandlerTest, AbleToRetrieveHp)
{
    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_TRUE(hp != nullptr);
}

TEST_F(EntityEventHandlerTest, DecimateBaseTickReducesHp)
{
    Interactions::Interaction int_decimate {};
    int_decimate.add(mod_decimate);

    event_handler.recieve_interaction(int_decimate);
    event_handler._process(0.0);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_LT(hp->get_health(), MAX_HP);
}

TEST_F(EntityEventHandlerTest, DecimateBaseTickReducesCorrectAmountHp)
{
    Interactions::Interaction int_decimate {};
    int_decimate.add(mod_decimate);

    event_handler.recieve_interaction(int_decimate);
    event_handler._process(0.0);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_EQ(hp->get_health(), MAX_HP - DAMAGE_AMOUNT);
}

TEST_F(EntityEventHandlerTest, DecimateTenTicksReducesCorrectAmountHp)
{
    Interactions::Interaction int_decimate {};
    int_decimate.add(mod_decimate);

    event_handler.recieve_interaction(int_decimate);
    event_handler._process(TICK_TIME*9.0);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_EQ(hp->get_health(), MAX_HP - DAMAGE_AMOUNT * 10.0);
}

TEST_F(EntityEventHandlerTest, DoubleDecimateTenTicksReducesCorrectAmountHp)
{
    Interactions::Interaction int_decimate {};
    int_decimate.add(mod_decimate);
    int_decimate.add(mod_decimate);

    event_handler.recieve_interaction(int_decimate);
    event_handler._process(TICK_TIME*9.0);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_EQ(hp->get_health(), MAX_HP - DAMAGE_AMOUNT * 2.0 * 10.0);
}

TEST_F(EntityEventHandlerTest, TwoInterDecimateTenTicksReducesCorrectAmountHp)
{
    Interactions::Interaction int_decimate {};
    int_decimate.add(mod_decimate);

    event_handler.recieve_interaction(int_decimate);
    event_handler.recieve_interaction(int_decimate);
    event_handler._process(TICK_TIME*9.0);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_EQ(hp->get_health(), MAX_HP - DAMAGE_AMOUNT * 2.0 * 10.0);
}
