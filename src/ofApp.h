#pragma once

#include "ofMain.h"
#include "Utils.h"
#include "MyPoint.h"
#include <opencv2/features2d.hpp>


using cv::ORB;

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void LoadScreen1();
	void DrawScreen1();
	void LoadScreen2();
	void DrawScreen2();
	void drawDraggedImage();

	Utils Tool;
	ofImage ImageLoad;
	ofImage ImageVector[9];
	ofImage ButtonVector1[5];
	ofFile *textFile, textFile1, textFile2, textFile3;
	int loadedImageNumber, lowbownd, highbound;
	int screenLoader;
	bool firstResize;
	bool loadNewImage;
	float timer;
	int width, heigh;
	MyPoint relativePointLeft, relativePointRight;
	MyPoint uploadLUCorner, uploadRDCorner;
	MyPoint pictureLUUpload, pictureRDUpload;
	ofTrueTypeFont 	vagRounded;
	ofTrueTypeFont	verdana14;
	string eventString;
	string path;
	string foundImage;
	vector <string> imageNames;
	vector <ofImage> draggedImages;
	glm::vec2 dragPt;

};