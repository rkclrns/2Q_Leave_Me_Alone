#include "Application.h"
#include "Contents.h"
#include "Resource.h"
#include "WorldHeaders.h"

void GameApplication::Initialize(HINSTANCE _hinstance, const WCHAR* _title, const int _width, const int _height)
{
	__super::Initialize(_hinstance, _title, _width, _height);
	LoadResource();
	LoadWorld();
	InputManager::Initialize();
	SetGameManager<GameManager>();
	CollisionManager::SetCollsionLayer(LayerTag::Object, true);
	CollisionManager::ProcessCycle = 1;
}

void GameApplication::LoadWorld()
{
	// 월드를 생성
	WorldManager::CreateWorld<Title>("Title", WorldTag::Title);
	WorldManager::CreateWorld<IntroScene_01>("IntroScene_01", WorldTag::Play);
	WorldManager::CreateWorld<Credit>("Credit", WorldTag::Default);
	WorldManager::CreateWorld<LoadingScene>("LoadingScene", WorldTag::Default);
	// 월드를 교체
	WorldManager::ChangeWorld("Title");
}

void GameApplication::LoadResource()
{
	// ========= BackGround =========

	BackGroundSprite_01().Load();

	// ========= Player =========
	PlayerSprite().Load();

	PlayerIdle().Load();
	PlayerHold().Load();
	PlayerSkill().Load();
	PlayerMove_Top().Load();
	PlayerMove_Down().Load();
	PlayerMove_RL().Load();

	// ========= Cat =========
	CatSprite().Load();

	Cat_Idle().Load();
	Cat_Appear().Load();
	Cat_Run().Load();
	Cat_Walk().Load();
	Cat_Disappear().Load();

	// ========= Title =========
	TitleBackgroundSprite().Load();
	TitleLogoSprite().Load();

	// ========= Credit =========
	CreditBackgroundSprite().Load();

	// ========= Intro =========
	IntroBackgroundSprite().Load();

	// ========= Pause =========
	BGMVolumeBarSprite().Load();
	SFXVolumeBarSprite().Load();
	VolumeGaugeBarSprite().Load();
	PauseExitSprite().Load();
	PauseLogoSprite().Load();
	PauseTutorialSprite().Load();
	PauseRetrySprite().Load();

	// ========= InGame =========
	InGameGaugeSkillSprite().Load();
	InGameHumanBoxSprite().Load();
	InGameSkillSprite().Load();
	InGameTimeSprite().Load();
	InGameBackgroundSprite().Load();
	HumanListKeySprite().Load();
	PauseKeySprite().Load();

	// ========= Loading =========
	LoadingPointerSprite().Load();
	LoadingTextSprite().Load();
	LoadingTextAnimation().Load();

	// ========= Clear =========
	ClearLogoSprite().Load();

	// ========= FixedObject =========
	BedSprite().Load();
	//PianoSprite().Load();
	ClockBigSprite().Load();
	StatueSprite().Load();
	MannequinSprite().Load();
	MiddleWindow1Sprite().Load();
	TVSprite().Load();
	MirrorSprite().Load();

	BedAnimation().Load();
	//PianoAnimation().Load();
	ClockBigAnimation().Load();
	StatueAnimation().Load();
	MannequinAnimation().Load();
	MiddleWindow1Animation().Load();
	TVAnimation().Load();
	MirrorAnimation().Load();

	// ========= MovingObject =========
	OldBookSprite().Load();
	DollSprite().Load();
	ChairSprite().Load();
	BroomSprite().Load();
	OldBookAnimation().Load();
	DollAnimation().Load();
	BroomAnimation().Load();
	ChairAnimation().Load();

	// ========= Falling Object =========
	LampSprite1().Load();
	Lamp1Animation().Load();
	BottleSprite().Load();
	BottleAnimation().Load();
	PotSprite().Load();
	PotAnimation().Load();
	TeaCupSprite().Load();
	TeaCupAnimation().Load();
	FrameSprite().Load();
	FrameAnimation().Load();
	CandleLightSprite().Load();
	CandleLightAnimation().Load();

	// ========= NonFalling Object =========
	ChandelierSprite().Load();
	ChandelierAnimation().Load();
}

void GameApplication::ReleaseResource()
{
	// ========= Player =========
	PlayerSprite().Release();

	PlayerIdle().Release();
	PlayerHold().Release();
	PlayerSkill().Release();
	PlayerMove_Top().Release();
	PlayerMove_Down().Release();
	PlayerMove_RL().Release();

	// ========= Cat =========
	CatSprite().Release();

	Cat_Idle().Release();
	Cat_Appear().Release();
	Cat_Run().Release();
	Cat_Walk().Release();
	Cat_Disappear().Release();

	// ========= Title =========
	TitleBackgroundSprite().Release();
	TitleLogoSprite().Release();

	// ========= Credit =========
	CreditBackgroundSprite().Release();

	// ========= Intro =========
	IntroBackgroundSprite().Release();

	// ========= Pause =========
	BGMVolumeBarSprite().Release();
	SFXVolumeBarSprite().Release();
	VolumeGaugeBarSprite().Release();
	PauseExitSprite().Release();
	PauseLogoSprite().Release();
	PauseTutorialSprite().Release();
	PauseRetrySprite().Release();

	// ========= InGame =========
	InGameGaugeSkillSprite().Release();
	InGameHumanBoxSprite().Release();
	InGameSkillSprite().Release();
	InGameTimeSprite().Release();
	InGameBackgroundSprite().Release();
	HumanListKeySprite().Release();
	PauseKeySprite().Release();

	// ========= Loading =========
	LoadingPointerSprite().Release();
	LoadingTextSprite().Release();

	// ========= Clear =========
	ClearLogoSprite().Release();

	// ========= FixedObject =========
	BedSprite().Release();
	//PianoSprite().Release();
	ClockBigSprite().Release();
	StatueSprite().Release();
	MannequinSprite().Release();
	MiddleWindow1Sprite().Release();
	TVSprite().Release();
	MirrorSprite().Release();

	// ========= MovingObject =========
	OldBookSprite().Release();
	DollSprite().Release();
	ChairSprite().Release();
	BroomSprite().Release();

	// ========= Falling Object =========
	LampSprite1().Release();
	BottleSprite().Release();
	PotSprite().Release();
	TeaCupSprite().Release();
	FrameSprite().Release();
	CandleLightSprite().Release();

	// ========= NonFalling Object =========
	ChandelierSprite().Release();
}
