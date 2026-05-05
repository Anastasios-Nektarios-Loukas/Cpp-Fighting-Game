#include "animations.h";

void animations::init_1(std::vector<std::string>& m_sprites,
	std::vector<std::string>& m_sprites_attack,
	std::vector<std::string>& m_sprites_jump,
	std::vector<std::string>& m_sprites_sattack,
	std::vector<std::string>& m_sprites_defend,
	std::vector<std::string>& m_sprites_hit,
	std::vector<std::string>& m_sprites_death,
	std::vector<std::string>& m_sprites_idle)
{
	m_sprites.push_back(m_state->getFullAssetPath("run_1.png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_2.png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_3.png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_4.png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_5.png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_6.png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_7.png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_8.png"));

	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_1.png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_2.png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_3.png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_4.png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_5.png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_6.png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_7.png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_8.png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_9.png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_10.png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_11.png"));

	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_1.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_2.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_3.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_4.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_5.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_6.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_7.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_8.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_9.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_10.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_11.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_12.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_13.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_14.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_15.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_16.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_17.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_18.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_19.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_20.png"));

	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_2.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_3.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_4.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_5.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_6.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_7.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_8.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_9.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_10.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_11.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_12.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_13.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_14.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_15.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_16.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_17.png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_18.png"));

	m_sprites_death.push_back(m_state->getFullAssetPath("death_1.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_2.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_3.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_4.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_5.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_6.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_7.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_8.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_9.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_10.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_11.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_12.png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_13.png"));

	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_1.png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_2.png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_3.png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_4.png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_5.png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_6.png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_7.png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_8.png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_9.png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_10.png"));

	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_1.png"));
	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_2.png"));
	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_3.png"));
	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_4.png"));
	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_5.png"));
	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_6.png"));

	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_1.png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_2.png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_3.png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_4.png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_5.png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_6.png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_7.png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_8.png"));
}

void animations::init_2(std::vector<std::string>& m_sprites,
	std::vector<std::string>& m_sprites_attack,
	std::vector<std::string>& m_sprites_jump,
	std::vector<std::string>& m_sprites_sattack,
	std::vector<std::string>& m_sprites_defend,
	std::vector<std::string>& m_sprites_hit,
	std::vector<std::string>& m_sprites_death,
	std::vector<std::string>& m_sprites_idle)
{
	m_sprites.push_back(m_state->getFullAssetPath("run_1_ (1).png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_1_ (2).png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_1_ (3).png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_1_ (4).png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_1_ (5).png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_1_ (6).png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_1_ (7).png"));
	m_sprites.push_back(m_state->getFullAssetPath("run_1_ (8).png"));


	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_1_2 (1).png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_1_2 (2).png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_1_2 (3).png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_1_2 (4).png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_1_2 (5).png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_1_2 (6).png"));
	m_sprites_attack.push_back(m_state->getFullAssetPath("1_atk_1_2 (7).png"));

	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_1.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_2.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_3.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_4.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_5.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_6.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_7.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_8.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_9.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_10.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_11.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_12.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_13.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_14.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_15.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_16.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_17.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_18.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_19.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_20.png"));
	m_sprites_jump.push_back(m_state->getFullAssetPath("jump_full_21.png"));

	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (1).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (2).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (3).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (4).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (5).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (6).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (7).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (8).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (9).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (10).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (11).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (12).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (13).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (14).png"));
	m_sprites_sattack.push_back(m_state->getFullAssetPath("sp_atk_1_ (15).png"));

	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (1).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (2).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (3).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (4).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (5).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (6).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (7).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (8).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (9).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (10).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (11).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (12).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (13).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (14).png"));
	m_sprites_death.push_back(m_state->getFullAssetPath("death_1_ (15).png"));

	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_1 (2).png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_2 (2).png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_3 (2).png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_4 (2).png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_5 (2).png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_6 (2).png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_7 (2).png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_8 (2).png"));
	m_sprites_defend.push_back(m_state->getFullAssetPath("defend_9 (2).png"));

	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_1 (2).png"));
	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_2 (2).png"));
	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_3 (2).png"));
	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_4 (2).png"));
	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_5 (2).png"));
	m_sprites_hit.push_back(m_state->getFullAssetPath("take_hit_6 (2).png"));

	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_1_ (1).png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_1_ (2).png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_1_ (3).png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_1_ (4).png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_1_ (5).png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_1_ (6).png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_1_ (7).png"));
	m_sprites_idle.push_back(m_state->getFullAssetPath("idle_1_ (8).png"));
}
