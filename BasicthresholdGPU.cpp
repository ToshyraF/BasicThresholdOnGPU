#include <opencv2/opencv.hpp>
#include <opencv2/gpu/gpu.hpp>
#include <iostream>
#include <string>
#include "opencv2/core/core.hpp"

using namespace cv;
// using namespace cv::gpu;
int main(){

	//read Image
	Mat src = imread("circles3.jpg", IMREAD_GRAYSCALE);

	//check value of src
	if(!src.data) exit(1);

	//copy src to d_src (host to GPU)
	gpu::GpuMat d_src(src);
	gpu::GpuMat d_dst;

	//call threshold function on GPU
	gpu::threshold(d_src,d_dst,128,255,THRESH_BINARY);

	//copy d_dst to dst (GPU to host)
	Mat dst(d_dst);

	//Output
	namedWindow("images source", WINDOW_AUTOSIZE);
	imshow("images source", src);
	namedWindow("images", WINDOW_AUTOSIZE);
	imshow("images", dst);
	waitKey(0);
	return 0;
}