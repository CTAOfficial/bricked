#pragma once

#include "Basic2D.h"

struct Block : public Basic2D {
public:
	 void OnContact(Basic2D& contact) override;
};