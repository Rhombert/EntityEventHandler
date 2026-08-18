#include "components/entity_event_handler.h"
#include "components/interaction.h"
#include "effects/damage.h"
#include "types/types.h"
#include <gtest/gtest.h>

class EntityEventHandlerTest : public testing::Test
{
protected:
    EntityEventHandlerTest() {
    }

    static constexpr double MAX_HP { 100.0 };
    static constexpr double TICK_TIME { 0.2 };
    static constexpr int TICK_LIMIT { 10 };
    static constexpr double DAMAGE_AMOUNT { 1.0 };

    EntityEventHandler event_handler { MAX_HP, 1.0 };

    Modifiers::Modifier make_decimate() {
        return {
            new Effects::Damage { DAMAGE_AMOUNT },
            TICK_TIME,
            TICK_LIMIT,
        };
    }
};

TEST_F(EntityEventHandlerTest, AbleToRetrieveHp)
{
    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_TRUE(hp != nullptr);
}

TEST_F(EntityEventHandlerTest, DecimateBaseTickReducesHp)
{
    Interactions::Interaction int_decimate {};
    int_decimate.add(make_decimate());

    event_handler.recieve_interaction(int_decimate);
    event_handler._process(0.0);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_LT(hp->get_health(), MAX_HP);
}

TEST_F(EntityEventHandlerTest, DecimateBaseTickReducesCorrectAmountHp)
{
    EntityEventHandler event_handler { MAX_HP, 1.0 };
    Interactions::Interaction int_decimate {};
    int_decimate.add(make_decimate());

    event_handler.recieve_interaction(int_decimate);
    event_handler._process(0.0);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_EQ(hp->get_health(), MAX_HP - DAMAGE_AMOUNT);
}

TEST_F(EntityEventHandlerTest, DecimateTenTicksReducesCorrectAmountHp)
{
    EntityEventHandler event_handler { MAX_HP, 1.0 };
    Interactions::Interaction int_decimate {};
    int_decimate.add(make_decimate());

    event_handler.recieve_interaction(int_decimate);
    event_handler._process(TICK_TIME*9.0);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_EQ(hp->get_health(), MAX_HP - DAMAGE_AMOUNT * 10.0);
}

TEST_F(EntityEventHandlerTest, DoubleDecimateTenTicksReducesCorrectAmountHp)
{
    EntityEventHandler event_handler { MAX_HP, 1.0 };
    Interactions::Interaction int_decimate {};
    int_decimate.add(make_decimate());
    auto mod_two = make_decimate();
    int_decimate.add(mod_two);

    event_handler.recieve_interaction(int_decimate);
    event_handler._process(TICK_TIME*9.0);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_EQ(hp->get_health(), MAX_HP - DAMAGE_AMOUNT * 2.0 * 10.0);
}

TEST_F(EntityEventHandlerTest, TwoInterDecimateTenTicksReducesCorrectAmountHp)
{
    Interactions::Interaction int_decimate {};
    int_decimate.add(make_decimate());

    event_handler.recieve_interaction(int_decimate);
    event_handler.recieve_interaction(int_decimate);
    event_handler._process(TICK_TIME*9.0);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_EQ(hp->get_health(), MAX_HP - DAMAGE_AMOUNT * 2.0 * 10.0);
}

TEST_F(EntityEventHandlerTest, SplitDoesNotExceedMaximumTicks)
{
    Interactions::Interaction int_decimate {};
    int_decimate.add(make_decimate());

    event_handler.recieve_interaction(int_decimate);

    event_handler._process(0.0);
    for (int i{0}; i < TICK_LIMIT*2; ++i) {
        event_handler._process(TICK_TIME);
    }

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_EQ(hp->get_health(), MAX_HP - DAMAGE_AMOUNT * 10.0);
}

TEST_F(EntityEventHandlerTest, BatchedDoesNotExceedMaximumTicks)
{
    Interactions::Interaction int_decimate {};
    int_decimate.add(make_decimate());

    event_handler.recieve_interaction(int_decimate);
    event_handler._process(TICK_TIME*TICK_LIMIT*10);

    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_EQ(hp->get_health(), MAX_HP - DAMAGE_AMOUNT * 10.0);
}
