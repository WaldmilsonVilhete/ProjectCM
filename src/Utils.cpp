#include "Utils.h"


void Utils::test() {
}
bool Utils::checkButtonCircle(int x, int y, MyPoint center, float radious)
{
	float xDifferenceSquared, yDifferenceSquared;
	xDifferenceSquared = (float)x - center.x;
	xDifferenceSquared = xDifferenceSquared * xDifferenceSquared;
	yDifferenceSquared = (float)y - center.y;
	yDifferenceSquared = yDifferenceSquared * yDifferenceSquared;
	if (xDifferenceSquared + yDifferenceSquared < radious * radious) {
		return true;
	}
	return false;
}

bool Utils::checkButtonRectangle(int x, int y, MyPoint rightDownCorner, MyPoint leftUpCorner)
{
	if (x > leftUpCorner.x && x < rightDownCorner.x) {
		if (y > leftUpCorner.y && y < rightDownCorner.y) {
			return true;
		}
	}
	return false;
}

void Utils::detect_and_compute(string type, Mat& img, vector<KeyPoint>& kpts, Mat& desc) {
    
    
    if (type == "orb") {
        Ptr<ORB> orb = ORB::create();
       // orb->detectAndCompute(img, Mat(), kpts, desc);
        orb->detectAndCompute(img, cv::Mat(), kpts, desc);
    }
    
}

void Utils::match(string type, Mat& desc1, Mat& desc2, vector<DMatch>& matches2) {
    const double kDistanceCoef = 2.0;
    const int kMaxMatchingSize = 150;
    vector<DMatch> matches;
    matches.clear();
    if (type == "bf") {
        BFMatcher desc_matcher(cv::NORM_L2, true);
        desc_matcher.match(desc1, desc2, matches, Mat());
    }
    if (type == "knn") {
        BFMatcher desc_matcher(cv::NORM_L2, true);
        vector< vector<DMatch> > vmatches;
        desc_matcher.knnMatch(desc1, desc2, vmatches, 1);
        for (int i = 0; i < static_cast<int>(vmatches.size()); ++i) {
            if (!vmatches[i].size()) {
                continue;
            }
            matches.push_back(vmatches[i][0]);
        }
    }
    
    if (!matches.empty()) {
        while (matches.front().distance * kDistanceCoef < matches.back().distance) {
            matches.pop_back();
       }
        while (matches.size() > kMaxMatchingSize) {
            matches.pop_back();
        }
        for (int i = 0; i < matches.size(); i++) {
            if (matches[i].distance < 350.0) {
                matches2.push_back(matches[i]);
                //cout << matches[i].distance << "  ";
            }
        }
    }
    
    cout << "no of mathces: " << matches2.size();
}

void Utils::findKeyPointsHomography(vector<KeyPoint>& kpts1, vector<KeyPoint>& kpts2,
    vector<DMatch>& matches, vector<char>& match_mask, Mat& lastMat) {
    int nr_of_minimum_matches = 3;
    if (static_cast<int>(match_mask.size()) < nr_of_minimum_matches) {
        return;
    }
    vector<Point2f> pts1;
    vector<Point2f> pts2;
    for (int i = 0; i < static_cast<int>(matches.size()); ++i) {
        pts1.push_back(kpts1[matches[i].queryIdx].pt);
        pts2.push_back(kpts2[matches[i].trainIdx].pt);
    }
    lastMat = findHomography(pts1, pts2, cv::RANSAC, 4, match_mask);
}

bool Utils::Match2Images(ofImage ImageLoader1, string img_file2) {
    // Program expects at least four arguments:
    //   - the uploaded image
    //   - path to the scene image file
    //

    string desc_type("orb");
    string match_type("knn");

    ofImage ImageLoader;
    //ImageLoader1.load(img_file1);

    int height = ImageLoader1.getHeight();
    int width = ImageLoader1.getWidth();

    Mat image1 = ofxCv::toCv(ImageLoader1.getPixels());

    cv::InputArray img1(image1);

    cout << img_file2 << " ";
    ImageLoader.load(img_file2);

    Mat image2 = ofxCv::toCv(ImageLoader.getPixels());

    cv::InputArray img2(image2);
   


    cv::OutputArray des1(image1), des2(image2);
    if (img1.channels() != 1) {
        cvtColor(img1, des1, cv::COLOR_RGB2GRAY);
        
    }

    if (img2.channels() != 1) {
        cvtColor(img2, des2, cv::COLOR_RGB2GRAY);
    }
    
    if (!des2.empty()) {
        // Iterate over the rows and columns of the matrix
        
    }
    else {
        // Failed to load the image
        std::cout << "Failed to load the image." << std::endl;
    }
    
    vector<KeyPoint> kpts1;
    vector<KeyPoint> kpts2;

    Mat desc1;
    Mat desc2;

    vector<DMatch> matches;

    cv::InputArray reimg1(des1);
    cv::InputArray reimg2(des2);

    Mat init1 = reimg1.getMat();
    Mat init2 = reimg2.getMat();
    
    detect_and_compute(desc_type, init1, kpts1, desc1);
    detect_and_compute(desc_type, init2, kpts2, desc2);
    
    match(match_type, desc1, desc2, matches);
    
    Mat lastMat;

    vector<char> match_mask(matches.size(), 1);
    findKeyPointsHomography(kpts1, kpts2, matches, match_mask, lastMat);

    cv::InputArray ending(lastMat);
   

    if (matches.size() >= 100) {
        cout << "match";
        return true;
    }
    else {
        cout << "they don't match";
        return false;
    }

    /*Mat res;
    cv::drawMatches(img1, kpts1, img2, kpts2, matches, res, Scalar::all(-1),
        Scalar::all(-1), match_mask, DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    cv::imshow("result", res);
    cv::waitKey(0);*/
    
}