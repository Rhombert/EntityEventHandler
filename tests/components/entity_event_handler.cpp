#include "components/entity_event_handler.h"
#include "types/types.h"
#include <gtest/gtest.h>

class EntityEventHandlerTest : public testing::Test
{
protected:
    EntityEventHandlerTest() {}

    EntityEventHandler event_handler { 100.0, 1.0 };
};

TEST_F(EntityEventHandlerTest, AbleToRetrieveHp)
{
    auto* hp = event_handler.get_interactable<Types::Interactable::HP>();
    ASSERT_TRUE(dynamic_cast<const Hp*>(hp) != nullptr);
}
