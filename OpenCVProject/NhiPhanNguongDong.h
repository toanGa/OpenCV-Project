#pragma once
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>

#include<iostream>
using namespace std;
using namespace cv;

void nhiPhanNguongDong(String s) {
	Mat src = imread(s, CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst;
	adaptiveThreshold(src, dst, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 35, 5);
	imshow("anh xam goc", src);
	imshow("anh nhi phan nguong dong", dst);
	waitKey(0);

}
