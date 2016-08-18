/*
 * cornerDetection.cpp
 *
 *  Created on: Jun 6, 2016
 *      Author: burak
 */

// Program to detect corners in an image
// Author: Samarth Manoj Brahmbhatt, University of Pennyslvania
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
using namespace std;
using namespace cv;

Mat image, image_gray;
int max_corners = 1000;

int main()
{
	image = imread("ghibli_inside.jpg");
	cvtColor(image, image_gray, CV_RGB2GRAY);
	namedWindow("Corners");

	if(image_gray.empty())
		return 0;

	float quality = 0.01;
	int min_distance = 10;
	vector<Point2d> corners;
	goodFeaturesToTrack(image_gray, corners, max_corners, quality, min_distance);

	// Draw the corners as little filled circles
	Mat image_corners = image.clone();
	for(size_t i = 0; i < corners.size(); i++)
		circle(image_corners, corners[i], 4, CV_RGB(255, 0, 0), -1);

	imshow("Corners", image_corners);

	waitKey(0);
	return 0;
}

