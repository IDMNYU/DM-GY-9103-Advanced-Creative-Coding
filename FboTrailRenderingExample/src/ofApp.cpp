#include "ofApp.h"
// A simple way of creating trail-like efffects using video and an fbo
//--------------------------------------------------------------
void ofApp::setup(){
	mVideoGrabber.setup(320, 240);
	mVideoGrabber.setVerbose(true);
	
	mFbo.allocate(mVideoGrabber.getWidth(),	 mVideoGrabber.getHeight(), GL_RGBA32F_ARB); // with alpha, 32 bits red, 32 bits green, 32 bits blue, 32 bits alpha, from 0 to 1 in 'infinite' steps
	
	//clear our fbo but not the alpha channel
	mFbo.begin();
	ofClear(255,255,255, 0);
	mFbo.end();
	//important so we don't automatically
	//clear our sketch background
	ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofEnableAlphaBlending();
	mVideoGrabber.update();
	
	//lets draw some graphics into our two fbos
	mFbo.begin();
	//this is where we fade the fbo
	//by setting the alpha to an opacity of 50
	//play around with this number to see how it affects the trails.
	ofSetColor(255,255,255,50);
	ofFill();
	
	// we check whether the videoGrabber has a new frame
	if(mVideoGrabber.isFrameNew()){
		mVideoGrabber.draw(0, 0);
	}
	mFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	mFbo.draw(0,0);
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
