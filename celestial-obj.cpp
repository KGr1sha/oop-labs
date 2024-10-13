#include "celestial-obj.h"
#include <stdexcept>


Star::Star() {
    _coordinates = spherical_coordinates();
    _brightnes = 0;
    _name = "New Star";
}

Star::Star(
    float declination,
    float hour_angle,
    float brightness,
    std::string name
) : _brightnes(brightness), _name(name) {
    setCoordinates(spherical_coordinates(declination, hour_angle));
}

Star::Star(Star &object) {
    _brightnes = object._brightnes;
    _coordinates = object._coordinates;
    _name = object._name;
}

spherical_coordinates Star::getCoordinates() const {
    return _coordinates;
}

float Star::getBrightness() const {
    return _brightnes;
}

std::string Star::getName() const {
    return _name;
}

celestialObjetType Star::getType() const {
    return celestialObjetType::SingleStar;
}

void Star::setBrightness(float brightness) {
    _brightnes = brightness;
}

bool Star::setCoordinates(spherical_coordinates coords) {
    if (coords.declination > 90 || coords.declination < -90\
    || coords.hour_angle < 0 || coords.hour_angle > 360) {
        throw std::invalid_argument("ERROR: argument out of range");
        return false;
    }

    _coordinates = coords;
    return true;
}

void Star::setName(std::string name) {
    _name = name;
}

bool Star::rotate(float angle) {
    if (angle > 360 || angle < -360) {
        throw std::invalid_argument("ERROR: angle shoud be between -360 and 360");
        return false;
    }

    _coordinates.hour_angle += angle;
    if (_coordinates.hour_angle > 360) {
        _coordinates.hour_angle -= 360;
    }
    if (_coordinates.hour_angle < 0) {
        _coordinates.hour_angle += 360;
    }
    return true;
}


StarSystem::StarSystem() : Star() {
    _gravitational_attrraction = 0;
}

StarSystem::StarSystem(
    float declination,
    float hour_angle,
    float brightness,
    std::string name,
    float gravitational_attraction
) : Star(declination, hour_angle, brightness, name) {
    setGravitationalAttraction(gravitational_attraction);
}

StarSystem::StarSystem(StarSystem &other) : Star(other){
    _gravitational_attrraction = other._gravitational_attrraction;
}

bool StarSystem::setGravitationalAttraction(float attraction) {
    if (attraction <= 0) {
        throw std::invalid_argument("ERROR: attraction should be positive");
        return false;
    }
    _gravitational_attrraction = attraction;
    return true;
}

float StarSystem::getGravitationalAttraction() const {
    return _gravitational_attrraction;
}

celestialObjetType StarSystem::getType() const {
    return celestialObjetType::StarSystem;
}
