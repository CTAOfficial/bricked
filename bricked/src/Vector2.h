#pragma once

struct Vector2 {
public:
	Vector2(){}
	Vector2(float x) {
		X = x;
	}
	Vector2(float x, float y) {
		X = x;
		Y = y;
	}

	float X = 0;
	float Y = 0;


};