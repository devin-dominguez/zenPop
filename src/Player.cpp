#include "Player.h"

Player::Player() {
	core.size = 2;
	trigger.size = 12;
	maxSpeed = 300;
	trailTimer = 1;
	trailRate = 30;

	init();
}

void Player::init() {
	pos.set(Field::w / 2, Field::h / 2);
	speed = 0;
	direction.set(0, 0);

	KB.up = false;
	KB.down = false;
	KB.left = false;
	KB.right = false;
	KB.z = false;
}

void Player::update(double dt) {

	kbStuff();
	move(dt);

	core.pos = pos;
	trigger.pos = pos;

	int trailAmmount = trails.size();

	updateVector(trails, dt);
	cleanupVector(trails);	


	if(trailTimer > 0) {
		trailTimer -= trailRate * dt;
	}
	else {
		trailTimer = 1;
		trails.push_back(new Trail(pos, core.size));
	}

}

void Player::draw() {
	ofPushMatrix();
		ofTranslate(pos);
		core.draw();
		trigger.draw();
	ofPopMatrix();
	
	drawVector(trails);
}

void Player::move(double dt) {
	pos += direction * speed * dt;
	if(pos.x < 0) pos.x = 0;
	if(pos.x > Field::w) pos.x = Field::w;
	if(pos.y < 0) pos.y = 0;
	if(pos.y > Field::h) pos.y = Field::h;

}

void Player::removeTrail() {
	int num = trails.size();
	for(int i = 0; i < num; i++) {
		trails[i]->dead = true;

	}

}


void Player::kbStuff() {

	//figure out direction in the least elegant way possible
	if(KB.left && !(KB.up || KB.down)) 
		direction.set(-1, 0);
	if(KB.right && !(KB.up || KB.down))
		direction.set(1, 0);
	if(KB.up && !(KB.left || KB.right))
		direction.set(0, -1);
	if(KB.down && !(KB.left || KB.right))
		direction.set(0, 1);

	if(KB.left && KB.up)
		direction.set(-M_SQRT1_2, -M_SQRT1_2);
	if(KB.right && KB.up)
		direction.set(M_SQRT1_2, -M_SQRT1_2);
	if(KB.left && KB.down)
		direction.set(-M_SQRT1_2, M_SQRT1_2);
	if(KB.right && KB.down)
		direction.set(M_SQRT1_2, M_SQRT1_2);

	
	if(KB.up || KB.down || KB.left || KB.right) {
		speed = maxSpeed;
	}
	else {
		speed = 0;
	}

}


void Player::keyPressed(int key) {
	switch(key) {
		case OF_KEY_UP: //up
			KB.up = true;
			break;
		case OF_KEY_DOWN: //down
			KB.down = true;
			break;

		case OF_KEY_LEFT: //left
			KB.left = true;
			break;

		case OF_KEY_RIGHT: //right
			KB.right = true;
			break;
	}
}

void Player::keyReleased(int key) {
	switch(key) {
		case OF_KEY_UP: //up
			KB.up = false;
			break;

		case OF_KEY_DOWN: //down
			KB.down = false;
			break;

		case OF_KEY_LEFT: //left
			KB.left = false;
			break;

		case OF_KEY_RIGHT: //right
			KB.right = false;
			break;
	}
}



//--------------------------------------------------------------

void Core::draw() {
	ofPopStyle();
		ofFill();
		ofSetColor(Colors::A);
		ofCircle(0, 0, size);
	ofPushStyle();
}


void Trigger::draw() {
	ofPopStyle();
		ofNoFill();
		ofSetColor(Colors::A);
		ofCircle(0, 0, size);
	ofPushStyle();
}


//--------------------------------------------------------------
Trail::Trail(ofVec2f &pos, double size) {
	this->pos = pos;
	this->size = .5 * size;
	initSize = this->size;
	rate = .75;
	dead = false;
}

void Trail::update(double dt) {
	if(size > 0) {
		size = fmax(0, size -  rate * dt);
	}
	else {
		dead = true;
	}
}

void Trail::draw() {
	ofPushMatrix();
	ofPushStyle();
		ofTranslate(pos);
		ofFill();
		ofSetColor(Colors::A, 255 * (size / initSize) );
		ofCircle(0,0, initSize);
	ofPopStyle();
	ofPopMatrix();
}






