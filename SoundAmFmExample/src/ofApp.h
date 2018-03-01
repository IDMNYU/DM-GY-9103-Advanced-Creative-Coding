#pragma once

#include "ofMain.h"
#include "ofxGui.h"

enum class ModulationType {AM, FM};

// builds on SoundSimpleOscillator app
class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	//our audio output stream
	void audioOut( ofSoundBuffer &outBuffer );
	void onButtonPress();
	float generateSample(float phase, int waveType);
	float modulateSample(float sample, float modFreq, float modOffset, const ModulationType modType);
	double mPhase = 0;
	float mModPhase = 0.0f;
	ofxFloatSlider mFreqSlider;
	ofxFloatSlider mVolumeSlider;
	ofxFloatSlider mLfoFreqSlider;
	ofxFloatSlider mLfoAmpSlider;
	ofxPanel mGui;
	int sampleRate = 44100;
	bool bTriggerOsc = false;
	ofMutex mWaveformMutex;
	int currWaveForm = 1;
	
	float wavePhase;
	float pulsePhase;
	
	ModulationType mCurrentMod = ModulationType::AM;

};
