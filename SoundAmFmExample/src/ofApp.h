#pragma once

#include "ofMain.h"

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
		void audioOut(float * output, int buffer_size, int n_channels);
	
		void osc1(float * output, int buffer_size);
		void AM(float * output, int buffer_size);
		void AM2(float * output, int buffer_size);
		void FM(float * output, int buffer_size);
		int wavePhase = 0;
		int pulsePhase = 0;
		int sampleRate = 44100;
		int patch = 1;
};
