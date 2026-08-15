#include "interactables/move_speed.h"

#include "types/types.h"

using namespace Interactables;

MoveSpeed::MoveSpeed(double value)
    : InteractableState { Types::Interactable::TURN_SPEED }
    , m_base_move_speed { value }
    , m_current_move_speed { value }
{ }

void MoveSpeed::receive_effect(Effects::Effect *effect)
{
    effect -> apply_effect(this);
}

double MoveSpeed::get_move_speed() const { return m_current_move_speed; }
