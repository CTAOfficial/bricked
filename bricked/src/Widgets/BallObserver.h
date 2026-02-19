#pragma once

class Ball;

class BallObserver {
public:
	BallObserver(Ball* ball) : ball(ball) {
	}

	Ball* ball;

	void Draw();
};