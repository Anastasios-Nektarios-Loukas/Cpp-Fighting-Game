#pragma once
#include "gameobject.h"
#include <sgg/graphics.h>
#include "box.h"
class Player : public Box, public GameObject
{

private:
	const float m_accel_horizontal = 35.0f;
	const float m_accel_vertical = 300.1f;
	const float m_max_velocity = 10.0f;
	float move;
	class animations* animation;
	std::vector<std::string> m_sprites;
	std::vector<std::string> m_sprites_attack;
	std::vector<std::string> m_sprites_jump;
	std::vector<std::string> m_sprites_sattack;
	std::vector<std::string> m_sprites_hit;
	std::vector<std::string> m_sprites_defend;
	std::vector<std::string> m_sprites_death;
	std::vector<std::string> m_sprites_idle;
	bool jump;
	bool istakingdamage;
	bool alive;
	int idle_count;
	int hit_count;
	int at1_count;
	int at2_count;
	int jump_count;
	int def_count;
	int death_count;
	graphics::scancode_t key_at1;
	graphics::scancode_t key_at2;
	graphics::scancode_t key_jump;
	graphics::scancode_t key_forward;
	graphics::scancode_t key_backward;
	graphics::scancode_t key_defend;
	float life;
	float at1_damage;
	float at2_damage;
	int at1_count_for_special;
	int spatck;

public:
	bool dying;
	bool at1;
	bool at2;
	bool def;
	bool at1_fordamage;
	bool at2_fordamage;
	bool at_defend;
	float m_vy;
	float m_gravity;
	bool iscol;
	bool lookdirection;
public:
	graphics::Brush m_brush_player;
	float m_pos_x;
	float m_pos_y;
	void update(float dt);
	void draw();
	void init(int i);
	void setposx(float posx) { this->m_pos_x = posx; }
	void setposy(float posy) { this->m_pos_y = posy; }
	float getlife() { return life; }
	void setlife(float l) { life = l; }
	void drainlife(float amount) { life = std::max<float>(0.0f, life - amount); }
	float getat1_damage() { return at1_damage; }
	float getat2_damage() { return at2_damage; }
	void set_at1key(graphics::scancode_t key) { this->key_at1 = key; }
	void set_at2key(graphics::scancode_t key) { this->key_at2 = key; }
	void set_jumpkey(graphics::scancode_t key) { this->key_jump = key; }
	void set_forwardkey(graphics::scancode_t key) { this->key_forward = key; }
	void set_backwardkey(graphics::scancode_t key) { this->key_backward = key; }
	void set_defendkey(graphics::scancode_t key) { this->key_defend = key; }
	void set_takingdamage(bool t) { istakingdamage = t; }
	bool get_takingdamage() { return istakingdamage; }
	void set_status(bool t) { alive = t; }
	bool get_status() { return alive; }
	Player(std::string name) : GameObject(name) {}


protected:
	void debugDraw();
	void movePlayer(float dt);

};