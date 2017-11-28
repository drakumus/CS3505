/*
Rohan Cheeniyil
u0914584
CS3505-Fall

Spiral Header
*/

class Spiral
{
private:
	int step;
    double centerX, centerY;
    double x, y, radius, angle;
    void calculateNext();

public:
	Spiral( double initialX, double initialY, double initialRadius, double initialAngle);
    ~Spiral();
        double getRadians(double angle_input);
    double getTextX();
    double getTextY();
    double getSpiralAngle();
    double getTextAngle();
    Spiral& operator++();
    Spiral operator++(int);
    friend std::ostream& operator<<(std::ostream& out, const Spiral& s);
};