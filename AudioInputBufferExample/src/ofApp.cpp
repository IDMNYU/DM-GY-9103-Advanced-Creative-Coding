#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	//2 output ch, 1 input ch
	ofSoundStreamSetup(2, 1, 44100, 512, 3);
	micSamples.assign(512, 0.0f);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(0.0,ofGetHeight()/2);
	//probably would be better as an ofPolyline
	//but I'm moving fast
	ofBeginShape();
	float x = 0;
	for(auto &sample: micSamples){
		ofVertex(x, sample*100.0f);
		x++;
	}
	ofEndShape();
}

void ofApp::audioIn(ofSoundBuffer &inBuff){
	for(int i=0; i < inBuff.size(); i++){
		//assign our buffer samples to our
		//floating point vector.
		// another betteroption would be to copy
		// the samples from inBuff to a custom
		// ofSoundBuffer. For more info on that
		//check out the soundBufferExample included
		//with openframeworks
		micSamples[i]		= inBuff[i*2]*0.5;
	}
}

void ofApp::audioOut(ofSoundBuffer &outBuff){
	//process your custom buffer and then copy
	//those values over to outBuff by
	//looping
	for(int i=0; i < outBuff.size(); i+=2){
		
	}
	
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
