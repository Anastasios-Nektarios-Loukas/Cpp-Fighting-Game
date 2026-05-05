#pragma once
#include "gameObject.h"
#include "box.h"
#include <sgg/graphics.h>

class Enemy : public GameObject, public Box
{
private:
	float speed;
	float rotation;
	graphics::Brush enbr;
	bool onscreen = true;
public:
	float damage = 0.1f;
	float life = 1.0f;
	void update(float dt) override;
	void draw() override;
	void init() override;
	void debug();
	bool IsOnScreen() { return onscreen; }
	Enemy(std::string name) : GameObject(name) { }
	~Enemy();
};