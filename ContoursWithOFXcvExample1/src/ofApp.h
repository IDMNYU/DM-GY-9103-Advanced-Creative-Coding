#pragma once

#include "ofMain.h"
//EXAMPLE USES KYLE MACDONALDS ofxCV addon
//VERY IMPORTANT WHEN CREATING NEW PROJECTS USING THIS ADDON:
//You must add ofxCv and ofxOpenCV in the projectGenerator app
#include "ofxCv.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void drawContourEdges();
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
		bool bShowCam = true;
		ofVideoGrabber cam;
		ofxCv::ContourFinder contourFinder;
};
