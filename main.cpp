/*
Блогер Боря пытается сочетать увлечение астрономией
с тягой к путешествиям. Пока пожертвований
подписчиков не хватает на билет,
он пытается представить, как выглядит звёздное небо
в различных точках земного шара. Для этого Боре
нужна программа, которая позволяет составить
карту звёздного неба, поворачивать её 
(с поправкой на долготу) и отфильтровывать наименее яркие объекты
(с поправкой на световое загрязнение крупных городов).

1. Небесное тело: небесные координаты;
видимая звёздная величина.

2. Система: несколько небесных тел,
связанных гравитационно.

3. Карта звёздного неба 
(массив звёзд и других небесных тел),
класс которой включает следующие методы:
1) метод, принимающий значение угла
и возвращающий копию карты звёздного неба,
повёрнутую на заданный угол;
2) метод, принимающий значение звёздной величины
и возвращающий копию карты звёздного неба,
в которой присутствуют только объекты 
со звёздной величиной не меньше заданной.
*/

#include "celestial-obj.h"
#include "assert.h"
#include <iostream>
#include <stdexcept>

void testStarForDefaultValues(Star &star) {
    assert(star.getName() == "New Star");
    assert(star.getBrightness() == 0);
    spherical_coordinates cords = star.getCoordinates();
    assert(cords.declination == 0 && cords.hour_angle == 0);
}

Star testStarConstructors() {
    //testing default constructor
    Star star_default;
    testStarForDefaultValues(star_default);    
    //testing init contructor
    Star star1(45, 90, 1, "Star1");
    assert(star1.getName() == "Star1");
    assert(star1.getBrightness() == 1);
    spherical_coordinates cords = star1.getCoordinates();
    assert(cords.declination == 45 && cords.hour_angle == 90);
    //testing copy contructor
    Star star2(star1);
    assert(star2.getName() == "Star1");
    assert(star2.getBrightness() == 1);
    cords = star2.getCoordinates();
    assert(cords.declination == 45 && cords.hour_angle == 90);
    return star2;
}


void testStarSetters(Star &star) {
    spherical_coordinates initialCords = star.getCoordinates();
    spherical_coordinates cords;
    star.setName("Star2");
    assert(star.getName() == "Star2");
    star.setBrightness(3);
    assert(star.getBrightness() == 3);
    cords = spherical_coordinates(90, 500);
    try {
        star.setCoordinates(cords);
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << "(intended)" << std::endl; 
    }
    cords = star.getCoordinates();
    assert(
        cords.hour_angle == initialCords.hour_angle\
        && cords.declination == initialCords.declination
    );

    cords = spherical_coordinates(30, 330);
    star.setCoordinates(cords);
    cords = star.getCoordinates();
    assert(cords.declination == 30 && cords.hour_angle == 330);
}

void testRotate(Star &star) {
    spherical_coordinates cords(30, 330);
    star.setCoordinates(cords);
    try {
        star.rotate(370);
    } catch(std::invalid_argument &e) {
        std::cerr << e.what() << "(intended)" << std::endl;
    }
    star.rotate(30);
    assert(star.getCoordinates().hour_angle == 360);
}


void testSystemForDefaultValuse(class StarSystem &system) {
    testStarForDefaultValues(system);
    assert(system.getGravitationalAttraction() == 0);
}


int main() {
    Star star = testStarConstructors();
    testStarSetters(star);
    testRotate(star);
    assert(star.getType() == celestialObjetType::SingleStar);
    std::cout << "Lab1 tests passed" << std::endl;

    //testing defaulst constructor
    class StarSystem system_default;
    testSystemForDefaultValuse(system_default);
    //testing init constructor
    class StarSystem system1(45, 90, 1, "system1", 10);
    assert(system1.getGravitationalAttraction() == 10);

    try {
        system1.setGravitationalAttraction(-1);
    } catch(std::invalid_argument &e){
        std::cerr << e.what() << "(intended)" << std::endl;
    }

    system1.setGravitationalAttraction(1);
    assert(system1.getGravitationalAttraction() == 1);

    assert(system1.getType() == celestialObjetType::StarSystem);
    std::cout << "Lab2 tests passed" << std::endl;
    
    return 0;
}
