#pragma once


#include <windows.h>
#include <cstdio>

// typedef    unsigned short    WORD;  //2바이트
// typedef    unsigned long     DWORD; //4바이트
// typedef    long              LONG;  // long 은 운영체제에따라서 크기 다름


// typedef struct tagBITMAPFILEHEADER {
//     WORD       bfType; // 'BM' 비트맵 의미
//     DWORD      bfSize;	   // 파일 크기
//     WORD       bfReserved1; // 미사용. 기본값 0
//     WORD       bfReserved2; // 미사용. 기본값 0
//     DWORD      bfOffBits;   // BITMAPFILEHEADER 구조체의 시작 위치부터 실제 픽셀 데이터 정보를 담고 있는 비트맵 비트까지의 바이트 오프셋을 나타낸다. 
							   // 즉, [BITMAPFILEHEADER 크기 + BITMAPINFOHEADER 크기 + 색상 테이블 크기]와 같다.
// } BITMAPFILEHEADER, FAR* LPBITMAPFILEHEADER, * PBITMAPFILEHEADER;


// typedef struct tagBITMAPINFOHEADER {
//     DWORD biSize;
//     LONG biWidth;                    //비트맵의 가로 크기를 픽셀 단위로 나타낸다
//     LONG biHeight;                   // 비트맵의 세로 크기를 픽셀 단위로 나타낸다. 
										// 이 값이 양수이면 픽셀 데이터는 상하가 뒤집힌 상태(buttom-up)로 저장되며, 
										// 음수이면 정상적인 상태(top-down)로 저장된다. 
										// 일반적으로 biHeight는 양수로 저장되며, 
										// 픽셀 데이터는 상하가 뒤집힌 상태로 저장된다.
//     WORD biPlanes;                   // 비트맵을 화면 등에 보여줄 때 필요한 플레인 수를 나타내며, 항상 1이다.
//     WORD biBitCount;                 // 픽셀 하나를 표현하기 위해 필요한 비트 수를 나타낸다. 1, 4, 8, 16, 24, 32의 값을 가질 수 있다. 
										// 이 값이 8이면 28 = 256색을 표현할 수 있고, 
										// 24이면 224 = 16,777,216색(트루컬러)을 표현할 수 있다.
//     DWORD biCompression;             // 압축 유형을 나타낸다. 일반적으로 BMP 파일은 압축을 하지 않음을 나타내는 BI_RGB 값을 가진다.
//     DWORD biSizeImage;               // DIB 구조에서 픽셀 데이터를 저장하는 데 필요한 메모리 공간의 크기를 나타낸다. 
										// 만약 비트맵 영상의 가로 크기가 4의 배수가 아니면 4의 배수에 맞게 여분의 바이트가 추가되어 계산된다. 
										// biCompression이 BI_RGB인 경우, 이 값은 0의 값을 가질 수도 있다.
//     LONG biXPelsPerMeter;            // 가로 방향으로 미터당 픽셀 수를 나타낸다. 그림판 기본값:3780
//     LONG biYPelsPerMeter;            // 세로 방향으로 미터당 픽셀 수를 나타낸다.
//     DWORD biClrUsed;                 // 색상 테이블에서 실제 사용되는 색상 수를 나타낸다. 
										// 이 값이 0이면, biBitCount에서 지정한 색상수를 모두 사용하는 것을 나타낸다. 
										// 0이 아니면, RGBQUAD 구조체 배열의 크기를 지정한다. 
										// 일반적으로 0이다.
//     DWORD biClrImportant;            // 비트맵을 화면에 표현하기 위해 필요한 색상 인덱스의 수를 나타낸다. 
										// 0이면 모든 색상이 필요함을 나타내며, 일반적으로 0이다.
// } BITMAPINFOHEADER, FAR* LPBITMAPINFOHEADER, * PBITMAPINFOHEADER;

// typedef struct tagBITMAPINFO {
//     BITMAPINFOHEADER    bmiHeader;
//     RGBQUAD             bmiColors[1];
// } BITMAPINFO, FAR* LPBITMAPINFO, * PBITMAPINFO;

class CBMP
{
public:
	typedef struct tagRGB {
		BYTE    Blue = 0; // 반드시 초기화 필요. 안그럼 2바이크가 들어감...
		BYTE    Green = 0;//
		BYTE    Red = 0;
	} RGB;

	int bit = 8;

	BITMAPINFOHEADER bih; // 이미지 정보 헤더 정보 저장할 포인터
	BITMAPFILEHEADER bfh; // 파일 시작 해더

	FILE* fp = nullptr;

	DWORD ws; // 가로 메모리 크기
	DWORD ds; // 메모리 크기

	//RGB** pData;// RGB 데이터를 저장할 버퍼 포인터
	//BYTE* pData;// RGB 데이터를 저장할 버퍼 포인터
	RGB* pData;// RGB 데이터를 저장할 버퍼 포인터

	RGB rgb_wt = { 255,255,255 };
	RGB rgb_red = { 0,0,255 };
	RGB rgb_gre = { 0,255,0 };
	RGB rgb_blu = { 255,0,0 };
	RGB rgb_lbl = { 255,255,0 };
	RGB rgb_pup = { 255,0,255 };
	RGB rgb_yel = { 0,255,255 };


	CBMP() {
		bih.biSize = sizeof(BITMAPINFOHEADER); // 헤더 크기 저장
		bih.biWidth = 100;
		bih.biHeight = 100;
		bih.biPlanes = 1;
		bih.biBitCount = sizeof(RGB) * bit;
		printf("RGB:%u\n", sizeof(RGB));
		bih.biCompression = BI_RGB;
		bih.biSizeImage = 0;
		bih.biXPelsPerMeter = 0;
		bih.biYPelsPerMeter = 0;
		bih.biClrUsed = 0;
		bih.biClrImportant = 0;


		bfh.bfType = *(WORD*)"BM";
		//bfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
		bfh.bfReserved1 = 0;
		bfh.bfReserved2 = 0;
		bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	}

	// 사이즈 설정
	void sizeSet(int width, int height) {

		/* 메모리 해제 */
		//for (int i = 0; i < height; ++i) {
		//	delete[] pData[i];
		//} 
		delete[] pData;

		bih.biWidth = width;
		bih.biHeight = height;

		//bih.biSizeImage = (DWORD)((width * bih.biBitCount / 8 + 3) & ~3) * height;
		//bih.biSizeImage = (DWORD)((width * bih.biBitCount / 8 + 3) & ~3) * height;
		bih.biSizeImage = bih.biWidth * bih.biHeight * sizeof(RGB);
		printf("bih.biSizeImage:%lu\n", bih.biSizeImage);

		bfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bih.biSizeImage;
		printf("bfh.bfSize:%lu\n", bfh.bfSize);

		//pData = new BYTE[bih.biSizeImage];
		pData = new RGB[bih.biWidth * bih.biHeight];
		//pData = new RGB[bih.biWidth][bih.biHeight];
		//int** arr = new int* [height];
		//for (int i = 0; i < height; ++i) {
		//	arr[i] = new int[width];
		//	//memset(arr[i], 0, sizeof(int) * width); // 메모리 공간을 0으로 초기화 
		//}

	}

	void setPixel(int x, int y) {
		 setPixel(x, y, rgb_wt);
	}
	void setPixel2(int x, int y) {
		setPixel2(x, y, rgb_wt);
	}
	void setPixel(int x, int y, RGB rgb) {
		pData[bih.biWidth*(bih.biHeight - y - 1)+x]=rgb;
		//pData[bih.biWidth*y+x]=rgb;
	}

	void setPixel2(int x, int y, RGB rgb) {
		//pData[bih.biWidth * (bih.biHeight - y - 1) + x] = rgb;
		pData[bih.biWidth*y+x]=rgb;
	}

	// 파일 저장
	bool fileSave(const char* filename) {

		// 파일 열기
		fopen_s(&fp, filename, "wb");
		if (nullptr == fp)
		{
			//LOG_OUT_A("fopen() error");
			printf("파일 만들기 실패");
			return false;
		}

		// 생성 후 헤더 및 데이터 쓰기.

		fwrite(&bfh, 1, sizeof(BITMAPFILEHEADER), fp);
		printf("BITMAPFILEHEADER:%u\n", sizeof(BITMAPFILEHEADER));

		fwrite(&bih, 1, sizeof(BITMAPINFOHEADER), fp);
		printf("BITMAPFILEHEADER:%u\n", sizeof(BITMAPINFOHEADER));

		fwrite(pData, 1, bih.biSizeImage, fp);
		printf("pData:%u\n", sizeof(pData));

		fclose(fp);
		return true;
	}
};

