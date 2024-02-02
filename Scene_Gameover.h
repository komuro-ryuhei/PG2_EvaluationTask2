#pragma once
#include "Scene_Base.h"

class Scene_Gameover :
	public Scene_Base {

public:

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

};

