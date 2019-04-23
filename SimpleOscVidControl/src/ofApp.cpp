#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	receiver.setup(PORT);
	player.load("CQ02607.mov");
	player.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	player.update();
	
	while(receiver.hasWaitingMessages()){
		ofxOscMessage m;
		receiver.getNextMessage(m);
		if(m.getAddress() == "/accxyz"){
			auto x = m.getArgAsFloat(0);
			auto y = m.getArgAsFloat(1);
			auto z = m.getArgAsFloat(2);
			ofLogNotice() << x << " " << y << " " << z << endl;
			if( x  < 0.001){
				x = 0.001;
			}
			mVidSpeed = x;
			mVidRotation = y*100.0;
			mVidScale = z;
			ofLogNotice() << mVidSpeed << endl;
		}
	}
	
	player.setSpeed(mVidSpeed);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofRotateXDeg(mVidRotation);
	player.draw(ofGetWidth()/2, ofGetHeight() / 2);
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
