#include "entity_event_handler.h"

using namespace godot;

void EntityEventHandler::_bind_methods() {

}

EntityEventHandler::EntityEventHandler() {
    initializePipelines();
}

EntityEventHandler::~EntityEventHandler() {}

void EntityEventHandler::_process(double delta) {
    for (auto& interactable : m_interactables)
    {

    }
}

void EntityEventHandler::initializePipelines() {
}
