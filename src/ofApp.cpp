#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	TestAudio::setup();
	
	ofSetFrameRate(60);
	ofSetVerticalSync(true);	
	ofDisableAntiAliasing();
	//ofSetFullscreen(true);
	ofSetCircleResolution(512);
	state = GAME;

	font.loadFont("ABSTRACT.TTF", 4);
	
	dt = 0;
	pt = ofGetElapsedTimef();
	
	
	VectorText::setup();
	gameplay.setup(&font);
}


//--------------------------------------------------------------
void ofApp::update(){
	dt = ofGetElapsedTimef() - pt;
	pt = ofGetElapsedTimef();


	switch(state) {
		case TITLE:
			break;

		case GAME:
			if(!gameplay.update(dt) ) {
				state = TITLE;
			}
			break;

		default:
			break;

	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	switch(state) {
		case TITLE:
			break;

		case GAME:
			gameplay.draw();
			break;
		
		default:
			break;
	
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(state) {
		case TITLE:
			break;

		case GAME:
			gameplay.keyPressed(key);
			break;
		
		default:
			break;
	
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch(state) {
		case TITLE:
			break;

		case GAME:
			gameplay.keyReleased(key);
			break;
		
		default:
			break;
	
	}
}
