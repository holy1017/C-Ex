#include <iostream>

//#include "CBMP.cpp"
//#include "CBMPRW.cpp"
//#include "CbmpMy.cpp"
//#include "Cbmp2.h"
#include "CBMP.cpp"


int main(int argc, char** argv) {
	printf("main st\n");

	//CBMPRW crw;
	//crw.test();

	//CbmpMy c;
	//c.sizeSet(100,100);
	//c.fileSave("CbmpMy.bmp");
	//Cbmp2 c;
	//c.test();

	CBMP c;
	c.sizeSet(100, 100);
	for (int i = 0; i <99; i++)
	{
		c.setPixel(i,i);	
	}
	c.fileSave("Cbmp3.bmp");

	printf("main ed\n");
}