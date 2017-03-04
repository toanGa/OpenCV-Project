#pragma once
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;
	// open the default camera, use something different from 0 otherwise;
	// Check VideoCapture documentation.
	String face_cascade_name = "haarcascade_frontalface_alt.xml";
	CascadeClassifier face_cascade;

	if (!cap.open(0))
		return 0;

	if (!face_cascade.load(face_cascade_name))
	{
		printf("--(!)Error loading face cascade\n");
		system("pause");
		return -1;
	};

	int i = 0;
	vector<Rect> faces;
	Mat grayImage;
	for (;;)
	{
		Mat frame;
		cap >> frame;

		if (frame.empty()) break; // end of video stream
								  //imshow("this is you, smile! :)", frame);
		cvtColor(frame, grayImage, COLOR_BGR2GRAY);
		face_cascade.detectMultiScale(grayImage, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
		for (int i = 0; i < faces.size(); i++)
		{
			cout << "face " << i << "have location x = " << faces[i].x << ", y = " << faces[i].y;
			Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
			ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
		}
		imshow("face detected", frame);
		if (waitKey(10) == 27) break; // stop capturing by pressing ESC
		cout << i++;
	}
	// the camera will be closed automatically upon exit
	// cap.close();
	return 0;
}
