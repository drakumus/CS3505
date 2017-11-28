/*
Rohan Cheeniyil
u0914584
CS3505-Fall

HaruPDF Header
*/

#include "hpdf.h"

class HaruPDF
{
private: 
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;
    const char* fileName;


public:
    HaruPDF(const char* fontName, double fontSize);
    ~HaruPDF();
    void printCharacter (const char c, double textX, double textY, double textAngle);
    void save(const char* fileName);
};