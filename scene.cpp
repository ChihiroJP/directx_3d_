/*==============================================================================

	Scene [scene.cpp]
														 Author : Zishan
														 Date   : 2025/07/11
--------------------------------------------------------------------------------

==============================================================================*/

#include "scene.h"
#include "title.h"
#include "game.h"

static Scene g_Scene = SCENE_GAME;
static Scene g_SceneNext = g_Scene;


void Scene_Initialize()
{
	switch (g_Scene) {
	case SCENE_TITLE:
		Title_Initialize();
		break;
	case SCENE_GAME:
		Game_Initialize();
		break;
	case SCENE_RESULT:
		break;
	}
}

void Scene_Finalize()
{
	switch (g_Scene) {
	case SCENE_TITLE:
		Title_Finalize();
		break;
	case SCENE_GAME:
		Game_Finalize();
		break;
	case SCENE_RESULT:
		break;
	}
}

void Scene_Update(double elapsed_time)
{
	switch (g_Scene) {
	case SCENE_TITLE:
		Title_Update(elapsed_time);
		break;
	case SCENE_GAME:
		Game_Update(elapsed_time);
		break;
	case SCENE_RESULT:
		break;
	}
}

void Scene_Draw()
{
	switch (g_Scene) {
	case SCENE_TITLE:
		Title_Draw();
		break;
	case SCENE_GAME:
		Game_Draw();
		break;
	case SCENE_RESULT:
		break;
	}
}

void Scene_Refresh()
{
	if (g_Scene != g_SceneNext) {
		// Scene Now Finalize
		Scene_Finalize();

		g_Scene = g_SceneNext;
		Scene_Initialize();
	}
}

void Scene_Change(Scene scene)
{
	g_SceneNext = scene;
}
