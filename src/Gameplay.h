#pragma once

#include "ofMain.h"
#include "Entity.h"
#include "Player.h"
#include "Target.h"
#include "Bullet.h"
#include "Environment.h"
#include "TestAudio.h"

class Gameplay {

	public:
		void setup(ofTrueTypeFont *font);
		bool update(double dt);
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

		

		void init();
		
	private:
		int level;
		void makeWave();

		void deathStuff();

		void drawData();


		ofTrueTypeFont *font;

		double timeScale, timeTarget;
		
		bool flash;

		Player *player;
		vector<Entity*> targets;
		vector<Entity*> bullets;

		bool paused;		
};
	
