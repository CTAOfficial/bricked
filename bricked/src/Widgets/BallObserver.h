#pragma once
#include "Widget.h"

class Ball;

class BallObserver : public Widget {
private:
	Ball* ball;

protected:
	void OnDraw() override;

public:
	BallObserver(Ball* ball) : Widget("Ball Observer"), ball(ball) {
	}

};