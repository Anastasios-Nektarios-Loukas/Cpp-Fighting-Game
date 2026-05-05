#pragma once
#include "gameobject.h"
#include <vector>
#include <list>
#include <string>
#include <sgg/graphics.h>
#include "Player.h"
#include <thread>
#include <chrono>


class animations :GameObject {
public:
	void init_1(std::vector<std::string>& m_sprites,
		std::vector<std::string>& m_sprites_attack,
		std::vector<std::string>& m_sprites_jump,
		std::vector<std::string>& m_sprites_sattack,
		std::vector<std::string>& m_sprites_defend,
		std::vector<std::string>& m_sprites_hit,
		std::vector<std::string>& m_sprites_death,
		std::vector<std::string>& m_sprites_idle);
	void init_2(std::vector<std::string>& m_sprites,
		std::vector<std::string>& m_sprites_attack,
		std::vector<std::string>& m_sprites_jump,
		std::vector<std::string>& m_sprites_sattack,
		std::vector<std::string>& m_sprites_defend,
		std::vector<std::string>& m_sprites_hit,
		std::vector<std::string>& m_sprites_death,
		std::vector<std::string>& m_sprites_idle);
	animations() {};
};