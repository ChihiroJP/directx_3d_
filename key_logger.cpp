/*==============================================================================

  Keyboard Input Register [key_logger.cpp]
														 Author : Zishan
														 Date   : 2025/06/27
--------------------------------------------------------------------------------

==============================================================================*/

#include "key_logger.h"

static Keyboard_State g_PreviewState{};
static Keyboard_State g_TriggerState{};
static Keyboard_State g_ReleaseState{};

void KeyLogger_Initialize()
{
	Keyboard_Initialize();
}

void KeyLogger_Update()
{
	const Keyboard_State* pState = Keyboard_GetState();
	LPBYTE pn = (LPBYTE)pState;
	LPBYTE pp = (LPBYTE)&g_PreviewState;
	LPBYTE pt = (LPBYTE)&g_TriggerState;
	LPBYTE pr = (LPBYTE)&g_ReleaseState;

	for (int i = 0; i < sizeof(Keyboard_State); i++) {
		pt[i] = (pp[i] ^ pn[i]) & pn[i]; // Trigger
		pr[i] = (pp[i] ^ pn[i]) & pp[i]; // Release
	}
	g_PreviewState = *pState;
}

bool KeyLogger_IsPressed(Keyboard_Keys key)
{
	return Keyboard_IsKeyDown(key);
}

bool KeyLogger_IsTrigger(Keyboard_Keys key)
{
	return Keyboard_IsKeyDown(key, &g_TriggerState);
}

bool KeyLogger_IsRelease(Keyboard_Keys key)
{
	return Keyboard_IsKeyDown(key, &g_ReleaseState);
}
