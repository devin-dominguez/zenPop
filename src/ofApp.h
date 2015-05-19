#pragma once

#include "ofMain.h"
#include "Entity.h"
#include "Player.h"
#include "VectorText.h"
#include "Gameplay.h"
#include "TestAudio.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

		ofTrueTypeFont font;

		Gameplay gameplay;
	
		double dt, pt;
		
		enum {
			TITLE,
			GAME
		} state;
};
