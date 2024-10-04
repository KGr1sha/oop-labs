#include <vector>


struct spherical_coordinates {
    float hour_angle; // часовой угол
    float declination; // склонение
    
    spherical_coordinates() {
        declination = 0;
        hour_angle = 0;
    }
    
    spherical_coordinates(
        float declination,
        float hour_angle
    ) {
        this->declination = declination;     
        this->hour_angle = hour_angle;     
    }
};


class Star {
public:
    Star();
    Star(
        float declination,
        float hour_angle,
        float brightness
    );
    Star(Star &object);

    void printInfo() const;
    spherical_coordinates getCoordinates() const;
    float getBrightness() const;
    void rotate(float angle);
private:
    float _brightnes; 
    spherical_coordinates _coordinates; 
};

class StarSystem {
public:
    StarSystem(std::vector<Star> &stars);
    std::vector<Star> getStars();
private:
    std::vector<Star> _stars;
};
