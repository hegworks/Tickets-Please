#pragma once
enum class GameState
{
	WaitingForCollectBtnClick, // InGameplay
	WaitingForSkipCollectBtnReport, // InGamePlayReport
	WaitingForTimesUpMenuBtnClick, //InTimesUpMenu
	InMainMenu,
};