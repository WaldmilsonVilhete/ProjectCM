#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

	//text font loading
	verdana14.load("verdana.ttf", 14, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);
	//path = "/Users/bogda/Desktop/diverse/anul_3/Sem2/Multimedia Computing/type2/of_v0.11.2_vs2017_release/apps/myApps/myFearlessSketch/bin/data/";
	firstResize = TRUE;
	loadNewImage = FALSE;
	ImageLoad.load("images/Buttons/Left.png");
	ButtonVector1[0] = ImageLoad;
	ImageLoad.load("images/Buttons/Right.png");
	ButtonVector1[1] = ImageLoad;
	ImageLoad.load("images/Buttons/Upload.png");
	ButtonVector1[2] = ImageLoad;
	ImageLoad.load("images/Buttons/UploadScreen1.png");
	ButtonVector1[3] = ImageLoad;
	loadedImageNumber = 6;
	screenLoader = 1;
	vagRounded.load("vag.ttf", 32);
	ofBackground(50, 50, 50);

	imageNames.push_back("images/Vasco.jpg");
	imageNames.push_back("images/Vasco2.jpg");
	imageNames.push_back("images/Vasco3.jpg");
	imageNames.push_back("images/25AprilBridge.jpeg");
	imageNames.push_back("images/25AprilBridge2.jpeg");
	imageNames.push_back("images/25AprilBridge3.jpeg");
	imageNames.push_back("images/25AprilBridge4.jpeg");
	imageNames.push_back("images/Jeronimos.jpeg");
	imageNames.push_back("images/Jeronimos2.jpeg");
	imageNames.push_back("images/Jeronimos3.jpeg");

		ImageLoad.load("images/Vasco.jpg");
		ImageVector[0] = ImageLoad;
		ImageLoad.load("images/Vasco2.jpg");
		ImageVector[1] = ImageLoad;
		ImageLoad.load("images/Vasco3.jpg");
		ImageVector[2] = ImageLoad;
		ImageLoad.load("images/Jeronimos.jpeg");
		ImageVector[3] = ImageLoad;
		ImageLoad.load("images/Jeronimos2.jpeg");
		ImageVector[4] = ImageLoad;
		ImageLoad.load("images/Jeronimos3.jpeg");
		ImageVector[5] = ImageLoad;
		ImageLoad.load("images/25AprilBridge.jpeg");
		ImageVector[6] = ImageLoad;
		ImageLoad.load("images/25AprilBridge2.jpeg");
		ImageVector[7] = ImageLoad;
		ImageLoad.load("images/25AprilBridge3.jpeg");
		ImageVector[8] = ImageLoad;

	textFile1.open(ofToDataPath("text/25AprilBridge.txt"), ofFile::ReadWrite, false);
	textFile2.open(ofToDataPath("text/Vasco.txt"), ofFile::ReadWrite, false);
	textFile3.open(ofToDataPath("text/Jeronimos.txt"), ofFile::ReadWrite, false);

	foundImage = "text/25AprilBridge.txt";
	highbound = 8;
	lowbownd = 0;

}

//--------------------------------------------------------------
void ofApp::update() {

	width = ofGetWindowWidth();
	heigh = ofGetWindowHeight();
	switch (screenLoader)
	{
	case 1: LoadScreen1();
		break;
	case 2: LoadScreen2();
		break;
	default: LoadScreen1();
		break;
	}
	//LoadScreen1();
}

//--------------------------------------------------------------
void ofApp::draw(){

	timer = (int)(ofGetElapsedTimef() * 1000) % 1000;
	/*if (timer > 500) {
		
		//ImageVector[0].resize(300, 300);
		//ImageVector[0].draw(200, 200);
	}
	else {
		//ImageVector[1].resize(300, 300);
		//ImageVector[1].draw(200, 200);
	}*/
	switch (screenLoader)
	{
	case 1: DrawScreen1();
		break;
	case 2: DrawScreen2();
		break;
	default: DrawScreen1();
		break;
	}


	//ofSetHexColor(0xffffff);
	//vagRounded.drawString(eventString, 98, 198);

	//ofSetColor(255, 122, 220);
	//vagRounded.drawString(eventString, 100, 200);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	eventString = "mouseMoved = (" + ofToString(x) + ", " + ofToString(y) + ")";
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (screenLoader == 1) {
		eventString = "mousePressed = (" + ofToString(x) + ", " + ofToString(y) + " - button " + ofToString(button) + ")";
		//check if the left button is pressed
		if (Tool.checkButtonCircle(x, y, relativePointLeft, heigh / 16)) {
			loadedImageNumber--;
		}
		//check if the right button is pressed
		if (Tool.checkButtonCircle(x, y, relativePointRight, heigh / 16)) {
			loadedImageNumber++;
		}
		//check if the upload button is pressed
		if (Tool.checkButtonRectangle(x, y, uploadRDCorner, uploadLUCorner)) {
			screenLoader++;
		}
	} 
	if (screenLoader == 2) {
		//check if the upload button was perssed
		if (Tool.checkButtonRectangle(x, y, pictureRDUpload, pictureLUUpload)) {
			// do some calculations, see what picture it is
			if (draggedImages.size() > 0) {
				std::cout << "uploaded an image";
				ofImage image1 = draggedImages[0];
				draggedImages.clear();
				bool match = false;
				int iterator = 0;
				while (iterator < imageNames.size() && match != true) {
					match = Tool.Match2Images(image1, imageNames[iterator]);
					iterator++;
				}
				iterator--;
				if (match == TRUE) {
					if (imageNames[iterator].find("Vasco") != std::string::npos) {
						
						foundImage = "text/Vasco.txt";
						highbound = 2;
						lowbownd = 0;
					}
					
					if (imageNames[iterator].find("Jeronimos") != std::string::npos) {

						foundImage = "text/Jeronimos.txt";
						highbound = 3;
						lowbownd = 5;
					}

					if (imageNames[iterator].find("25AprilBridge") != std::string::npos) {

						foundImage = "text/25AprilBridge.txt";
						highbound = 6;
						lowbownd = 8;
					}

					loadNewImage = TRUE;
				}
			}
			else {
				std::cout << "image empty";
			}
			screenLoader--;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo info){
	if (info.files.size() > 0) {
		dragPt = info.position;

		draggedImages.assign(info.files.size(), ofImage());
		for (unsigned int k = 0; k < info.files.size(); k++) {
			draggedImages[k].load(info.files[k]);
		}
	}

}
void ofApp::LoadScreen1() {
	
	relativePointLeft.x = width * 2 / 3 + heigh / 16;
	relativePointLeft.y = heigh * 3 / 4 + heigh / 16;
	relativePointRight.x = relativePointLeft.x + heigh / 4;
	relativePointRight.y = relativePointLeft.y;
	uploadLUCorner.x = width / 36;
	uploadLUCorner.y = heigh * 2 / 3;
	uploadRDCorner.x = uploadLUCorner.x + heigh / 6;
	uploadRDCorner.y = uploadLUCorner.y + heigh / 6;
	if (firstResize == TRUE) {
		ImageLoad.resize(ImageLoad.getWidth() / 4, ImageLoad.getHeight() / 4);
		ImageLoad.setImageType(OF_IMAGE_GRAYSCALE);
		firstResize = FALSE;
		loadNewImage = TRUE;
	}
	if (loadNewImage == TRUE) {

		loadNewImage = FALSE;
	}

}
void ofApp::DrawScreen1() {

	
	if (loadedImageNumber > highbound) {
		loadedImageNumber = lowbownd;
	}
	if (loadedImageNumber < lowbownd) {
		loadedImageNumber = highbound;
	}
	ImageVector[loadedImageNumber].resize(300, 300);
	ImageVector[loadedImageNumber].draw(200, 200);


	ButtonVector1[0].resize(heigh / 8, heigh / 8);
	ButtonVector1[0].draw(width * 2 / 3, heigh * 3 / 4);
	ButtonVector1[1].resize(heigh / 8, heigh / 8);
	ButtonVector1[1].draw(width * 2 / 3 + heigh / 4, heigh * 3 / 4);
	ButtonVector1[2].resize(heigh / 6, heigh / 6);
	ButtonVector1[2].draw(width / 36, heigh * 2 / 3);

	textFile1.open(ofToDataPath("text/25AprilBridge.txt"), ofFile::ReadWrite, false);
	textFile2.open(ofToDataPath("text/Vasco.txt"), ofFile::ReadWrite, false);
	textFile3.open(ofToDataPath("text/Jeronimos.txt"), ofFile::ReadWrite, false);
	//text output:
	if (foundImage.find("Vasco") != std::string::npos) {
		textFile = &textFile2;
	}
	if (foundImage.find("Jeronimos") != std::string::npos) {
		textFile = &textFile3;
	}
	if (foundImage.find("25AprilBridge") != std::string::npos) {
		textFile = &textFile1;
		
	}
	
	int posY = heigh / 4;
	string line;
	ofSetColor(ofColor::white);
	ofDrawRectangle(width * 5 / 8 - 50, heigh / 4 - 50, width * 3 / 8, heigh / 2 );
	while (getline((*textFile), line)) {
		if (line.empty() == false) {
			//string minutes = grepStringInRegex(line, "[0-9]+:[0-9]+");
			//string sentence = grepStringInRegex(line, "[^0-9_:\\[\\]]");
			//ofDrawBitmapString("Time:" + minutes, 400, posY);
			//ofDrawBitmapString("Sentence:" + sentence, 500, posY);
			
			ofSetColor(ofColor::black);
			verdana14.drawString(line, width * 5 / 8, posY);
			posY += 20;
			
		}
	}
	ofSetColor(ofColor::white);

	//verdana14.drawString("Font Example - use keyboard to type", 30, 35);
}

void ofApp::LoadScreen2() {
	
	pictureLUUpload.x = width / 4 + width / 8;
	pictureLUUpload.y = heigh * 3 / 4;
	pictureRDUpload.x = pictureLUUpload.x + width / 4;
	pictureRDUpload.y = pictureLUUpload.y + heigh / 8;
}
void ofApp::DrawScreen2() {
	drawDraggedImage();
	ButtonVector1[3].resize(width / 4, heigh / 8);
	ofSetColor(ofColor::white);
	ButtonVector1[3].draw(width / 4 + width / 8, heigh * 3 / 4);
}

void ofApp::drawDraggedImage() {
	ofSetColor(255);

	float dx = dragPt.x;
	float dy = dragPt.y;

	
	for (unsigned int k = 0; k < draggedImages.size(); k++) {
		draggedImages[k].draw(dx, dy);
		dy += draggedImages[k].getHeight() + 10;
	}

	ofSetColor(0);
	ofDrawBitmapString("drag image files into this window", 10, 20);
}
