#pragma once
#include "ofMain.h"
#include "Entity.h"
#include "Bullet.h"
#include "Environment.h"
#include "VectorText.h"

class Target : public Entity {
	public:
		Target(int level, vector<Entity*> *bullets);
		~Target();
		void update(double dt);
		void draw();
		void collision();
		
		static const double decayRate = 36;
		static const double padding = 4;
		
		static void killAllActive(vector<Entity*> &e);

		bool active;
		static int numActive;
		static int numComplete;
		static const double fadeInRate = 10;

	private:
		ofTrueTypeFont *font;
		int level;
		int numBullet;
		double fade, fadeSig;
		double signalInit, signalSize;
		vector<Entity*> *bullets;

		bool blink;
};
