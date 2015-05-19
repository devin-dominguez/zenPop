#include "Entity.h"

Entity::Entity() {
	dead = false;
}

//--------------------------------------------------------------
Entity::~Entity() {}
void Entity::collision() {};
void Entity::update(double dt) {};
void Entity::draw() {};
void Entity::kill() {};

//--------------------------------------------------------------
void Entity::updateVector(vector<Entity*> &e, double dt) {
	int s = e.size();
	for(int i = 0; i < s; i++) {
		e[i]->update(dt);
	}
}

//--------------------------------------------------------------
void Entity::drawVector(vector<Entity*> &e) {
	int s = e.size();
	for(int i = 0; i < s; i++) {
		e[i]->draw();
	}
}

//--------------------------------------------------------------
void Entity::cleanupVector(vector<Entity*> &e) {
	int i = e.size();
	while(i--) {
		if(e[i]->dead) {
			delete e[i];
			e.erase(e.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void Entity::killAll(vector<Entity*> &e) {
	int s = e.size();
	for(int i = 0; i < s; i++) {
		e[i]->dead = true;
	}
}


//--------------------------------------------------------------
void Entity::collideOneToMany(Entity* e1, vector<Entity*> &e2) {
	int s = e2.size();
	for(int i = 0; i < s; i++) {
		if(checkCollision(e1, e2[i])) {
			e1->collision();
			e2[i]->collision();
		}
	}
}

//--------------------------------------------------------------
bool Entity::collideManyToOne(vector<Entity*> &e1, Entity *e2) {
	int s = e1.size();
	for(int i = 0; i < s; i++) {
		if(checkCollision(e1[i], e2)) {
			return true;
		}
	}
	return false;
}

//--------------------------------------------------------------
bool Entity::checkCollision(Entity *e1, Entity *e2) {
	float a = e1->size - e2->size;
	a *= a;
	
	float b1 = e1->pos.x - e2->pos.x;
	b1 *= b1;

	float b2 = e1->pos.y - e2->pos.y;
	b2 *= b2;

	float b = b1 + b2;
	
	float c = e1->size + e2->size;
	c *= c;

	return a <= b && b <= c;
}
