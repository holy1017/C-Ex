#pragma once


#include <windows.h>
#include <cstdio>

// typedef    unsigned short    WORD;  //2����Ʈ
// typedef    unsigned long     DWORD; //4����Ʈ
// typedef    long              LONG;  // long �� �ü�������� ũ�� �ٸ�


// typedef struct tagBITMAPFILEHEADER {
//     WORD       bfType; // 'BM' ��Ʈ�� �ǹ�
//     DWORD      bfSize;	   // ���� ũ��
//     WORD       bfReserved1; // �̻��. �⺻�� 0
//     WORD       bfReserved2; // �̻��. �⺻�� 0
//     DWORD      bfOffBits;   // BITMAPFILEHEADER ����ü�� ���� ��ġ���� ���� �ȼ� ������ ������ ��� �ִ� ��Ʈ�� ��Ʈ������ ����Ʈ �������� ��Ÿ����. 
							   // ��, [BITMAPFILEHEADER ũ�� + BITMAPINFOHEADER ũ�� + ���� ���̺� ũ��]�� ����.
// } BITMAPFILEHEADER, FAR* LPBITMAPFILEHEADER, * PBITMAPFILEHEADER;


// typedef struct tagBITMAPINFOHEADER {
//     DWORD biSize;
//     LONG biWidth;                    //��Ʈ���� ���� ũ�⸦ �ȼ� ������ ��Ÿ����
//     LONG biHeight;                   // ��Ʈ���� ���� ũ�⸦ �ȼ� ������ ��Ÿ����. 
										// �� ���� ����̸� �ȼ� �����ʹ� ���ϰ� ������ ����(buttom-up)�� ����Ǹ�, 
										// �����̸� �������� ����(top-down)�� ����ȴ�. 
										// �Ϲ������� biHeight�� ����� ����Ǹ�, 
										// �ȼ� �����ʹ� ���ϰ� ������ ���·� ����ȴ�.
//     WORD biPlanes;                   // ��Ʈ���� ȭ�� � ������ �� �ʿ��� �÷��� ���� ��Ÿ����, �׻� 1�̴�.
//     WORD biBitCount;                 // �ȼ� �ϳ��� ǥ���ϱ� ���� �ʿ��� ��Ʈ ���� ��Ÿ����. 1, 4, 8, 16, 24, 32�� ���� ���� �� �ִ�. 
										// �� ���� 8�̸� 28 = 256���� ǥ���� �� �ְ�, 
										// 24�̸� 224 = 16,777,216��(Ʈ���÷�)�� ǥ���� �� �ִ�.
//     DWORD biCompression;             // ���� ������ ��Ÿ����. �Ϲ������� BMP ������ ������ ���� ������ ��Ÿ���� BI_RGB ���� ������.
//     DWORD biSizeImage;               // DIB �������� �ȼ� �����͸� �����ϴ� �� �ʿ��� �޸� ������ ũ�⸦ ��Ÿ����. 
										// ���� ��Ʈ�� ������ ���� ũ�Ⱑ 4�� ����� �ƴϸ� 4�� ����� �°� ������ ����Ʈ�� �߰��Ǿ� ���ȴ�. 
										// biCompression�� BI_RGB�� ���, �� ���� 0�� ���� ���� ���� �ִ�.
//     LONG biXPelsPerMeter;            // ���� �������� ���ʹ� �ȼ� ���� ��Ÿ����. �׸��� �⺻��:3780
//     LONG biYPelsPerMeter;            // ���� �������� ���ʹ� �ȼ� ���� ��Ÿ����.
//     DWORD biClrUsed;                 // ���� ���̺��� ���� ���Ǵ� ���� ���� ��Ÿ����. 
										// �� ���� 0�̸�, biBitCount���� ������ ������� ��� ����ϴ� ���� ��Ÿ����. 
										// 0�� �ƴϸ�, RGBQUAD ����ü �迭�� ũ�⸦ �����Ѵ�. 
										// �Ϲ������� 0�̴�.
//     DWORD biClrImportant;            // ��Ʈ���� ȭ�鿡 ǥ���ϱ� ���� �ʿ��� ���� �ε����� ���� ��Ÿ����. 
										// 0�̸� ��� ������ �ʿ����� ��Ÿ����, �Ϲ������� 0�̴�.
// } BITMAPINFOHEADER, FAR* LPBITMAPINFOHEADER, * PBITMAPINFOHEADER;

// typedef struct tagBITMAPINFO {
//     BITMAPINFOHEADER    bmiHeader;
//     RGBQUAD             bmiColors[1];
// } BITMAPINFO, FAR* LPBITMAPINFO, * PBITMAPINFO;

class CBMP
{
public:
	typedef struct tagRGB {
		BYTE    Blue = 0; // �ݵ�� �ʱ�ȭ �ʿ�. �ȱ׷� 2����ũ�� ��...
		BYTE    Green = 0;//
		BYTE    Red = 0;
	} RGB;

	int bit = 8;

	BITMAPINFOHEADER bih; // �̹��� ���� ��� ���� ������ ������
	BITMAPFILEHEADER bfh; // ���� ���� �ش�

	FILE* fp = nullptr;

	DWORD ws; // ���� �޸� ũ��
	DWORD ds; // �޸� ũ��

	//RGB** pData;// RGB �����͸� ������ ���� ������
	//BYTE* pData;// RGB �����͸� ������ ���� ������
	RGB* pData;// RGB �����͸� ������ ���� ������

	RGB rgb_wt = { 255,255,255 };
	RGB rgb_red = { 0,0,255 };
	RGB rgb_gre = { 0,255,0 };
	RGB rgb_blu = { 255,0,0 };
	RGB rgb_lbl = { 255,255,0 };
	RGB rgb_pup = { 255,0,255 };
	RGB rgb_yel = { 0,255,255 };


	CBMP() {
		bih.biSize = sizeof(BITMAPINFOHEADER); // ��� ũ�� ����
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

	// ������ ����
	void sizeSet(int width, int height) {

		/* �޸� ���� */
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
		//	//memset(arr[i], 0, sizeof(int) * width); // �޸� ������ 0���� �ʱ�ȭ 
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

	// ���� ����
	bool fileSave(const char* filename) {

		// ���� ����
		fopen_s(&fp, filename, "wb");
		if (nullptr == fp)
		{
			//LOG_OUT_A("fopen() error");
			printf("���� ����� ����");
			return false;
		}

		// ���� �� ��� �� ������ ����.

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

