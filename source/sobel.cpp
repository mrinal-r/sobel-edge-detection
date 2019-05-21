//
// Created by Mrinal Rawool on 4/23/19.
//

#include "sobel.h"

Mat sobelEdgeDetector(Mat& image, int kernelSize, int scale, int delta){

    // -- perform Gaussian blur with kernel size 3 -- //
    GaussianBlur(image, image, Size(5,5), 0, 0, BORDER_DEFAULT);

    // -- calculate gradient along x and y axis -- //
    Mat grad_x, grad_y;   // -- storing gradient images along x and y axis -- //
    int ddepth = CV_16S;  // -- 3 -- //

    // -- first order along y -- //
    Sobel(image, grad_x, ddepth, 1, 0, kernelSize, scale, delta, BORDER_DEFAULT);
    // -- first order along y -- //
    Sobel(image, grad_y, ddepth, 0, 1, kernelSize, scale, delta, BORDER_DEFAULT);

    // -- calculate final gradient G = |Gx| + |Gy|
    Mat abs_grad_x, abs_grad_y;
    convertScaleAbs(grad_x, abs_grad_x); // -- |Gx| -- //
    convertScaleAbs(grad_y, abs_grad_y); // -- |Gy| -- //

    // -- dst = src1*alpha + src2*beta + gamma; -- //
    Mat output;
    //addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, output);
    bitwise_or(abs_grad_x,abs_grad_y,output);

    return output;

}

Mat superimpose(Mat& original, Mat& edges){

    // -- create array of matrices -- //
    Mat matArray[3];

    // -- initialize -- //
    int h = original.rows;
    int w = original.cols;

    matArray[0]= edges.clone();
    matArray[1]= Mat(h,w,CV_8UC1, Scalar(0));
    matArray[2]= Mat(h,w,CV_8UC1, Scalar(0));

    Mat colorEdge;
    // -- creating a colored version of edges -- /
    merge(matArray,3, colorEdge);

    // -- creating color version of original image -- /
    Mat colorImage;
    cv::cvtColor(original, colorImage, cv::COLOR_GRAY2BGR);

    // -- final output -- //
    Mat output = Mat::zeros(original.size(), CV_8UC3);
    //addWeighted(colorImage, 0.5, colorEdge, 0.5, 0, output);
    bitwise_or(colorImage,colorEdge,output);
    return output;
}