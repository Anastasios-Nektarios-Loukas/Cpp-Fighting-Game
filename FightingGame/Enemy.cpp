#include "Enemy.h"
#include <random>
#include "util.h"
#include "GameState.h"
#include "Player.h"

void Enemy::update(float dt)
{
	m_pos_x -= speed * dt / 1000.0f;
	rotation += 10.0f * dt / 1000.0f;
	rotation = fmodf(rotation, 360);
	if (m_pos_x < -5 || life == 0.0f) {
		onscreen = false;
	}
	GameObject::update(dt);
}

void Enemy::draw()
{
	graphics::setScale(1.0f, 1.0f);
	graphics::setOrientation(rotation);
	graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, enbr);
	if (life != 0)
		enbr.texture = m_state->getFullAssetPath("fireball.png");
	else
		enbr.texture = m_state->getFullAssetPath("fireballdeath.png");
	enbr.fill_opacity = 1.0f;
	graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, enbr);
	graphics::resetPose();
	if (m_state->m_debugging)
		debug();
}

void Enemy::init()
{
	m_width = 2;
	m_height = 2;
	speed = 1.0f;
	m_pos_x = 24;
	m_pos_y = m_state->getPlayer_Viking()->m_pos_y + 2.0f;
	rotation = 360 * rand() / (float)RAND_MAX;
	enbr.outline_opacity = 0.0f;
}

void Enemy::debug()
{
	graphics::Brush debug_brush;
	SETCOLOR(debug_brush.fill_color, 1, 0.3f, 0);
	SETCOLOR(debug_brush.outline_color, 1, 0.1f, 0);
	debug_brush.fill_opacity = 0.1f;
	debug_brush.outline_opacity = 0.5f;
	graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, debug_brush);
}


Enemy::~Enemy()
{
}