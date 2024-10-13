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

enum celestialObjetType {
    SingleStar,
    StarSystem
};


class Star {
protected:
    std::string _name;
    float _brightnes; 
    spherical_coordinates _coordinates; 
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
    virtual celestialObjetType getType() const;

    bool setCoordinates(spherical_coordinates coords);
    void setBrightness(float brightness);
    void setName(std::string name);

    bool rotate(float angle);
};

class StarSystem : public Star
{
private:
    float _gravitational_attrraction;

public:
    StarSystem();
    StarSystem(
        float declination,
        float hour_angle,
        float brightness,
        std::string name,
        float gravitational_attraction
    );
    StarSystem(StarSystem &other);

    bool setGravitationalAttraction(float attraction);

    float getGravitationalAttraction() const;
    celestialObjetType getType() const override;
};
