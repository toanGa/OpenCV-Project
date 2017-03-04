#include"histogramExam.h"
//#include"canBangHistogramExam.h"
//#include"Canny_TimBienAnhExam.h"
//#include "AddTwoImageExample.h"
//#include "DetectColorExam.h"
//#include "face_and_eyes_detect.h"
//#include "OpenWebcome.h"
//#include "OpenVideo.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "openImage.h"
//#include "anhXam.h"
#include "nhiPhanNguongDong.h"
//#include "rotImage.h"
//#include "slideImage.h"
#include "myHistogram.h"
//#include "filter.h"

#define maxa(a,b) (a < b ? b : a)
using namespace cv;
using namespace std;

template <typename t>
inline t max(t &a, t &b) {
	return a < b ? b : a;
}
int _main()
{
	double m[3][3] = {
		{ -1, -1, 0 },
		{ -1, 0, 1 },
		{ 0, 1, 1 }
	};

	cout << m[1][0] << endl;
	cout << max(1, 2) << endl << maxa(2.2, 3.3);
	//proccess();
	string path = "C:/Users/toan/Pictures/cc1101.png";
	histogram myHis(path);
	//myHis.showRootImage();
	myHis.CalcImageHist();

	//myHis.CalcImageHist();
	//nhiPhanNguongDong("C:/Users/toan/Pictures/cc1101.png");
	//proccess();
	//slideImage("C:/Users/toan/Pictures/cc1101.png", 45.0, 1.2);
	//filter f;
	//f.sobel("C:/Users/toan/Pictures/cc1101.png");

	waitKey(0);
	return 0;
}

