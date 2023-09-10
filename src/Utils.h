#pragma once

#include "ofMain.h"
#include "MyPoint.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/core/ocl.hpp>
#include <ofxCv.h>
//#include <ofxCv/libs/ofxCv/src/Utilities.cpp>

using cv::Mat;
using cv::Point2f;
using cv::KeyPoint;
using cv::Scalar;
using cv::Ptr;

using cv::DMatch;
using cv::BFMatcher;
using cv::DrawMatchesFlags;
using cv::Feature2D;
using cv::ORB;
using cv::BRISK;
using cv::AKAZE;
using cv::KAZE;


//using namespace cv;
//using namespace ofxCv;

class Utils
{
public:
	void test();
	bool checkButtonCircle(int x, int y, MyPoint center, float radious);
	bool checkButtonRectangle(int x, int y, MyPoint rightDownCorner, MyPoint leftUpCorner);
	void detect_and_compute(string type, Mat& img, vector<KeyPoint>& kpts, Mat& desc);
	void match(string type, Mat& desc1, Mat& desc2, vector<DMatch>& matches);
	void findKeyPointsHomography(vector<KeyPoint>& kpts1, vector<KeyPoint>& kpts2,
		vector<DMatch>& matches, vector<char>& match_mask, Mat& lastMat);
	bool Match2Images(ofImage ImageLoader1, string img_file2);
};

