#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mVideoGrabber.setup(320, 240);
	mVideoGrabber.setVerbose(true);//set the videoGrabber to verbose so we can get a debug output
	mColorImage.allocate(320, 240);
	mGrayscaleImage.allocate(320, 240);
	
	mBall.checkIntersects(ofVec2f(2.4f));
}

//--------------------------------------------------------------
void ofApp::update(){
	mVideoGrabber.update();
	if(mVideoGrabber.isFrameNew()){
		mColorImage.setFromPixels(mVideoGrabber.getPixels());
		mGrayscaleImage = mColorImage;//notice how we set the grayscale image to the val of our colorImage. This is done through operator overloading in C++
		
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	mVideoGrabber.draw(20, 20);//draw the videoGrabber output
	mColorImage.draw(20, mVideoGrabber.getWidth() + 20);//draw the colorImage output
	mGrayscaleImage.draw(mColorImage.getWidth()+40, mVideoGrabber.getWidth() + 20);//draw the grayscaleImage output
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
