/*
Rohan Cheeniyil
u0914584
CS3505-Fall

Spiral 
*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <spiral.h>
    
    //initialize spiral and set min/max radius
    Spiral::Spiral( double initialX, double initialY, double initialRadius, double initialAngle) : centerX(initialX), centerY(initialY), radius(initialRadius), angle(-initialAngle+90)
    {
        if(radius > 300 || radius < 40)
            radius=80;
    }

    Spiral:: ~Spiral()
    {
    }

    //code for << operator
    std::ostream& operator<<(std::ostream& out, const Spiral& s)
    {
        out << "X: " << s.x << " Y: " << s.y << " at " << std::fixed << std::setw(11) << s.angle;
        return out;    
    }


    //implementation of ++s and s++ operators
    Spiral& Spiral::operator++()
    {
        calculateNext();
        return *this;
    }

    Spiral Spiral::operator++(int)
    {
        Spiral temp = *this;
        calculateNext();
        return temp;
    }

    //getters
    double Spiral::getTextX()
    {
        float rad2 = getRadians(getSpiralAngle());
        return centerX +  cos(getRadians(getSpiralAngle())) *  (radius+(step)/2);
    }

    double Spiral::getTextY()
    {
        float rad2 = getRadians(getSpiralAngle());
        return centerY +  sin(getRadians(getSpiralAngle())) *  (radius+(step)/2);
    } 

    double Spiral::getRadians(double input_angle)
    {
        return (input_angle) / 180 * M_PI;
    }

    double Spiral::getSpiralAngle()
    {
        return angle;
    }
    double Spiral::getTextAngle()
    {
        //cout<<getRadians()<<endl;
        return (angle - 90);
    }

    //called by the ++ operator to update
    void Spiral::calculateNext()
    {
        float rad2 = getRadians(getSpiralAngle());

        x = getTextX();
        y = getTextY();
        step++;
        angle-= 13+(rad2/3);
    }