/*
Rohan Cheeniyil
u0914584
CS3505-Fall

Spiral Header
*/
#include <iostream>
#include <string.h>
#include <spiral.h>
#include <HaruPDF.h>

int main(int argc, char **argv)
{
	//        x    y    r  angle
	Spiral s(210, 300, 50, 90);

	if(argc > 1) //checks if there's a valid number of arguments
	{			 //Segmentation fault if this does not happen.
		HaruPDF h("Courier-Bold", 20.0);
		char* printable = argv[1]; //gets the first arg print letters
		for(int i = 0; i < strlen(printable); i++) //cycle through each char and print
		{
			char buf[2];

			h.printCharacter(printable[i], s.getTextX(), s.getTextY(), s.getTextAngle());
			
			s++;
		} 
		h.save("spiralPDF"); //save the file
	} else
	{
		std::cout<<"Error no text to print" << std::endl; //throw an error if there's no text
	}
}