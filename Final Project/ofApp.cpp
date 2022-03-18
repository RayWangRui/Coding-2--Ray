#include "ofApp.h"


ofSoundPlayer sound;
ofFbo fbo;
const int numBands = 2048;
float spectrum[numBands];

void ofApp::setup() {
	ofBackgroundGradient(ofColor(128), ofColor(0));

	//ofBackground(r, g, b);

	sound.load("1.mp3");
	sound.setLoop(true);
	sound.play();

	fbo.allocate(ofGetWidth(), ofGetHeight());

	for (int i = 0; i < numBands; i++) {
		spectrum[i] = 0.0f;
	}

	// load in sounds:
	beat.load("1.wav");
	//ow.load("sounds/ow.mp3");
	

	// we will bounce a circle using these variables:
	px = 300;
	py = 300;
	vx = 0;
	vy = 0;

	// the fft needs to be smoothed out, so we create an array of floats
	// for that purpose:
	fftSmoothed = new float[8192];

	for (int i = 0; i < 8192; i++) {
		fftSmoothed[i] = 0;
	}

	nBandsToGet = 256;
	tx = new float[nBandsToGet];//x×ø±êÊý×é
	ty = new float[nBandsToGet];//y×ø±êÊý×é
	beat.play();
	for (int i = 0; i < nBandsToGet; i++) {//ËùÓÐµÄ
		tx[i] = 1120 + cos(r) * 300;//x×ø±ê
		ty[i] = 350 + sin(r) * 300;//y×ø±ê
		r += 2 * PI / nBandsToGet;//Ôö¼Ó
	}
}

void ofApp::update() {
	float *val = ofSoundGetSpectrum(numBands);

	for (int i = 0; i < numBands; i++) {
		spectrum[i] *= ofRandom(0.75, 0.95);
		spectrum[i] = max(spectrum[i] * ofRandom(0.02, 0.05), val[i]);
	}

	// --------------------------------------------------------------------------
	ofSoundUpdate();

	// (1) we increase px and py by adding vx and vy
	px += vx;
	py += vy;


	
	float vel = sqrt(vx*vx + vy * vy);
	//ow.setVolume(MIN(vel/5.0f, 1));
	//beat.setVolume(MIN(vel/5.0f, 1));
	//dog.setVolume(MIN(vel/5.0f, 1));
	//rooster.setVolume(MIN(vel/5.0f, 1));

	
	for (int i = 0; i < nBandsToGet; i++) {

		// let the smoothed calue sink to zero:
		//fftSmoothed[i] *= 0.96f;

		// take the max, either the smoothed or the incoming:
		//if (fftSmoothed[i] < val[i]) 
		fftSmoothed[i] = val[i];

	}
}
void ofApp::mousePressed(int x, int y, int button) {
	r1 = ofRandom(255);
	g1 = ofRandom(255);
	b1 = ofRandom(255);

	//r2 = ofRandom(255);
	//g2 = ofRandom(255);
	//b2 = ofRandom(255);
}

void ofApp::draw() {
	//ofEnableAlphaBlending();
	//ofEnableAntiAliasing();

	fbo.begin();
	ofBackground(r1, g1, b1);
	//ofBackgroundGradient(ofColor(128), ofColor(0));

	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float radius = ofRandom(150, 250);

	ofSetColor(255, 255, 255, 255);
	for (int i = 0; i < numBands; i++) {
		float x = 200 + radius * cos(i);
		float y = 0 + radius * sin(i);
		float size = spectrum[i] * ofRandom(100, 200);
		size *= ofRandom(-2, 2);

		int c = ofRandom(255);
		//ofSetColor(r2, g2, b2, 200);
		//ofDrawCircle(x, y, size);
		ofDrawRectangle(x, y, size * 3, size * 3);
	}

	fbo.end();
	ofPopMatrix();
	fbo.draw(0, 0);

	ofDrawBitmapString("Click to change color", 50, 50);

	w = 0;// 2 * PI;// / nBandsToGet;;


	float width = (float)(9 * 128) / nBandsToGet;
	for (int i = 0; i < nBandsToGet; i++) {
		int a = 2 * (int)(fftSmoothed[i] * 100);
		/*ofColor c;
		c.setHsb(i * 1, 255, 255);
		ofSetColor(c);*/
		ofSetColor(0, 255, 255, 255);
		// (we use negative height here, because we want to flip them
		// because the top corner is 0,0)
		//ofDrawRectangle(i*width,0, width,(fftSmoothed[i] * 200));
		for (int j = 0; j < a; j++)
		{
			//fill(j*1.3, 255, 255);
			ofDrawRectangle(i * 10, ofGetHeight() - j * 6, 8, 4);
		}
	}
	ofSetLineWidth(2);
	//ofTranslate(-1020, -350);
	//ofRotate(-1.5*PI);
	//ofTranslate(1020, 350);
	for (int i = 0; i < nBandsToGet; i++) {//ËùÓÐµÄ
	/*	ofColor c;
		c.setHsb(i * 1, 255, 255);
		ofSetColor(c);*/
		ofSetColor(255, 255, 0, 255);
		if (i == nBandsToGet - 1) {//Ã»µ½±ß½ç
			ofDrawLine(tx[i] + fftSmoothed[i] * 150 * cos(w), ty[i] + fftSmoothed[i] * 150 * sin(w), tx[0] + fftSmoothed[0] * 150 * cos(w), ty[0] + fftSmoothed[0] * 150 * sin(w));//ÏßÌõ
			ofDrawLine(tx[i] - fftSmoothed[i] * 150 * cos(w), ty[i] - fftSmoothed[i] * 150 * sin(w), tx[0] - fftSmoothed[0] * 150 * cos(w), ty[0] - fftSmoothed[0] * 150 * sin(w));//ÏßÌõ
		}
		else//·ñÔò
		{
			ofDrawLine(tx[i] + fftSmoothed[i] * 150 * cos(w), ty[i] + fftSmoothed[i] * 150 * sin(w), tx[i + 1] + fftSmoothed[i + 1] * 150 * cos(w), ty[i + 1] + fftSmoothed[i + 1] * 150 * sin(w));//ÏßÌõ
			ofDrawLine(tx[i] - fftSmoothed[i] * 150 * cos(w), ty[i] - fftSmoothed[i] * 150 * sin(w), tx[i + 1] - fftSmoothed[i + 1] * 150 * cos(w), ty[i + 1] - fftSmoothed[i + 1] * 150 * sin(w));//ÏßÌõ
		}
		w += 2 * PI / nBandsToGet;//Ôö¼Ó
	}
}
