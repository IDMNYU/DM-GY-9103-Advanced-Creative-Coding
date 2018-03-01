#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mGui.setup("oscillator settings");
	mFreqSlider.setup("frequency", 200.0f, 60.0f, 2500.0f);
	mVolumeSlider.setup("volume(amplitude)", 0.2f,0.0f,0.89f);
	//ampersand means we pass in the variable location in memory
	//because inside the add function we create a pointer
	mGui.add(&mFreqSlider);
	mGui.add(&mVolumeSlider);
	// 2 output channels (stereo), 0 input channels
	// 512 samples per buffer, 2 buffers
	ofSoundStreamSetup(2, 0, sampleRate, 512, 2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	mGui.draw();//draw our gui
}


void ofApp::audioOut(ofSoundBuffer &outBuffer){
	
	for(int i = 0; i < outBuffer.size(); i += 2) {
		float sample = sin(mPhase*TWO_PI) * (float)mVolumeSlider; // generating a sine wave sample
		outBuffer[i] = sample; // writing to the left channel
		outBuffer[i+1] = sample; // writing to the right channel
		//memorize this equation! phaseOffset = freq / sampleRate
		float phaseOffset = ((float)mFreqSlider / (float)sampleRate);
		mPhase += phaseOffset;
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
