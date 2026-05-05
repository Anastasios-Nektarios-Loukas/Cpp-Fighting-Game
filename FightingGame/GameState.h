#pragma once
#include <string>
#include<sgg/graphics.h>

class GameState
{
	typedef enum { STATUS_START, STATUS_PLAYING, STATUS_SUPPORT, STATUS_CHOICE, STATUS_ENDSCREEN } status_t;
	status_t status = STATUS_START;
private:
	graphics::Brush m_loadingscreen;
	static GameState* m_unique_instance;

	const std::string m_asset_path = "assets\\";

	const float m_canvas_width = 22.0f;
	const float m_canvas_height = 12.0f;

	class Level* m_current_level = 0;
	class Player* m_player = nullptr;
	class Player* m_player_Viking = nullptr;
	class Enemy* enemyobj = nullptr;
	bool musiccontrol = true;
	bool dyingscreen = false;
	GameState();

public:


	bool m_debugging = false;

public:

	~GameState();
	static GameState* getInstance();
	void drawenemy();
	void checkenemy();
	bool init();
	void draw();
	void update(float dt);
	void updateStartscreen();
	void updateSupportscreen();
	void updateendscreen();
	void updatelvlscreen();
	status_t getGStatus() { return status; }
	std::string getFullAssetPath(const std::string& asset);
	std::string getAssetDir();

	float getCanvasWidth() { return m_canvas_width; }
	float getCanvasHeight() { return m_canvas_height; }
	class Enemy* getenemy() { return enemyobj; }
	class Player* getPlayer() { return m_player; }
	class Player* getPlayer_Viking() { return m_player_Viking; }

};