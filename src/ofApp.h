#pragma once

#include "ofMain.h"
#include "Utils.h"
#include "Point.h"

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

	Utils Tool;
	ofImage ImageLoad;
	ofImage ImageVector[3];
	ofImage ButtonVector1[5];
	int loadedImageNumber;
	int screenLoader;
	bool firstResize;
	bool loadNewImage;
	float timer;
	int width, heigh;
	Point relativePointLeft, relativePointRight;
	Point uploadLUCorner, uploadRDCorner;
	Point pictureLUUpload, pictureRDUpload;
	ofTrueTypeFont 	vagRounded;
	string eventString;

};