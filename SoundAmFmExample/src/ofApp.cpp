#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	

	
	
	// start the sound stream with a sample rate of 44100 Hz, and a buffer
	// size of 512 samples per audioOut() call
	ofSoundStreamSetup(2, 0, sampleRate, 512, 3);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	switch(patch) {
		case 1:
			ofDrawBitmapString("1. Basic Oscillator", 20, 20);
			break;
		case 2:
			ofDrawBitmapString("2. Amplitude Modulation", 20, 20);
			break;
		case 3:
			ofDrawBitmapString("3. Amplitude Modulation w/ Phasor", 20, 20);
			break;
		case 4:
			ofDrawBitmapString("4. Frequency Modulation", 20, 20);
			break;
		default:
			break;
	}
}

void ofApp::osc1(float * output, int buffer_size) {
	for(int i = 0; i < buffer_size; i++) {
		output[i] = sin(ofMap(mouseX, 0,ofGetWidth(), 0,360.0)+ wavePhase);
	}
}

void ofApp::AM(float * output, int buffer_size) {
	for(int i = 0; i < buffer_size; i++) {
		output[i] = sin(ofMap(mouseX, 0,ofGetWidth(), 0,360.0)+ wavePhase) * sin(ofMap(mouseY, 0,ofGetHeight(), 0,360.0)+ wavePhase);
	}
}

void ofApp::AM2(float * output, int buffer_size) {
	for(int i = 0; i < buffer_size; i++) {
//		output[i] = osc1.sinewave(mouseX) * osc2.sinewave(osc3.phasor(0.01, 0, 440.0));
	}
}

void ofApp::FM(float * output, int buffer_size) {
	for(int i = 0; i < buffer_size; i++) {
//		output[i] = osc1.sinewave(osc2.sinewave(mouseX) * mouseY + 440.0);
	}
}


void ofApp::audioOut(float * output, int buffer_size, int n_channels){
	
	// base frequency of the lowest sine wave in cycles per second (hertz)
	float frequency = 172.5;
	
	// mapping frequencies from Hz into full oscillations of sin() (two pi)
	float wavePhaseStep = (frequency / sampleRate) * TWO_PI;
	float pulsePhaseStep = (0.5 / sampleRate) * TWO_PI;
	// get the two phase variables ready for the next sample
	wavePhase += wavePhaseStep;
	pulsePhase += pulsePhaseStep;
	
	switch(patch) {
		case 1:
			osc1(output, buffer_size);
			break;
		case 2:
			AM(output, buffer_size);
			break;
		case 3:
			AM2(output, buffer_size);
			break;
		case 4:
			FM(output, buffer_size);
			break;
		default:
			break;
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	patch = key;
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
