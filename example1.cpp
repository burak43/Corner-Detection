/*
 * example1.cpp
 *
 *  Created on: Jun 6, 2016
 *      Author: burak
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout << "Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image(300,600, CV_8UC3, Scalar(255,0,255));

    //image = imread(argv[1], 0);   		// Read the file

    if(! image.data )                       // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "Display window", WINDOW_AUTOSIZE );			// Create a window for display.
    imshow( "Maserati Inside View", image );                   // Show our image inside it.

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}
