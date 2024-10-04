#include "celestial-obj.h"
#include <iostream>


Star::Star() {
    _coordinates = spherical_coordinates();
    _brightnes = 0;
}

Star::Star(
    float declination,
    float hour_angle,
    float brightness
) : _brightnes(brightness) {
    _coordinates = spherical_coordinates(declination, hour_angle);
}

Star::Star(Star &object) {
    _brightnes = object._brightnes;
    _coordinates = object._coordinates;
}

void Star::printInfo() const {
    std::cout << "Coordinates:" << std::endl;
    std::cout << "Declination: " << _coordinates.declination << std::endl;
    std::cout << "Hour angle: " << _coordinates.hour_angle << std::endl;
    std::cout << std::endl << "Brightness: " << _brightnes << std::endl;
}

void Star::rotate(float angle) {
    _coordinates.hour_angle += angle;
}

spherical_coordinates Star::getCoordinates() const {
    return _coordinates;
}

float Star::getBrightness() const {
    return _brightnes;
}
