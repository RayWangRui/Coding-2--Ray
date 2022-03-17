#include "ofApp.h"
#include "maximilian.h"


maxiOsc myOsc;
maxiOsc myOsc2;
maxiOsc myOsc3;
maxiOsc myOsc4;
maxiOsc myOsc5;
maxiOsc myOsc6;

//--------------------------------------------------------------
void ofApp::setup(){
    myOsc = maxiOsc();
    myOsc2 = maxiOsc();
    myOsc3 = maxiOsc();
    myOsc4 = maxiOsc();
    myOsc5 = maxiOsc();
    myOsc6 = maxiOsc();
    
    mouseX =20;
    mouseY =20;
    
    counter = 0;
    segments = 1500;
    //myOsc.
    ofSoundStreamSettings settings;
    settings.numOutputChannels = 2;
    settings.sampleRate = 44100;
    settings.bufferSize = 512;
    settings.numBuffers = 4;
    settings.setOutListener(this);
    soundStream.setup(settings);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    double spacing = TWO_PI / segments;

    double spacing1 = TWO_PI / segments;
    int radius = 300;
    
    waveform.clear();
    for (int i = 0; i < 5*segments; i++)
    {
        int x;
        int y;

        x = sin(spacing * i * (mouseX/100)) * radius;
        y = cos(spacing * i* (mouseX/100)) * sin(spacing * i * (mouseY/20)) * cos(spacing * i* (mouseX/200))*radius;
        if(1<x && x<20) ofSetColor(0, 255, 255);
        if(20<x && x<40 ) ofSetColor(0x5c, 0xad, 0xad);
        if(40<y && y<60) ofSetColor(0xbb, 255, 255);
        if(60<y && y<80 )ofSetColor(0x80, 255, 255);
        if(x>80 )ofSetColor(0xff, 0xe6, 0x6f);
        waveform.addVertex(x+radius+20, y+radius+50);
    }
    
    ofBackground(ofColor::black);
    waveform.draw();
}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer &outBuffer) {
    
    for (int i=0; i<512; i++) {
//        double sum = myOsc.sinewave(myOsc4.sinewave(220) )+
//                      myOsc3.sinewave(myOsc5.sinewave(440) * 0.3 + myOsc6.saw(myOsc4.sinewave(550)));
//        double out = sum * 1000;
        
        double averageOutput = 0;
        double o1 = myOsc4.sinewave(220);
        double o2 = myOsc5.sinewave(440);
        double o3 = myOsc4.sinewave(550);
        averageOutput = (o1+o2+o3) * 0.3;
        //averageOutput+=out;
        outBuffer.getSample(i, 0) = averageOutput;
        outBuffer.getSample(i, 1) = averageOutput;
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
    mouseX = x;
    mouseY = y;
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

