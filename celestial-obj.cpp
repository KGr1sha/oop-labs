#include "celestial-obj.h"
#include <iostream>
#include "assert.h"


Star::Star() {
    _coordinates = spherical_coordinates();
    _brightnes = 0;
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

void Star::setBrightness(float brightness) {
    _brightnes = brightness;
}

void Star::setCoordinates(spherical_coordinates coords) {
    assert(coords.declination <= 90 && coords.declination >= -90); 
    assert(coords.hour_angle >= 0 && coords.hour_angle <= 360);
    _coordinates = coords;
}

void Star::setName(std::string name) {
    _name = name;
}

void Star::rotate(float angle) {
    assert(angle <= 360);
    _coordinates.hour_angle += angle;
    if (_coordinates.hour_angle > 360) {
        _coordinates.hour_angle -= 360;
    }
}

void Star::printInfo() const {
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Coordinates:" << std::endl;
    std::cout << "Declination: " << _coordinates.declination << std::endl;
    std::cout << "Hour angle: " << _coordinates.hour_angle << std::endl;
    std::cout << std::endl << "Brightness: " << _brightnes << std::endl;
}
