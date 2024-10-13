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


int main() {
    //testing default constructor
    Star star_default;
    assert(star_default.getName() == "New Star");
    assert(star_default.getBrightness() == 0);
    spherical_coordinates cords = star_default.getCoordinates();
    assert(cords.declination == 0 && cords.hour_angle == 0);
    //testing init contructor
    Star star1(45, 90, 1, "Star1");
    assert(star1.getName() == "Star1");
    assert(star1.getBrightness() == 1);
    cords = star1.getCoordinates();
    assert(cords.declination == 45 && cords.hour_angle == 90);
    //testing copy contructor
    Star star2(star1);
    assert(star2.getName() == "Star1");
    assert(star2.getBrightness() == 1);
    cords = star2.getCoordinates();
    assert(cords.declination == 45 && cords.hour_angle == 90);

    //testing setters
    star2.setName("Star2");
    assert(star2.getName() == "Star2");
    star2.setBrightness(3);
    assert(star2.getBrightness() == 3);
    cords = spherical_coordinates(90, 500);
    try {
        star2.setCoordinates(cords);
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << "(intended)" << std::endl; 
    }
    cords = star2.getCoordinates();
    assert(cords.declination == 45 && cords.hour_angle == 90);

    cords = spherical_coordinates(30, 330);
    star2.setCoordinates(cords);
    cords = star2.getCoordinates();
    assert(cords.declination == 30 && cords.hour_angle == 330);
    //testing rotate method
    try {
        star2.rotate(370);
    } catch(std::invalid_argument &e) {
        std::cerr << e.what() << "(intended)" << std::endl;
    }
    assert(star2.getCoordinates().hour_angle == 330);
    star2.rotate(30);
    assert(star2.getCoordinates().hour_angle == 360);

    std::cout << "All tests passed" << std::endl;
    return 0;
}
