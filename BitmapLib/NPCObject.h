#pragma once
#include "Object.h"

class NPCObject : public Object
{
public:
	bool Update();

public:
	NPCObject();
	virtual ~NPCObject();
};

