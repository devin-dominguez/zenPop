#pragma once
#include "ofMain.h"

struct Field {
	static const int x = 50;
	static const int y = 120;
   	static const int w = 700;
	static const int h = 700;
	static void draw();
};


//--------------------------------------------------------------
struct Colors {
	static void setup();
	static ofColor A, B, C, D, E, bg, flash;
};

//--------------------------------------------------------------
struct Score {
	static void init();
	static void update(double dt);
	static void draw();
	static void deathStuff();
	static int level;

	static int score;
	static int  multi;

	static void addTime(double t);
	static void addPoints(int p);
	static const double maxTime = 30;
	static const double bonusTime = 28;
	static const double deathPenalty = 7.5;
	static double timeLeft;
	static double rate, baseRate;
	static bool blink;
};
