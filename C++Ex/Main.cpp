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

	//for (int i = 0; i < 100; i++)
	//{
	//	printf("%f \n", ((double)rand() / RAND_MAX * 256));
	//	printf("%d \n", (int)((double)rand() / RAND_MAX * 256));
	//}

	srand((unsigned int)time(NULL));//난수 처리


	int w = 1600, h = 900;

	Cgrp* g = new Cgrp(-w/2, -h/2, w, h);
	g->reset();
	for (int i = 0; i < w/2; i += (int)((double)rand() / RAND_MAX * 50 + 1))
	{
		g->circle(0, 0, i);
	}
	   
	g->line(-w / 3, -h / 3, w / 3, h / 3);
	g->line(-w / 3, h / 3, w / 3, -h / 3);

	g->line(-h / 3, -w / 3, h / 3,  w / 3);
	g->line(-h / 3,  w / 3, h / 3, -w / 3);

	g->line(w / 2,  h / 3, -w / 2, -h / 3);

	CBMP b;
	b.sizeSet(w, h);
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			if (g->arr[x][y]) {
				b.setPixel2(x, y, {
					(BYTE)((double)rand() / RAND_MAX * 64+128+ 64)
					, (BYTE)((double)rand() / RAND_MAX * 64 + 128 + 64)
					, (BYTE)((double)rand() / RAND_MAX * 64 + 128 + 64)
					}
				);
				//b.setPixel2(x, y, {0,0,255 });
			}
			else {
				b.setPixel2(x, y, {
					(BYTE)((double)rand() / RAND_MAX * 64)
					,(BYTE)((double)rand() / RAND_MAX * 64)
					,(BYTE)((double)rand() / RAND_MAX * 64)
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