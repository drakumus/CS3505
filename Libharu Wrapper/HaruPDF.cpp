/*
Rohan Cheeniyil
u0914584
CS3505-Fall

HaruPDF Class
*/

#include "hpdf.h"
#include <math.h> 
#include <HaruPDF.h>
#include <string.h>

HaruPDF::HaruPDF(const char* fontName, double fontSize)
{
	//set up libharu for use
    pdf = HPDF_New (NULL, NULL);
    
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
    HPDF_Page_BeginText (page);//*******
    font = HPDF_GetFont (pdf, fontName, NULL);
    HPDF_Page_SetFontAndSize (page, font, fontSize);
}

//prints a character using libharu functions
void HaruPDF::printCharacter (const char c, double x, double y, double angle)
{
	char buf[2];
	float rad1 = angle/180 * M_PI;
	HPDF_Page_SetTextMatrix(page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1), x, y);

	buf[0] = c;
	buf[1] = 0;
	HPDF_Page_ShowText (page, buf);
}

//save file
void HaruPDF::save(const char* fileName)
{
	char file[256];
	strcpy(file,fileName);	
	strcat(file, ".pdf");
    HPDF_Page_EndText (page);
    HPDF_SaveToFile (pdf, "spiralPDF.pdf");
}
//deconstruct and free resource
HaruPDF::~HaruPDF()
{

	HPDF_Free(pdf);
}