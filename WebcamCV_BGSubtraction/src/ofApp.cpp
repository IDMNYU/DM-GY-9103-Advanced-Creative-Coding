#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mVideoGrabber.setup(320, 240);
	mVideoGrabber.setVerbose(true);//set the videoGrabber to verbose so we can get a debug output
	
	//get the width and height of our mVideoGrabber as a glm::ivec2 type
	glm::ivec2 grabberSize = glm::ivec2(int(mVideoGrabber.getWidth()), int(mVideoGrabber.getHeight()));
	//we access the x and y properties of our grabberSize like
	//so
	mColorImage.allocate(grabberSize.x, grabberSize.y);
	mGrayscaleImage.allocate(grabberSize.x, grabberSize.y);
	mBgImage.allocate(grabberSize.x, grabberSize.y);
	mGrayDifference.allocate(grabberSize.x, grabberSize.y);
}

//--------------------------------------------------------------
void ofApp::update(){
	mVideoGrabber.update();

	
	if(mVideoGrabber.isFrameNew()){
		mColorImage.setFromPixels(mVideoGrabber.getPixels());
		mGrayscaleImage = mColorImage;//notice how we set the grayscale image to the val of our colorImage. This is done through operator overloading in C++
		
		
		
	}
	//every 5 seconds we will sample a new background
	if(ofGetSeconds() % 5 == 0){
		mBgImage = mGrayscaleImage;
	}
	//we set our difference to the absDiff
	mGrayDifference.absDiff(mGrayscaleImage, mBgImage);
	mGrayDifference.threshold(80);
}

//--------------------------------------------------------------
void ofApp::draw(){

	mColorImage.draw(20, mVideoGrabber.getWidth() + 20);//draw the colorImage output
	mGrayscaleImage.draw(mColorImage.getWidth()+40, mVideoGrabber.getWidth() + 20);//draw the grayscaleImage output
	
	//we draw the grayscale difference which separates our bg from our subject
	mGrayDifference.draw(20,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
