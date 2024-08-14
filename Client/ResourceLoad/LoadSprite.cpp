#include "LoadSprite.h"

// ================== Character ====================

PlayerSprite::PlayerSprite()
{
	_key = L"S_PlayerSheet";
	_path = L"Sprite/Player/Player.png";
	_data = SpriteData(Vector2(7, 5));
}

Woman1Sprite::Woman1Sprite()
{
	_key = L"S_Woman1Sheet";
	_path = L"Sprite/Human/Woman1.png";
	_data = SpriteData(Vector2(10, 5));
}

Man1Sprite::Man1Sprite()
{
	_key = L"S_Man1Sheet";
	_path = L"Sprite/Human/Man1.png";
	_data = SpriteData(Vector2(10, 5));
}

CatSprite::CatSprite()
{
	_key = L"S_CatSheet";
	_path = L"Sprite/Cat/Cat.png";
	_data = SpriteData(Vector2(7, 6));
}

// ================== Title UI ====================

TitleLogoSprite::TitleLogoSprite()
{
	_key = L"S_TitleLogo";
	_path = L"Sprite/UI/TitleLogo.png";
	_data = SpriteData(Vector2(1, 1));
}

TitleBackgroundSprite::TitleBackgroundSprite()
{
	_key = L"S_TitleBackground";
	_path = L"Sprite/UI/TitleBackground.png";
	_data = SpriteData(Vector2(1, 1));
}

// ================== Credit UI ====================

CreditBackgroundSprite::CreditBackgroundSprite()
{
	_key = L"S_CreditBackground";
	_path = L"Sprite/UI/CreditBackground.png";
	_data = SpriteData(Vector2(1, 1));
}

// ================== Intro UI ====================

IntroBackgroundSprite::IntroBackgroundSprite()
{
	_key = L"S_IntroBackground";
	_path = L"Sprite/UI/IntroBackground.png";
	_data = SpriteData(Vector2(1, 1));
}

// ================== Pause UI ====================

PauseLogoSprite::PauseLogoSprite()
{
	_key = L"S_PauseLogo";
	_path = L"Sprite/UI/PauseLogo.png";
	_data = SpriteData(Vector2(1, 1));
}

PauseRetrySprite::PauseRetrySprite()
{
	_key = L"S_PauseRetry";
	_path = L"Sprite/UI/PauseRetry.png";
	_data = SpriteData(Vector2(3, 1));
}

PauseExitSprite::PauseExitSprite()
{
	_key = L"S_PauseExit";
	_path = L"Sprite/UI/PauseExit.png";
	_data = SpriteData(Vector2(3, 1));
}

BGMVolumeBarSprite::BGMVolumeBarSprite()
{
	_key = L"S_BGMVolumeBar";
	_path = L"Sprite/UI/BGMVolumeBar.png";
	_data = SpriteData(Vector2(2, 1));
}

SFXVolumeBarSprite::SFXVolumeBarSprite()
{
	_key = L"S_SFXVolumeBar";
	_path = L"Sprite/UI/SFXVolumeBar.png";
	_data = SpriteData(Vector2(2, 1));
}

VolumeGaugeBarSprite::VolumeGaugeBarSprite()
{
	_key = L"S_VolumeGaugeBar";
	_path = L"Sprite/UI/VolumeGaugeBar.png";
	_data = SpriteData(Vector2(6, 1));
}

PauseTutorialSprite::PauseTutorialSprite()
{
	_key = L"S_PauseTutorial";
	_path = L"Sprite/UI/PauseTutorial.png";
	_data = SpriteData(Vector2(1, 1));
}

// ================== InGame UI ====================

InGameBackgroundSprite::InGameBackgroundSprite()
{
	_key = L"S_InGameBackground";
	_path = L"Sprite/UI/map.png";
	_data = SpriteData(Vector2(1, 1));
}

InGameTimeSprite::InGameTimeSprite()
{
	_key = L"S_InGameTime";
	_path = L"Sprite/UI/InGameTime.png";
	_data = SpriteData(Vector2(1, 1));
}

InGameGaugeSkillSprite::InGameGaugeSkillSprite()
{
	_key = L"S_InGameGaugeSkill";
	_path = L"Sprite/UI/InGameGaugeSkill.png";
	_data = SpriteData(Vector2(1, 1));
}

InGameHumanBoxSprite::InGameHumanBoxSprite()
{
	_key = L"S_InGameHumanBox";
	_path = L"Sprite/UI/InGameHumanBox.png";
	_data = SpriteData(Vector2(1, 1));
}

InGameSkillSprite::InGameSkillSprite()
{
	_key = L"S_InGameSkill";
	_path = L"Sprite/UI/InGameSkill.png";
	_data = SpriteData(Vector2(2, 1));
}

HumanListKeySprite::HumanListKeySprite()
{
	_key = L"S_HumanListKeyBar";
	_path = L"Sprite/UI/HumanListKey.png";
	_data = SpriteData(Vector2(1, 1));
}

PauseKeySprite::PauseKeySprite()
{
	_key = L"S_PauseKeySprite";
	_path = L"Sprite/UI/PauseKey.png";
	_data = SpriteData(Vector2(1, 1));
}

// ================== Loading UI ====================

LoadingPointerSprite::LoadingPointerSprite()
{
	_key = L"S_LoadingPointer";
	_path = L"Sprite/UI/LoadingPointer.png";
	_data = SpriteData(Vector2(1, 1));
}

LoadingTextSprite::LoadingTextSprite()
{
	_key = L"S_LoadingText";
	_path = L"Sprite/UI/LoadingText.png";
	_data = SpriteData(Vector2(6, 1));
}

// ================== Clear UI ====================

ClearLogoSprite::ClearLogoSprite()
{
	_key = L"S_ClearLogoSprite";
	_path = L"Sprite/UI/ClearLogo.png";
	_data = SpriteData(Vector2(1, 1));
}


// ================== Moving Object =====================

OldBookSprite::OldBookSprite()
{
	_key = L"S_OldBook";
	_path = L"Sprite/Object/oldBook.png";
	_data = SpriteData(Vector2(9, 1));
}

DollSprite::DollSprite()
{
	_key = L"S_Doll";
	_path = L"Sprite/Object/doll.png";
	_data = SpriteData(Vector2(6, 1));
}

ChairSprite::ChairSprite()
{
	_key = L"S_Chair";
	_path = L"Sprite/Object/chair.png";
	_data = SpriteData(Vector2(8, 1));
}

BroomSprite::BroomSprite()
{
	_key = L"S_Broom";
	_path = L"Sprite/Object/broom.png";
	_data = SpriteData(Vector2(8, 1));
}

// ================== Fixed Object =====================

BedSprite::BedSprite()
{
	_key = L"S_Bed";
	_path = L"Sprite/Object/bed.png";
	_data = SpriteData(Vector2(5, 1));
}

//PianoSprite::PianoSprite()
//{
//	_key = L"S_Piano";
//	_path = L"Sprite/Object/piano.png";
//	_data = SpriteData(Vector2(8, 1));
//}

ClockBigSprite::ClockBigSprite()
{
	_key = L"S_ClockBig";
	_path = L"Sprite/Object/clock_big.png";
	_data = SpriteData(Vector2(14, 1));
}

StatueSprite::StatueSprite()
{
	_key = L"S_Statue";
	_path = L"Sprite/Object/statue.png";
	_data = SpriteData(Vector2(4, 1));
}

MannequinSprite::MannequinSprite()
{
	_key = L"S_Mannequin";
	_path = L"Sprite/Object/mannequin.png";
	_data = SpriteData(Vector2(5, 1));
}

MiddleWindow1Sprite::MiddleWindow1Sprite()
{
	_key = L"S_MiddleWindow1";
	_path = L"Sprite/Object/m_window01.png";
	_data = SpriteData(Vector2(12, 1));
}

TVSprite::TVSprite()
{
	_key = L"S_TV";
	_path = L"Sprite/Object/TV.png";
	_data = SpriteData(Vector2(15, 1));
}

MirrorSprite::MirrorSprite()
{
	_key = L"S_Mirror";
	_path = L"Sprite/Object/mirror.png";
	_data = SpriteData(Vector2(5, 1));
}

// ================== Falling Object =====================

LampSprite1::LampSprite1()
{
	_key = L"S_Lamp1";
	_path = L"Sprite/Object/s_lamp.png";
	_data = SpriteData(Vector2(6, 1));
}

BottleSprite::BottleSprite()
{
	_key = L"S_Bottle";
	_path = L"Sprite/Object/bottle.png";
	_data = SpriteData(Vector2(6, 1));
}

PotSprite::PotSprite()
{
	_key = L"S_Pot";
	_path = L"Sprite/Object/pot.png";
	_data = SpriteData(Vector2(6, 1));
}

FrameSprite::FrameSprite()
{
	_key = L"S_Frame";
	_path = L"Sprite/Object/s_frame01.png";
	_data = SpriteData(Vector2(3, 1));
}

TeaCupSprite::TeaCupSprite()
{
	_key = L"S_TeaCup";
	_path = L"Sprite/Object/teaCup.png";
	_data = SpriteData(Vector2(7, 1));
}

CandleLightSprite::CandleLightSprite()
{
	_key = L"S_CandleLight";
	_path = L"Sprite/Object/candleLight.png";
	_data = SpriteData(Vector2(12, 1));
}

// ================== NonFalling Object =====================

ChandelierSprite::ChandelierSprite()
{
	_key = L"S_Chandelier";
	_path = L"Sprite/Object/chandelier.png";
	_data = SpriteData(Vector2(12, 1));
};

// ================== 삭 제 예 정 ====================

TestBackgroundSprite::TestBackgroundSprite()
{
	_key = L"TestBackGround";
	_path = L"Sprite/UI/TestBackGround.png";
	_data = SpriteData(Vector2(1, 1));
}

BackGroundSprite_01::BackGroundSprite_01()
{
	_key = L"S_BackGroundSprite_01";
	_path = L"Sprite/BackGround/BackGround_01.png";
	_data = SpriteData(Vector2(1, 1));
}