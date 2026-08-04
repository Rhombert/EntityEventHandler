#include <algorithm>

#include "godot_cpp/core/class_db.hpp"

#include "interactables/hp.h"

using namespace godot;

Ref<Hp> Hp::create(double value) 
{
    Ref<Hp> ref { memnew(Hp { value }) };
    return ref;
}

void Hp::heal(double amount)
{
    m_current_health = std::min(m_current_health+amount, m_max_health);
}

void Hp::damage(double amount)
{
    m_current_health = std::max(m_current_health-amount, 0.0);
}

void Hp::_bind_methods()
{
    ClassDB::bind_static_method(
                         "Hp",
                         D_METHOD("test"),
                         &Hp::test);
    ClassDB::bind_static_method(
                         "Hp",
                         D_METHOD("create", "value"),
                         &Hp::create);
    ClassDB::bind_method(D_METHOD("heal", "amount"),
                         &Hp::heal);
    ClassDB::bind_method(D_METHOD("damage", "amount"),
                         &Hp::damage);
    ClassDB::bind_method(D_METHOD("get_health"),
                         &Hp::get_health);
    ClassDB::bind_method(D_METHOD("get_max_health"),
                         &Hp::get_max_health);
}
