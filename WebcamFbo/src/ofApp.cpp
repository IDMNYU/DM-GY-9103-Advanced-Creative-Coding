#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mVideoGrabber.setup(320, 240);
	mVideoGrabber.setVerbose(true);
	mFbo.allocate(mVideoGrabber.getWidth(), mVideoGrabber.getHeight(), GL_RGBA);
	
	//now we add lines to our path
	mPath.lineTo(mVideoGrabber.getWidth()/4, mVideoGrabber.getHeight());
	mPath.lineTo(mVideoGrabber.getWidth()/2, mVideoGrabber.getHeight()/ 2);
	mPath.lineTo(mVideoGrabber.getWidth(), 0);
	mPath.close();
	
	mFbo.begin();
	ofClear(0,0,0,0);
	ofSetColor(255,255,255,255);
	mPath.draw();
	mFbo.end();
	
}

//--------------------------------------------------------------
void ofApp::update(){
	mVideoGrabber.update();
	// we check whether the videoGrabber has a new frame
	if(mVideoGrabber.isFrameNew()){
		//if so we get the videoGrabber texture, and set an alpha mask on it from our fbo
		mVideoGrabber.
			getTexture().
			setAlphaMask(mFbo.getTexture());
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//draw the webcam
	mVideoGrabber.draw(ofGetMouseX(), ofGetMouseY());
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
