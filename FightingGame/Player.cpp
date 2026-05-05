#include "Player.h"
#include "util.h"
#include <cmath>
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include "Animations.h"



void Player::update(float dt)
{
	if (!at1 && !at2) movePlayer(dt);
	if (life == 0) { alive = false;}
	GameObject::update(dt);
}

void Player::draw()
{
	if (lookdirection)
		graphics::setScale(1.0f, 1.0f);
	else if (!lookdirection)
		graphics::setScale(-1.0f, 1.0f);
	else
		graphics::setScale(1.0f, 1.0f);


	if (alive) {
		if (istakingdamage) {
			at1 = false;
			at2 = false;
			jump = false;
			def = false;
			at1_count = 0;
			at2_count = 0;
			jump_count = 0;
			def_count = 0;
			if (hit_count == m_sprites_hit.size() - 1) {
				hit_count = 0;
				istakingdamage = false;
			}
			else if (istakingdamage) {
				m_brush_player.texture = m_sprites_hit[hit_count];
				if (hit_count == 5) {}
				std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(70));
				hit_count++;
			}
		}


		if (!at1 && !at2 && !jump && !def && !istakingdamage) {
			if (graphics::getKeyState(key_backward) || graphics::getKeyState(key_forward)) {
				int s = fmodf(m_pos_x, m_sprites.size());
				m_brush_player.texture = m_sprites[s];
			}
			else {
				if (idle_count == m_sprites_idle.size() - 1) {
					idle_count = 0;
				}
				else {
					m_brush_player.texture = m_sprites_idle[idle_count];
					std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(70));
					idle_count++;
				}
			}
		}


		if (!at2 && !jump && !def) {
			if (at1_count == m_sprites_attack.size() - 1) {
				at1_count = 0;
				at1 = false;
			}
			else if (graphics::getKeyState(key_at1) && !at1) {
				at1 = true;
				graphics::playMusic(m_state->getFullAssetPath("sword.mp3"), 0.7f, false, 500);
				at1_count_for_special++;
				if (at1_count_for_special == 5) {
					spatck++;
					at1_count_for_special = 0;
				}

			}
			else if (at1) {
				m_brush_player.texture = m_sprites_attack[at1_count];
				std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(70));
				at1_count++;
				if (at1_count == 2) { at1_fordamage = true; }
				else if (at1_count == 3) { at1_fordamage = false; }

			}
		}


		if (!at1 && !at2 && !def && !istakingdamage) {
			if (jump_count == m_sprites_jump.size() - 1) {
				jump_count = 0;
				jump = false;
			}
			else if (graphics::getKeyState(key_jump) && !jump) {
				jump = true;
			}
			else if (jump) {
				m_brush_player.texture = m_sprites_jump[jump_count];
				std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(70));
				jump_count++;
			}
		}


		if (!at1 && !jump && !def && !istakingdamage) {
			if (at2_count == m_sprites_sattack.size() - 1) {
				at2_count = 0;
				at2 = false;
				spatck=0;
			}
			else if (graphics::getKeyState(key_at2) && !at2 && spatck >= 1) {
				at2 = true;
				graphics::playMusic(m_state->getFullAssetPath("sword.mp3"), 0.9f, false, 300);
			}
			else if (at2) {
				m_brush_player.texture = m_sprites_sattack[at2_count];
				std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(70));
				at2_count++;
				if (at2_count == 2) { at2_fordamage = true; }
				else if (at2_count == 3) { at2_fordamage = false; }
			}
		}

		if (!at1 && !at2 && !jump && !istakingdamage) {
			if (def_count == m_sprites_defend.size() - 1) {
				def_count = 0;
				def = false;
				at_defend = false;
			}
			else if (graphics::getKeyState(key_defend) && !def) {
				def = true;
				at_defend = true;
			}
			else if (def) {
				m_brush_player.texture = m_sprites_defend[def_count];
				std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(70));
				def_count++;
			}
		}
	}
	else {
		if (dying) {
			if (death_count == m_sprites_death.size() - 1) {
				alive = false;
				dying = false;
				death_count = 0;
			}
			else {
				m_brush_player.texture = m_sprites_death[death_count];
				std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(70));
				death_count++;
			}
		}
		
	}
		
	
	graphics::drawRect(m_pos_x, m_pos_y, 8.0f, 8.0f, m_brush_player);

	if (m_state->m_debugging)
		debugDraw();


}

void Player::init(int i) {
	m_sprites.clear();
	m_sprites_attack.clear();
	m_sprites_death.clear();
	m_sprites_defend.clear();
	m_sprites_hit.clear();
	m_sprites_idle.clear();
	m_sprites_jump.clear();
	m_sprites_sattack.clear();
	animation = new animations();
	i = i;
	if (i == 1) {
		animation->init_1(m_sprites, m_sprites_attack, m_sprites_jump, m_sprites_sattack, m_sprites_defend, m_sprites_hit, m_sprites_death, m_sprites_idle);

	}
	else {
		animation->init_2(m_sprites, m_sprites_attack, m_sprites_jump, m_sprites_sattack, m_sprites_defend, m_sprites_hit, m_sprites_death, m_sprites_idle);

	}
	m_brush_player.fill_opacity = 1.0f;
	m_brush_player.outline_opacity = 0.0f;
	m_width = 3.0f;
	m_height = 3.0f;
	life = 1.0f;
	jump = false;
	istakingdamage = false;
	alive = true;
	idle_count = 0;
	hit_count = 0;
	at1_count = 0;
	at2_count = 0;
	jump_count = 0;
	def_count = 0;
	death_count = 0;
	at1_damage = 0.10f;
	at2_damage = 0.20f;
	at1_count_for_special = 0;
	spatck = 0;
	m_vy = 0.0f;
	m_gravity = 4.0f;
	iscol = false;
	at1 = false;
	at2 = false;
	def = false;
	at1_fordamage = false;
	at2_fordamage = false;
	at_defend = false;
	dying = true;
}



void Player::debugDraw()
{
	graphics::Brush debug_brush;
	SETCOLOR(debug_brush.fill_color, 1, 0.3f, 0);
	SETCOLOR(debug_brush.outline_color, 1, 0.1f, 0);
	debug_brush.fill_opacity = 0.1f;
	debug_brush.outline_opacity = 0.5f;
	graphics::drawRect(m_pos_x, m_pos_y * 1.35f, 3.0f, 3.0f, debug_brush);
}


void Player::movePlayer(float dt)
{
	if (get_status()) {
		float delta_time = dt / 1000.0f;

		move = 0.0f;
		if (graphics::getKeyState(key_backward)) {
			lookdirection = false;
			move -= 1.0f;
		}
		if (graphics::getKeyState(key_forward)) {
			lookdirection = true;
			move = 1.0f;
		}

		m_pos_x += move * 8 * delta_time;
		if (m_pos_x < 0.5f) { m_pos_x = 0.5; }
		else if (m_pos_x > 21.5) { m_pos_x = 21.5; }

		if (fabs(m_vy) > 12.5f)
			m_vy = 0;


		if (m_vy == 0.0f)
			if (graphics::getKeyState(key_jump)) {
				m_gravity = 4.0f;
				m_vy -= 8;
			}

		m_vy += delta_time * 2 * m_gravity;

		m_pos_y += m_vy * delta_time;
		if (m_pos_y < 0.0f) { m_pos_y = 0.0f; }
	}
}