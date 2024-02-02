#pragma once
#include "Scene_Base.h"

class Scene_Title : 
	public Scene_Base {

public:

	Scene_Title(){

	}

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
};

