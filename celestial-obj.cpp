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
        throw std::invalid_argument("Argument out of range");
        return false;
    }

    _coordinates = coords;
    return true;
}

void Star::setName(std::string name) {
    _name = name;
}

bool Star::rotate(float angle) {
    if (angle > 360) {
        throw std::invalid_argument("Argument out of range");
        return false;
    }

    _coordinates.hour_angle += angle;
    if (_coordinates.hour_angle > 360) {
        _coordinates.hour_angle -= 360;
    }
    return true;
}

celestialObjetType StarSystem::getType() const {
    return celestialObjetType::StarSystem;
}
