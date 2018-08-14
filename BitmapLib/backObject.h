#pragma once
#include "Object.h"

class backObject : public Object
{
public: 
	bool Update() { return true; }

public:
	backObject();
	virtual ~backObject();
};

