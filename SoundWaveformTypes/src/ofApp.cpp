#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mGui.setup("oscillator settings");
	mFreqSlider.setup("frequency", 200.0f, 60.0f, 2500.0f);
	mVolumeSlider.setup("volume(amplitude)", 0.0f,0.0f,0.5f);
	mTriggerSoundBtn.setup("Press to trigger envelope");
	//we add an event listener so we can
	//call onButtonPress method when our
	//button is pressed!
	mTriggerSoundBtn.addListener(this, &ofApp::onButtonPress);
	//ampersand means we pass in the variable location in memory
	//because inside the add function we create a pointer
	mGui.add(&mFreqSlider);
	mGui.add(&mVolumeSlider);
	mGui.add(&mTriggerSoundBtn);
	// 2 output channels (stereo), 0 input channels
	// 512 samples per buffer, 2 buffers
	ofSoundStreamSetup(2, 0, sampleRate, 512, 2);
}

//--------------------------------------------------------------
void ofApp::update(){
	//we could move this code into its own function
	ofScopedLock waveformLock(mWaveformMutex);
	if(bTriggerOsc && (float)mVolumeSlider < 0.3f){
	//each time update runs, we lerp towards 0.6f by 0.002
	//to make the lerp go faster, increase the last param
	mVolumeSlider = ofLerp(mVolumeSlider, 0.6f, 0.002);
	}
	else {
		bTriggerOsc = false;
	}
	ofLogNotice("volume") << (float)mVolumeSlider << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::white, ofColor::gray);
	mGui.draw();//draw our gui
}

//method called when we press our button
void ofApp::onButtonPress(){
	mVolumeSlider = (float) 0.0f;
	if(!bTriggerOsc) bTriggerOsc = true;
}

void ofApp::audioOut(ofSoundBuffer &outBuffer){
	ofScopedLock waveformLock(mWaveformMutex);
	for(int i = 0; i < outBuffer.size(); i += 2) {
		float sample = generateSample(mPhase, currWaveForm);
		sample *= (float)mVolumeSlider; // generating a sine wave sample
		outBuffer[i] = sample; // writing to the left channel
		outBuffer[i+1] = sample; // writing to the right channel
		//memorize this equation! phaseOffset = freq / sampleRate
		float phaseOffset = ((float)mFreqSlider / (float)sampleRate);
		mPhase += phaseOffset;
	}
}

//returns a sample given an input phase and desired
//waveform type
//eg. sine, square, sawtooth, triangle
float ofApp::generateSample(float phase, int waveType){
	switch (waveType) {
		case 1://sine
			return sin(phase*TWO_PI);
			break;
		case 2://square
			return sin(phase*TWO_PI)>0?1:-1;
		case 3://sawtooth
			return fmod(phase,TWO_PI);
		case 4://triangle
			return abs(sin(phase*TWO_PI));
		default:
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	currWaveForm = key;
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
