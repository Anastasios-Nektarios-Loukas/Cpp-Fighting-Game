#include "Level.h"
#include <sgg/graphics.h>
#include "Player.h"
#include "Enemy.h"
#include "util.h"




void Level::drawBlock(int i)
{
	Box& box = m_blocks[i];
	std::string& name = m_block_names[i];

	float x = box.m_pos_x;
	float y = box.m_pos_y;
	float z = box.m_width;
	float e = box.m_height + box.m_height * 1.1f;

	m_block_brush.texture = m_state->getFullAssetPath(name);

	graphics::drawRect(x, y, z, e, m_block_brush);

	if (m_state->m_debugging)
		graphics::drawRect(x, y, box.m_width, box.m_height, m_block_brush_debug);

}

void Level::checkCollisions()
{
	if (((m_state->getPlayer()->m_pos_x - m_state->getPlayer()->m_width / 2 <= m_state->getPlayer_Viking()->m_pos_x + m_state->getPlayer_Viking()->m_width / 2)
		&& (m_state->getPlayer()->m_pos_x - m_state->getPlayer()->m_width / 2 >= m_state->getPlayer_Viking()->m_pos_x - m_state->getPlayer_Viking()->m_width / 2))
		&& (m_state->getPlayer()->m_pos_y - m_state->getPlayer()->m_height / 2 <= m_state->getPlayer_Viking()->m_pos_y + m_state->getPlayer_Viking()->m_height / 2)
		&& (m_state->getPlayer()->m_pos_y - m_state->getPlayer()->m_height / 2 >= m_state->getPlayer_Viking()->m_pos_y - m_state->getPlayer_Viking()->m_height / 2)
		||
		((m_state->getPlayer()->m_pos_x + m_state->getPlayer()->m_width / 2 >= m_state->getPlayer_Viking()->m_pos_x - m_state->getPlayer_Viking()->m_width / 2)
			&& (m_state->getPlayer()->m_pos_x + m_state->getPlayer()->m_width / 2 <= m_state->getPlayer_Viking()->m_pos_x + m_state->getPlayer_Viking()->m_width / 2)
			&& (m_state->getPlayer()->m_pos_y - m_state->getPlayer()->m_height / 2 <= m_state->getPlayer_Viking()->m_pos_y + m_state->getPlayer_Viking()->m_height / 2)
			&& (m_state->getPlayer()->m_pos_y - m_state->getPlayer()->m_height / 2 >= m_state->getPlayer_Viking()->m_pos_y - m_state->getPlayer_Viking()->m_height / 2))
		||
		((m_state->getPlayer()->m_pos_x - m_state->getPlayer()->m_width / 2 <= m_state->getPlayer_Viking()->m_pos_x + m_state->getPlayer_Viking()->m_width / 2)
			&& (m_state->getPlayer()->m_pos_x - m_state->getPlayer()->m_width / 2 >= m_state->getPlayer_Viking()->m_pos_x - m_state->getPlayer_Viking()->m_width / 2))
		&& (m_state->getPlayer()->m_pos_y + m_state->getPlayer()->m_height / 2 <= m_state->getPlayer_Viking()->m_pos_y + m_state->getPlayer_Viking()->m_height / 2)
		&& (m_state->getPlayer()->m_pos_y + m_state->getPlayer()->m_height / 2 >= m_state->getPlayer_Viking()->m_pos_y - m_state->getPlayer_Viking()->m_height / 2)
		||
		((m_state->getPlayer()->m_pos_x + m_state->getPlayer()->m_width / 2 >= m_state->getPlayer_Viking()->m_pos_x - m_state->getPlayer_Viking()->m_width / 2)
			&& (m_state->getPlayer()->m_pos_x + m_state->getPlayer()->m_width / 2 <= m_state->getPlayer_Viking()->m_pos_x + m_state->getPlayer_Viking()->m_width / 2)
			&& (m_state->getPlayer()->m_pos_y + m_state->getPlayer()->m_height / 2 <= m_state->getPlayer_Viking()->m_pos_y + m_state->getPlayer_Viking()->m_height / 2)
			&& (m_state->getPlayer()->m_pos_y + m_state->getPlayer()->m_height / 2 >= m_state->getPlayer_Viking()->m_pos_y - m_state->getPlayer_Viking()->m_height / 2))
		) {

		if (m_state->getPlayer()->at1_fordamage) {
			if (!m_state->getPlayer_Viking()->at_defend) {
				m_state->getPlayer_Viking()->set_takingdamage(true);
				graphics::playMusic(m_state->getFullAssetPath("hit.mp3"), 1.0f, false, 500);
				m_state->getPlayer_Viking()->drainlife(m_state->getPlayer_Viking()->getat1_damage());
				if ((m_state->getPlayer_Viking()->getlife()) <= 0.0f) {
					m_state->getPlayer_Viking()->set_status(false);
				}
			}
		}


		if (m_state->getPlayer()->at2_fordamage) {
			if (!m_state->getPlayer_Viking()->at_defend) {
				m_state->getPlayer_Viking()->set_takingdamage(true);
				graphics::playMusic(m_state->getFullAssetPath("hit.mp3"), 1.0f, false, 500);
				m_state->getPlayer_Viking()->drainlife(m_state->getPlayer_Viking()->getat2_damage());
				if ((m_state->getPlayer_Viking()->getlife()) <= 0.0f) {
					m_state->getPlayer_Viking()->set_status(false);
				}
			}
			else {
				graphics::playMusic(m_state->getFullAssetPath("swordhit.mp3"), 0.8f, false, 500);;
				m_state->getPlayer_Viking()->drainlife(0.1f);
				if ((m_state->getPlayer_Viking()->getlife()) <= 0.0f) {
					m_state->getPlayer_Viking()->set_status(false);
				}
			}
		}

		if (m_state->getPlayer_Viking()->at1_fordamage) {
			if (!m_state->getPlayer()->at_defend) {
				m_state->getPlayer()->set_takingdamage(true);
				graphics::playMusic(m_state->getFullAssetPath("hit.mp3"), 1.0f, false, 500);
				m_state->getPlayer()->drainlife(m_state->getPlayer()->getat1_damage());
				if ((m_state->getPlayer()->getlife()) <= 0.0f) {
					m_state->getPlayer()->set_status(false);
				}

			}
		}
		if (m_state->getPlayer_Viking()->at2_fordamage) {
			if (!m_state->getPlayer()->at_defend) {
				m_state->getPlayer()->set_takingdamage(true);
				graphics::playMusic(m_state->getFullAssetPath("hit.mp3"), 1.0f, false, 500);
				m_state->getPlayer()->drainlife(m_state->getPlayer()->getat2_damage());
				if ((m_state->getPlayer()->getlife()) <= 0.0f) {
					m_state->getPlayer()->set_status(false);
				}
			}
			else {
				graphics::playMusic(m_state->getFullAssetPath("swordhit.mp3"), 0.8f, false, 500);
				m_state->getPlayer()->drainlife(0.1f);
				if ((m_state->getPlayer()->getlife()) <= 0.0f) {
					m_state->getPlayer()->set_status(false);
				}

			}
		}


	}


	for (auto& block : m_blocks)
	{

		if (m_state->getPlayer_Viking()->m_pos_y + m_state->getPlayer_Viking()->m_height / 2 >= block.m_pos_y - block.m_height / 2 &&
			m_state->getPlayer_Viking()->m_pos_y + m_state->getPlayer_Viking()->m_height / 2 <= block.m_pos_y + block.m_height / 2 &&
			m_state->getPlayer_Viking()->m_pos_x <= block.m_pos_x + block.m_width / 2 &&
			m_state->getPlayer_Viking()->m_pos_x >= block.m_pos_x - block.m_width / 2)
		{
			m_state->getPlayer_Viking()->m_gravity = 0.0f;
			block.iscol = true;
			m_state->getPlayer_Viking()->m_pos_y = block.m_pos_y - (block.m_height) - (m_state->getPlayer_Viking()->m_height);
			m_state->getPlayer_Viking()->m_vy = 0.0f;
			break;
		}
		else if ((m_state->getPlayer_Viking()->m_pos_x > block.m_pos_x + block.m_width / 2 ||
				m_state->getPlayer_Viking()->m_pos_x < block.m_pos_x - block.m_width / 2))
		{
			if (block.iscol) {
				block.iscol = false;
				m_state->getPlayer_Viking()->m_gravity = 4.0f;
			}
			break;
		}
	}

	for (auto& block : m_blocks)
	{

		if (m_state->getPlayer()->m_pos_y + m_state->getPlayer()->m_height / 2 >= block.m_pos_y - block.m_height / 2 &&
			m_state->getPlayer()->m_pos_y + m_state->getPlayer()->m_height / 2 <= block.m_pos_y + block.m_height / 2 &&
			m_state->getPlayer()->m_pos_x <= block.m_pos_x + block.m_width / 2 &&
			m_state->getPlayer()->m_pos_x >= block.m_pos_x - block.m_width / 2)
		{
			m_state->getPlayer()->m_gravity = 0.0f;
			block.iscolb = true;
			m_state->getPlayer()->m_pos_y = block.m_pos_y - (block.m_height) - (m_state->getPlayer()->m_height);
			m_state->getPlayer()->m_vy = 0.0f;
			break;
		}
		else if ((m_state->getPlayer()->m_pos_x > block.m_pos_x + block.m_width / 2 ||
				m_state->getPlayer()->m_pos_x < block.m_pos_x - block.m_width / 2))
		{
			if (block.iscolb) {
				block.iscolb = false;
				m_state->getPlayer()->m_gravity = 4.0f;
			}
			break;
		}
	}

	if (levelcontrol == "levelmedium") {
		if (((m_state->getPlayer()->m_pos_x - m_state->getPlayer()->m_width / 2 <= m_state->getenemy()->m_pos_x + m_state->getenemy()->m_width / 2)
			&& (m_state->getPlayer()->m_pos_x - m_state->getPlayer()->m_width / 2 >= m_state->getenemy()->m_pos_x - m_state->getenemy()->m_width / 2))
			&& (m_state->getPlayer()->m_pos_y - m_state->getPlayer()->m_height / 2 <= m_state->getenemy()->m_pos_y + m_state->getenemy()->m_height / 2)
			&& (m_state->getPlayer()->m_pos_y - m_state->getPlayer()->m_height / 2 >= m_state->getenemy()->m_pos_y - m_state->getenemy()->m_height / 2)
			||
			((m_state->getPlayer()->m_pos_x + m_state->getPlayer()->m_width / 2 >= m_state->getenemy()->m_pos_x - m_state->getenemy()->m_width / 2)
				&& (m_state->getPlayer()->m_pos_x + m_state->getPlayer()->m_width / 2 <= m_state->getenemy()->m_pos_x + m_state->getenemy()->m_width / 2)
				&& (m_state->getPlayer()->m_pos_y - m_state->getPlayer()->m_height / 2 <= m_state->getenemy()->m_pos_y + m_state->getenemy()->m_height / 2)
				&& (m_state->getPlayer()->m_pos_y - m_state->getPlayer()->m_height / 2 >= m_state->getenemy()->m_pos_y - m_state->getenemy()->m_height / 2))
			||
			((m_state->getPlayer()->m_pos_x - m_state->getPlayer()->m_width / 2 <= m_state->getenemy()->m_pos_x + m_state->getenemy()->m_width / 2)
				&& (m_state->getPlayer()->m_pos_x - m_state->getPlayer()->m_width / 2 >= m_state->getenemy()->m_pos_x - m_state->getenemy()->m_width / 2))
			&& (m_state->getPlayer()->m_pos_y + m_state->getPlayer()->m_height / 2 <= m_state->getenemy()->m_pos_y + m_state->getenemy()->m_height / 2)
			&& (m_state->getPlayer()->m_pos_y + m_state->getPlayer()->m_height / 2 >= m_state->getenemy()->m_pos_y - m_state->getenemy()->m_height / 2)
			||
			((m_state->getPlayer()->m_pos_x + m_state->getPlayer()->m_width / 2 >= m_state->getenemy()->m_pos_x - m_state->getenemy()->m_width / 2)
				&& (m_state->getPlayer()->m_pos_x + m_state->getPlayer()->m_width / 2 <= m_state->getenemy()->m_pos_x + m_state->getenemy()->m_width / 2)
				&& (m_state->getPlayer()->m_pos_y + m_state->getPlayer()->m_height / 2 <= m_state->getenemy()->m_pos_y + m_state->getenemy()->m_height / 2)
				&& (m_state->getPlayer()->m_pos_y + m_state->getPlayer()->m_height / 2 >= m_state->getenemy()->m_pos_y - m_state->getenemy()->m_height / 2))
			) {
			m_state->getenemy()->life = 0.0f;
			m_state->getPlayer()->set_takingdamage(true);
			graphics::playMusic(m_state->getFullAssetPath("hit.mp3"), 1.0f, false, 500);
			m_state->getPlayer()->drainlife(m_state->getenemy()->damage);
			if ((m_state->getPlayer()->getlife()) <= 0.0f) {
				m_state->getPlayer()->set_status(false);
			}
		}

		if (((m_state->getPlayer_Viking()->m_pos_x - m_state->getPlayer_Viking()->m_width / 2 <= m_state->getenemy()->m_pos_x + m_state->getenemy()->m_width / 2)
			&& (m_state->getPlayer_Viking()->m_pos_x - m_state->getPlayer_Viking()->m_width / 2 >= m_state->getenemy()->m_pos_x - m_state->getenemy()->m_width / 2))
			&& (m_state->getPlayer_Viking()->m_pos_y - m_state->getPlayer_Viking()->m_height / 2 <= m_state->getenemy()->m_pos_y + m_state->getenemy()->m_height / 2)
			&& (m_state->getPlayer_Viking()->m_pos_y - m_state->getPlayer_Viking()->m_height / 2 >= m_state->getenemy()->m_pos_y - m_state->getenemy()->m_height / 2)
			||
			((m_state->getPlayer_Viking()->m_pos_x + m_state->getPlayer_Viking()->m_width / 2 >= m_state->getenemy()->m_pos_x - m_state->getenemy()->m_width / 2)
				&& (m_state->getPlayer_Viking()->m_pos_x + m_state->getPlayer_Viking()->m_width / 2 <= m_state->getenemy()->m_pos_x + m_state->getenemy()->m_width / 2)
				&& (m_state->getPlayer_Viking()->m_pos_y - m_state->getPlayer_Viking()->m_height / 2 <= m_state->getenemy()->m_pos_y + m_state->getenemy()->m_height / 2)
				&& (m_state->getPlayer_Viking()->m_pos_y - m_state->getPlayer_Viking()->m_height / 2 >= m_state->getenemy()->m_pos_y - m_state->getenemy()->m_height / 2))
			||
			((m_state->getPlayer_Viking()->m_pos_x - m_state->getPlayer_Viking()->m_width / 2 <= m_state->getenemy()->m_pos_x + m_state->getenemy()->m_width / 2)
				&& (m_state->getPlayer_Viking()->m_pos_x - m_state->getPlayer_Viking()->m_width / 2 >= m_state->getenemy()->m_pos_x - m_state->getenemy()->m_width / 2))
			&& (m_state->getPlayer_Viking()->m_pos_y + m_state->getPlayer_Viking()->m_height / 2 <= m_state->getenemy()->m_pos_y + m_state->getenemy()->m_height / 2)
			&& (m_state->getPlayer_Viking()->m_pos_y + m_state->getPlayer_Viking()->m_height / 2 >= m_state->getenemy()->m_pos_y - m_state->getenemy()->m_height / 2)
			||
			((m_state->getPlayer_Viking()->m_pos_x + m_state->getPlayer_Viking()->m_width / 2 >= m_state->getenemy()->m_pos_x - m_state->getenemy()->m_width / 2)
				&& (m_state->getPlayer_Viking()->m_pos_x + m_state->getPlayer_Viking()->m_width / 2 <= m_state->getenemy()->m_pos_x + m_state->getenemy()->m_width / 2)
				&& (m_state->getPlayer_Viking()->m_pos_y + m_state->getPlayer_Viking()->m_height / 2 <= m_state->getenemy()->m_pos_y + m_state->getenemy()->m_height / 2)
				&& (m_state->getPlayer_Viking()->m_pos_y + m_state->getPlayer_Viking()->m_height / 2 >= m_state->getenemy()->m_pos_y - m_state->getenemy()->m_height / 2))
			) {
			m_state->getenemy()->life = 0.0f;
			m_state->getPlayer_Viking()->set_takingdamage(true);
			graphics::playMusic(m_state->getFullAssetPath("hit.mp3"), 1.0f, false, 500);
			m_state->getPlayer_Viking()->drainlife(m_state->getenemy()->damage);
			if ((m_state->getPlayer_Viking()->getlife()) <= 0.0f) {
				m_state->getPlayer_Viking()->set_status(false);
			}
		}
	}

}





void Level::update(float dt)
{
	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->update(dt);

	if (m_state->getPlayer_Viking()->isActive())
		m_state->getPlayer_Viking()->update(dt);

	if (levelcontrol == "levelmedium") {
		m_state->checkenemy();
		m_state->drawenemy();
		if (m_state->getenemy()->isActive())
			m_state->getenemy()->update(dt);
	}
	checkCollisions();

	GameObject::update(dt);

}

void Level::draw()
{
	float w = m_state->getCanvasWidth();
	float h = m_state->getCanvasHeight();



	graphics::drawRect(w / 2.0f, h / 2.0f,22,12, m_brush_background);

	for (int i = 0; i < m_blocks.size(); i++)
	{
		drawBlock(i);
	}

	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->draw();

	if (m_state->getPlayer_Viking()->isActive())
		m_state->getPlayer_Viking()->draw();

	if (levelcontrol == "levelmedium") {
		if (m_state->getenemy()->isActive())
			m_state->getenemy()->draw();
	}


}

void Level::init()
{
	m_blocks.clear();
	if (levelcontrol == "leveleasy") {
		m_blocks.push_back(Box(11.0f, 12.5f, 30.0f, 3.0f));
		m_blocks.push_back(Box(10.0f, 6.5f, 7.0f, 1.5f));

		m_block_names.push_back("WEQ.png");
		m_block_names.push_back("brown.png");


		m_brush_background.texture = m_state->getFullAssetPath("back.png");
	}
	else if (levelcontrol == "levelmedium") {
		m_blocks.push_back(Box(11.0f, 12.5f, 30.0f, 3.0f));
		m_block_names.push_back("WEQ.png");
		m_brush_background.texture = m_state->getFullAssetPath("volcanoback.png");
	}
	m_brush_background.outline_opacity = 0.0f;
	m_block_brush.outline_opacity = 0.0f;
	m_block_brush_debug.fill_opacity = 0.1f;
	SETCOLOR(m_block_brush_debug.fill_color, 0.1f, 1.0f, 0.1f);
	SETCOLOR(m_block_brush_debug.outline_color, 0.3f, 1.0f, 0.2f);

}

Level::Level(const std::string& name)
	: GameObject(name)
{

}



Level::~Level()
{
}