#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
		ofSoundStream soundStream;
		void audioOut( ofSoundBuffer &outBuffer );
		void onButtonPress();
		double mPhase = 0;
		ofxFloatSlider mFreqSlider;
		ofxFloatSlider mVolumeSlider;
		ofxButton mTriggerSoundBtn;
		ofxPanel mGui;
		int sampleRate = 44100;
		bool bTriggerOsc = false;
		ofMutex mWaveformMutex;
};
