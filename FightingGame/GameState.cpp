#include "gamestate.h"
#include "Level.h"
#include "Player.h"
#include <thread>
#include <chrono>
#include <iostream>
#include<sgg/graphics.h>
#include "Enemy.h"
using namespace std::chrono_literals;

GameState::GameState()
{
}


GameState::~GameState()
{
	m_current_level->~Level();
}

GameState* GameState::getInstance()
{
	if (!m_unique_instance)
	{
		m_unique_instance = new GameState();
	}
	return m_unique_instance;
}

bool GameState::init()
{
	status = STATUS_START;
	m_loadingscreen.outline_opacity = 0.0f;

	m_current_level = new Level("1.lvl");

	m_player = new Player("Warrior");
	m_player->set_at1key(graphics::SCANCODE_E);
	m_player->set_at2key(graphics::SCANCODE_Q);
	m_player->set_jumpkey(graphics::SCANCODE_W);
	m_player->set_forwardkey(graphics::SCANCODE_D);
	m_player->set_backwardkey(graphics::SCANCODE_A);
	m_player->set_defendkey(graphics::SCANCODE_S);


	m_player_Viking = new Player("Viking");

	m_player_Viking->set_at1key(graphics::SCANCODE_U);
	m_player_Viking->set_at2key(graphics::SCANCODE_O);
	m_player_Viking->set_jumpkey(graphics::SCANCODE_I);
	m_player_Viking->set_forwardkey(graphics::SCANCODE_L);
	m_player_Viking->set_backwardkey(graphics::SCANCODE_J);
	m_player_Viking->set_defendkey(graphics::SCANCODE_K);



	graphics::preloadBitmaps(getAssetDir());
	return true;
}

void GameState::draw()
{
	if (status == STATUS_START) {
		m_loadingscreen.texture = getFullAssetPath("lobby.png");
		graphics::drawRect(getCanvasWidth() / 2.0f, getCanvasHeight() / 2.0f, 22.0f, 12.0f, m_loadingscreen);

	}
	else if (status == STATUS_SUPPORT) {
		m_loadingscreen.texture = getFullAssetPath("support.png");
		graphics::drawRect(getCanvasWidth() / 2.0f, getCanvasHeight() / 2.0f, 22.0f, 12.0f, m_loadingscreen);

	}
	else if (status == STATUS_CHOICE) {
		m_loadingscreen.texture = getFullAssetPath("gamemodes.png");
		graphics::drawRect(getCanvasWidth() / 2.0f, getCanvasHeight() / 2.0f, 22.0f, 12.0f, m_loadingscreen);

	}
	else if (status == STATUS_ENDSCREEN) {
		if (!(getPlayer_Viking()->get_status())) {
			m_loadingscreen.texture = getFullAssetPath("end1.png");
		}
		else if (!(getPlayer()->get_status())) {
			m_loadingscreen.texture = getFullAssetPath("end2.png");
		}
		graphics::drawRect(getCanvasWidth() / 2.0f, getCanvasHeight() / 2.0f, 22.0f, 12.0f, m_loadingscreen);

	}
	else {
		if (!m_current_level)
			return;
		if(status==STATUS_PLAYING)
			m_current_level->draw();

		graphics::Brush br_forlife;
		graphics::Brush br_forlife_two;
		float players_life = m_player ? m_player->getlife() : 0.0f - 0.5f;

		br_forlife.outline_opacity = 0.0f;
		br_forlife.fill_color[2] = 0.0f;
		br_forlife.fill_color[1] = 1.0f;
		br_forlife.fill_color[0] = 0.0f;

		br_forlife.texture = "";
		br_forlife.fill_secondary_color[2] = 0.0f;
		br_forlife.fill_secondary_color[1] = 0.2 * (1.0f - players_life) + players_life * 1.0f;
		br_forlife.fill_secondary_color[0] = 0.0f; 

		br_forlife.gradient = true;

		br_forlife.gradient_dir_u = 1.0f;
		br_forlife.gradient_dir_v = 0.0f;

		graphics::drawRect(m_canvas_width - 17.7f - ((1.0f - players_life) * 5 / 2), 1.0f, players_life * 5, 0.35f, br_forlife);
		br_forlife.outline_opacity = 1.0f;
		br_forlife.gradient = false;
		br_forlife.fill_opacity = 0.0f;
		graphics::drawRect(m_canvas_width - 17.7f - ((1.0f - players_life) * 5 / 2), 1.0f, players_life * 5, 0.35f, br_forlife);






		float players_life_two = m_player_Viking ? m_player_Viking->getlife() : 0.0f;

		br_forlife_two.outline_opacity = 0.0f;
		br_forlife_two.fill_color[0] = 0.0f;
		br_forlife_two.fill_color[1] = 1.0f;
		br_forlife_two.fill_color[2] = 0.0f;

		br_forlife_two.texture = "";

		br_forlife_two.fill_secondary_color[0] = 0.0f;
		br_forlife_two.fill_secondary_color[1] = 0.2 * (1.0f - players_life_two) + players_life_two * 1.0f;
		br_forlife_two.fill_secondary_color[2] = 0.0f; 

		br_forlife_two.gradient = true;

		br_forlife_two.gradient_dir_u = 1.0f;
		br_forlife_two.gradient_dir_v = 0.0f;

		graphics::drawRect(m_canvas_width - 1.6f - ((players_life_two) * 4.5 / 2), 1.0f, players_life_two * 4.5, 0.35f, br_forlife_two);
		br_forlife_two.outline_opacity = 1.0f;
		br_forlife_two.gradient = false;
		br_forlife_two.fill_opacity = 0.0f;
		graphics::drawRect(m_canvas_width - 1.6f - ((players_life_two) * 4.5 / 2), 1.0f, players_life_two * 4.5, 0.35f, br_forlife_two);
	}
}

void GameState::update(float dt)
{
	if (status == STATUS_START) {
		updateStartscreen();

	}
	else if (status == STATUS_SUPPORT) {
		updateSupportscreen();
	}
	else if (status == STATUS_CHOICE || status== STATUS_PLAYING) {
		updatelvlscreen();
	}
	else if (status == STATUS_ENDSCREEN) {
		updateendscreen();
	}


	if ((status == STATUS_START || status == STATUS_SUPPORT) && musiccontrol) {
		graphics::playMusic(getFullAssetPath("lobbymusic.mp3"), 0.3f, true, 4000);
		musiccontrol = false;
	}
	else if (status == STATUS_PLAYING && musiccontrol) {
		graphics::playMusic(getFullAssetPath("crowd.mp3"), 0.2f, false, 100);
		musiccontrol = false;
	}
	

	if (dt > 500)
		return;

	float sleep_time = std::max(17.0f - dt, 0.0f);
	if (sleep_time > 0.0f)
	{
		std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(sleep_time));
	}

	if (!m_current_level)
		return;

	if (status == STATUS_PLAYING)
		m_current_level->update(dt);

	m_debugging = graphics::getKeyState(graphics::SCANCODE_0);

}

void GameState::updateStartscreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN) && status != STATUS_PLAYING && status != STATUS_SUPPORT) {
		status = STATUS_CHOICE;
		musiccontrol = true;

	}
	else if (graphics::getKeyState(graphics::SCANCODE_X) && status != STATUS_START) {
		status = STATUS_START;
		musiccontrol = true;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_Q) && status != STATUS_SUPPORT && status != STATUS_PLAYING) {
		status = STATUS_SUPPORT;
		musiccontrol = true;
	}
}

void GameState::checkenemy()
{
	if (enemyobj && !enemyobj->IsOnScreen()) {
		delete enemyobj;
		enemyobj = nullptr;
	}
}

void GameState::updateSupportscreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_X) && status != STATUS_START) {
		status = STATUS_START;
		musiccontrol = true;
	}
}


void GameState::updateendscreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_X) && status != STATUS_START) {
		status = STATUS_START;
		musiccontrol = true;
	}
}



void GameState::updatelvlscreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_1) && status == STATUS_CHOICE) {
		m_current_level->setcontrol("leveleasy");
		m_current_level->init();
		m_player->setposx(m_canvas_width / 7.5f);
		m_player->setposy(m_canvas_height / 8.0f);
		m_player->init(1);
		m_player_Viking->setposx(m_canvas_width / 1.5f);
		m_player_Viking->setposy(m_canvas_height / 8.0f);
		m_player_Viking->init(2);
		status = STATUS_PLAYING;
		dyingscreen = true;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_2) && status == STATUS_CHOICE) {
		m_current_level->setcontrol("levelmedium");
		m_current_level->init();
		m_player->setposx(m_canvas_width / 7.5f);
		m_player->setposy(m_canvas_height / 8.0f);
		m_player->init(1);
		m_player_Viking->setposx(m_canvas_width / 1.5f);
		m_player_Viking->setposy(m_canvas_height / 8.0f);
		m_player_Viking->init(2);
		status = STATUS_PLAYING;
		dyingscreen = true;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_X) && status != STATUS_START) {
		status = STATUS_START;
		musiccontrol = true;
		dyingscreen = false;
	}
	else if ((!m_player->dying || !m_player_Viking->dying) && dyingscreen) {
		status = STATUS_ENDSCREEN;
		musiccontrol = true;
		dyingscreen = false;
	}
}

std::string GameState::getFullAssetPath(const std::string& asset)
{
	return m_asset_path + asset;
}

std::string GameState::getAssetDir()
{
	return m_asset_path;
}

void GameState::drawenemy()
{
	if (!enemyobj) {
		enemyobj = new Enemy("bread");
		enemyobj->init();
	}
}

GameState* GameState::m_unique_instance = nullptr;