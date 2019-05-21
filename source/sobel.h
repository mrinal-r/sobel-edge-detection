//
// Created by Mrinal Rawool on 4/23/19.
//

#ifndef SOBELEDGEDETECTOR_SOBEL_H
#define SOBELEDGEDETECTOR_SOBEL_H

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <iterator>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;
using std::string;
using std::map;

Mat sobelEdgeDetector(Mat& image, int kernelSize, int scale, int delta);

Mat superimpose(Mat& original, Mat& edges);

#endif //SOBELEDGEDETECTOR_SOBEL_H
