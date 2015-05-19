#pragma once
#include "ofMain.h"

class VectorText {
	public:
		static void setup();
		static void drawChar(unsigned char c, int x, int y, double size);
		static void drawCenter(string str, int x, int y, double size);
		static void drawLeft(string str, int x, int y, double size);

	private:
		static map<char, vector<ofPoint> > characters;
};
