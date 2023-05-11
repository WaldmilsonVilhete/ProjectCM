#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
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
	ImageLoad.load("images/Vasco.jpeg");
	ImageVector[0] = ImageLoad;
	loadedImageNumber = 0;
	screenLoader = 1;
	vagRounded.load("vag.ttf", 32);
	ofBackground(50, 50, 50);

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
	vagRounded.drawString(eventString, 100, 200);

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
void ofApp::dragEvent(ofDragInfo dragInfo){ 

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
		ImageLoad.load("images/Jeronimos.jpeg");
		ImageVector[1] = ImageLoad;
		loadNewImage = FALSE;
	}
}
void ofApp::DrawScreen1() {
	if (loadedImageNumber > 1) {
		loadedImageNumber = 0;
	}
	if (loadedImageNumber < 0) {
		loadedImageNumber = 1;
	}
	ImageVector[loadedImageNumber].resize(300, 300);
	ImageVector[loadedImageNumber].draw(200, 200);


	ButtonVector1[0].resize(heigh / 8, heigh / 8);
	ButtonVector1[0].draw(width * 2 / 3, heigh * 3 / 4);
	ButtonVector1[1].resize(heigh / 8, heigh / 8);
	ButtonVector1[1].draw(width * 2 / 3 + heigh / 4, heigh * 3 / 4);
	ButtonVector1[2].resize(heigh / 6, heigh / 6);
	ButtonVector1[2].draw(width / 36, heigh * 2 / 3);
}

void ofApp::LoadScreen2() {
	pictureLUUpload.x = width / 4 + width / 8;
	pictureLUUpload.y = heigh * 3 / 4;
	pictureRDUpload.x = pictureLUUpload.x + width / 4;
	pictureRDUpload.y = pictureLUUpload.y + heigh / 8;
}
void ofApp::DrawScreen2() {
	ButtonVector1[3].resize(width / 4, heigh / 8);
	ButtonVector1[3].draw(width / 4 + width / 8, heigh * 3 / 4);
}