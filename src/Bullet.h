#pragma once

#include "ofMain.h"
#include "Entity.h"
#include "Environment.h"


class Bullet : public Entity {
	public:
		Bullet(ofVec2f pos, ofVec2f dir);
		static const double speed = 120;
		static const double decayRate = 1;

		static int numComplete;

		void update(double dt);
		void draw();
		void kill();
	private:

		vector<Entity*> debris;
		ofVec2f dir;
		bool dying;
		float timeLeft;
};
