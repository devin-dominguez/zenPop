#pragma once
#include "ofMain.h"

class Entity {
	public:
		Entity();
	
		ofVec2f pos;
		float size;
		bool dead;

		virtual ~Entity();
		virtual void collision();
		virtual void kill();


		virtual void update(double dt);
		virtual void draw();

		static void updateVector(vector<Entity*> &e, double dt);
		static void drawVector(vector<Entity*> &e);
		static void cleanupVector(vector<Entity*> &e);
		static void killAll(vector<Entity*> &e);

		static void collideOneToMany(Entity *e1, vector<Entity*> &e2);
		static bool collideManyToOne(vector<Entity*> &e1, Entity *e2);
		static bool checkCollision(Entity *e1, Entity *e2);
};
