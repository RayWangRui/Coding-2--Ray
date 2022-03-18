#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	// void keyPressed(int key);
	// void keyReleased(int key);
	// void mouseMoved(int x, int y );
	// void mouseDragged(int x, int y, int button);
	// void mousePressed(int x, int y, int button);
	// void mouseReleased(int x, int y, int button);
	// void mouseEntered(int x, int y);
	// void mouseExited(int x, int y);
	// void windowResized(int w, int h);
	// void dragEvent(ofDragInfo dragInfo);
	// void gotMessage(ofMessage msg);
    float r1, g1, b1;
	float r2, g2, b2;

	ofSoundPlayer 		beat;
	//ofSoundPlayer		ow;
	//ofSoundPlayer		dog;
	//ofSoundPlayer		rooster;

	float 				* fftSmoothed;
	// we will draw a rectangle, bouncing off the wall:
	float 				px, py, vx, vy;

	int nBandsToGet;
	float prevx, prevy;
	float * tx; //±äÁ¿
	float * ty; //±äÁ¿
	float w = 0;//±äÁ¿
	float r = 0.5 * PI / 256;//±äÁ¿
};
