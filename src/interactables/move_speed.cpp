#include "interactables/move_speed.h"

#include "types/types.h"

using namespace Interactables;

MoveSpeed::MoveSpeed(double base_move_speed)
    : InteractableState { Types::Interactable::TURN_SPEED, base_move_speed }
{ }

void MoveSpeed::receive_effect(Effects::Effect *effect)
{
    effect -> apply_effect(this);
}

double MoveSpeed::get_move_speed() const 
{ 
    return get_current_value(); 
}
