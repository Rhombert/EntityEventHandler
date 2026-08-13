#include "components/entity_event_handler.h"
#include "components/interaction.h"
#include "effects/damage.h"
#include "types/types.h"
#include <gtest/gtest.h>

class EntityEventHandlerTest : public testing::Test
{
protected:
    EntityEventHandlerTest() {}

    EntityEventHandler event_handler { 100.0, 1.0 };
    Modifiers::Modifier mod_decimate {
        new Effects::Damage { 1.0 },
        0.2,
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
    ASSERT_LT(hp->get_health(), 100.0);
}
