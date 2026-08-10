#include <algorithm>

#include "interactables/hp.h"

using namespace Interactables;

void Hp::heal(double amount)
{
    m_current_health = std::min(m_current_health+amount, m_max_health);
}

void Hp::damage(double amount)
{
    m_current_health = std::max(m_current_health-amount, 0.0);
}
