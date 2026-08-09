#include "entity_event_handler.h"

using namespace godot;

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
