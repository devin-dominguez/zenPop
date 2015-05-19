#include "Gameplay.h"

//--------------------------------------------------------------
void Gameplay::setup(ofTrueTypeFont *font){
	Colors::setup();

	player = new Player();
	
	this->font = font;


	init();
}


//--------------------------------------------------------------
void Gameplay::init() {
	Bullet::numComplete = 0;
	Target::numComplete = 0;
	timeScale = 1;
	timeTarget = 1;
	flash = false;

	player->init();	
	Score::init();
	makeWave();
	paused = false;
}

//--------------------------------------------------------------
void Gameplay::makeWave() {

	for(int i = 1; i <= Score::level; i++) {
		for(int j = 0; j < (Score::level - i) + 2; j++) {

			targets.push_back(new Target( i, &bullets));
		
		}
	}

}

//--------------------------------------------------------------
bool Gameplay::update(double dt){
	//time stuff

	if(!paused) {
		TestAudio::gameplayUpdate();

		timeScale = .8 * timeScale + .2 * timeTarget;
		
		
		
		dt *= timeScale * .75 + .25;
		//update entites
		player->update(dt);
		
		Target::numActive = 0;
		Entity::updateVector(targets, dt);
		
		Entity::updateVector(bullets, dt);
		

		//collision stuff
		Entity::collideOneToMany(&player->trigger, targets);
		if(Entity::collideManyToOne(bullets, &player->core) ){
			deathStuff();
		}

		Score::rate = 1.0 / (timeScale * .975 + .025);
		Score::update(dt);
		
		if(targets.size() == 0) {
			Score::level++;
			Score::addTime(2);
			makeWave();
		}

		//clean up entity vectors
		Entity::cleanupVector(targets);
		Entity::cleanupVector(bullets);



		if(Score::timeLeft > 0) {
			return true;
		}
		else {
			return false;
		}
	}
}

//--------------------------------------------------------------
void Gameplay::draw(){
	
	ofBackground(Colors::bg);
	
	ofSetColor(255);
	
	ofPushMatrix();
		ofTranslate(Field::x, Field::y);

		drawData();

		Score::draw();
		Entity::drawVector(targets);
		Entity::drawVector(bullets);
		player->draw();
	ofPopMatrix();
	Field::draw();

	if(flash) {
		ofBackground(Colors::flash);
		flash = false;
	}
}

//--------------------------------------------------------------
void Gameplay::drawData() {

	ofPushStyle();

		ofSetColor(Colors::A);
		stringstream info;
		info << "Targets: " << targets.size() 		<< endl << endl
			 << "Bullets: " << bullets.size() 		<< endl << endl
			 << "Active:  "	<< Target::numActive 	<< endl << endl
			 << "ScoreA:  "	<< Bullet::numComplete 	<< endl << endl
			 << "ScoreB:  "	<< Target::numComplete 	<< endl << endl
			 << "Level:   "	<< Score::level 		<< endl << endl
			 << "SCORE:   "	<< Score::score			<< endl << endl
			 << "TIME:    "	<< Score::timeLeft		<< endl << endl
			 << "Multi:   "	<< Score::multi			<< endl;
		
		//font->drawString(info.str(), 8 , -96);
		int s = 8;	
		int offset = -36;
		VectorText::drawLeft("Level    " + ofToString(Score::level), 		8, s * 1 + offset, s);
		VectorText::drawLeft("Score    " + ofToString(Score::score), 		8, s * 2 + offset, s);
		VectorText::drawLeft("Multi    " + ofToString(Score::multi), 		8, s * 3 + offset, s);

	ofPopStyle();

}


//--------------------------------------------------------------
void Gameplay::deathStuff() {
	Entity::killAll(bullets);
	Target::killAllActive(targets);
	player->removeTrail();	
	flash = true;

	Score::deathStuff();

}




//--------------------------------------------------------------
void Gameplay::keyPressed(int key){
	switch(key) {
		case 'z':
			timeTarget = 0;
			break;
		case 'p':
			paused = !paused;

		default:
			player->keyPressed(key);

	}
}
//--------------------------------------------------------------
void Gameplay::keyReleased(int key){
	switch(key) {
		case 'z':
			timeTarget = 1;
			break;

		default:
			player->keyReleased(key);
	}
}
