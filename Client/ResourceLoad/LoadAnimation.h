#pragma once
#include "LoadResource.h"

// Player
struct PlayerHold : public LoadAnimation
{
	PlayerHold();
};

struct PlayerMove_Down : public LoadAnimation
{
	PlayerMove_Down();
};

struct PlayerIdle : public LoadAnimation
{
	PlayerIdle();
};

struct PlayerMove_RL : public LoadAnimation
{
	PlayerMove_RL();
};

struct PlayerMove_Top : public LoadAnimation
{
	PlayerMove_Top();
};


struct PlayerSkill : public LoadAnimation
{
	PlayerSkill();
};

// Woman1
struct Woman1_Idle : public LoadAnimation
{
	Woman1_Idle();
};

struct Woman1_Run : public LoadAnimation
{
	Woman1_Run();
};

struct Woman1_Surprise : public LoadAnimation
{
	Woman1_Surprise();
};

struct Woman1_Walk : public LoadAnimation
{
	Woman1_Walk();
};


// Man1
struct Man1_Idle : public LoadAnimation
{
	Man1_Idle();
};

struct Man1_Run : public LoadAnimation
{
	Man1_Run();
};

struct Man1_Surprise : public LoadAnimation
{
	Man1_Surprise();
};

struct Man1_Walk : public LoadAnimation
{
	Man1_Walk();
};


// Cat
struct Cat_Idle : public LoadAnimation
{
	Cat_Idle();
};

struct Cat_Walk : public LoadAnimation
{
	Cat_Walk();
};

struct Cat_Run : public LoadAnimation
{
	Cat_Run();
};

struct Cat_Jump : public LoadAnimation
{
	Cat_Jump();
};

struct Cat_Appear : public LoadAnimation
{
	Cat_Appear();
};

struct Cat_Disappear : public LoadAnimation
{
	Cat_Disappear();
};

struct OldBookAnimation : public LoadCSVAnimation
{
	OldBookAnimation();
};

struct DollAnimation : public LoadCSVAnimation
{
	DollAnimation();
};

struct BroomAnimation : public LoadCSVAnimation
{
	BroomAnimation();
};

struct ChairAnimation : public LoadCSVAnimation
{
	ChairAnimation();
};

struct BedAnimation : public LoadCSVAnimation
{
	BedAnimation();
};

//struct PianoAnimation : public LoadCSVAnimation
//{
//	PianoAnimation();
//};

struct ClockBigAnimation : public LoadCSVAnimation
{
	ClockBigAnimation();
};

struct StatueAnimation : public LoadCSVAnimation
{
	StatueAnimation();
};

struct MannequinAnimation : public LoadCSVAnimation
{
	MannequinAnimation();
};

struct MiddleWindow1Animation : public LoadCSVAnimation
{
	MiddleWindow1Animation();
};

struct TVAnimation : public LoadCSVAnimation
{
	TVAnimation();
};

struct MirrorAnimation : public LoadCSVAnimation
{
	MirrorAnimation();
};

struct ChandelierAnimation : public LoadCSVAnimation
{
	ChandelierAnimation();
};

struct Lamp1Animation : public LoadCSVAnimation
{
	Lamp1Animation();
};

struct BottleAnimation : public LoadCSVAnimation
{
	BottleAnimation();
};

struct PotAnimation : public LoadCSVAnimation
{
	PotAnimation();
};

struct FrameAnimation : public LoadCSVAnimation
{
	FrameAnimation();
};

struct TeaCupAnimation : public LoadCSVAnimation
{
	TeaCupAnimation();
};

struct CandleLightAnimation : public LoadCSVAnimation
{
	CandleLightAnimation();
};

struct LoadingTextAnimation : public LoadAnimation
{
	LoadingTextAnimation();
};