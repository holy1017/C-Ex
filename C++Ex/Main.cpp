#include <iostream>

//#include "CBMP.cpp"
//#include "CBMPRW.cpp"
//#include "CbmpMy.cpp"
//#include "Cbmp2.h"
#include "CBMP.cpp"
#include "Cgrp.cpp"


int main(int argc, char** argv) {
	printf("main st\n");

	int w = 1000, h = 500;

	Cgrp* g = new Cgrp(-500, -250, w, h);
	g->reset();
	for (int i = 2; i < 500; i += 7)
	{
		g->circle(0, 0, i);
	}

	CBMP b;
	b.sizeSet(w, h);
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			if(g->arr[x][y])
			b.setPixel2(x,y );
		}
	}
	//for (int i = 0; i <99; i++)
	//{
	//	b.setPixel(i,i);	
	//}
	b.fileSave("Cbmp3.bmp");

	printf("main ed\n");
}