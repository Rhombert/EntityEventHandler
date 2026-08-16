#include "interactables/turn_speed.h"

using namespace Interactables;

void TurnSpeed::receive_effect(Effects::Effect *effect)
{
    effect -> apply_effect(this);
}

double TurnSpeed::get_turn_speed() const { return get_current_value(); }
