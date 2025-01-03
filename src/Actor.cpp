#include "Actors/Actor.hpp"
Actor::Actor() {
    this->instanceName = "ACTOR";
}
bn::string<32> Actor::getInstanceName() {
    return this->instanceName;
}