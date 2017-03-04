#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("F:/anh/Camera/1.jpg", CV_LOAD_IMAGE_COLOR);
	Mat hsv, disp;
	cvtColor(src, hsv, CV_BGR2HSV);
	vector<Mat> hsv_channels;

	split(hsv, hsv_channels);
	equalizeHist(hsv_channels[2], hsv_channels[2]);
	merge(hsv_channels, hsv);
	cvtColor(hsv, disp, CV_HSV2BGR);
	imshow("anh goc", src);
	imshow("anh sau khi can bang histogram", disp);
	waitKey(0);
}