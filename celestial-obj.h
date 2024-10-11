#include "string"

struct spherical_coordinates {
    float declination; // склонение
    float hour_angle; // часовой угол
    
    spherical_coordinates(
        float declination = 0,
        float hour_angle = 0
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
        float brightness,
        std::string name
    );
    Star(Star &object);

    spherical_coordinates getCoordinates() const;
    float getBrightness() const;
    std::string getName() const;

    void setCoordinates(spherical_coordinates coords);
    void setBrightness(float brightness);
    void setName(std::string name);

    void rotate(float angle);
    void printInfo() const;
private:
    std::string _name;
    float _brightnes; 
    spherical_coordinates _coordinates; 
};
