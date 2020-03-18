#include <iostream>
#include <cstdlib> // for std::rand() and std::srand()
//출처: https://boycoding.tistory.com/192 [소년코딩]

//#include "CBMP.cpp"
//#include "CBMPRW.cpp"
//#include "CbmpMy.cpp"
//#include "Cbmp2.h"
#include "CBMP.cpp"
#include "Cgrp.cpp"
#include <time.h>


int main(int argc, char** argv) {
	printf("main st\n" );

	for (int i = 0; i < 100; i++)
	{
		printf("%f \n", ((double)rand() / RAND_MAX * 256));
		printf("%d \n", (int)((double)rand() / RAND_MAX * 256));
	}

	srand((unsigned int)time(NULL));//난수 처리


	int w = 1000, h = 500;

	Cgrp* g = new Cgrp(-500, -250, w, h);
	g->reset();
	for (int i = 2; i < 500; i += 7)
	{
		g->circle(0, 0, i);
	}
	   
	g->line(-400,-200,400,200);

	CBMP b;
	b.sizeSet(w, h);
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			if (g->arr[x][y]) {
				b.setPixel2(x, y, {
					(BYTE)((double)rand() / RAND_MAX * 256)
					,(BYTE)((double)rand() / RAND_MAX * 256)
					,(BYTE)((double)rand() / RAND_MAX * 256)
					}
				);
			}
			//		출처: https://gabble-workers.tistory.com/6 [게임공작소]
		}
	}
	//for (int i = 0; i <99; i++)
	//{
	//	b.setPixel(i,i);	
	//}
	b.fileSave("_test.bmp");

	printf("main ed\n");
}