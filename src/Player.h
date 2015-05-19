#pragma once
#include "ofMain.h"
#include "Entity.h"
#include "Environment.h"

class Trigger : public Entity {
	public:
		void draw();
};

//--------------------------------------------------------------
class Core : public Entity {
	public:
		void draw();
};


//--------------------------------------------------------------
class Trail : public Entity{
	public:
		Trail(ofVec2f &pos, double size);
	   	void update(double dt);
		void draw();
	private:
		double rate;
		double initSize;
};


//--------------------------------------------------------------
class Player : public Entity {
	public:
		Player();
		void init();
		
		void update(double dt);
		void draw();

		void move(double dt);
		void keyPressed(int key);
		void keyReleased(int key);

		Core core;	
		Trigger trigger;
	
		void removeTrail();
	private:
	

		double trailTimer, trailRate;
		vector<Entity*> trails;


		double speed, maxSpeed;
		ofVec2f direction;

		void kbStuff();
		struct  {
			bool up,
				 down,
				 left,
				 right,
				 z;
		} KB;




};


