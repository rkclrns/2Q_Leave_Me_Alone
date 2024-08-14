#include "LoadAnimation.h"

PlayerHold::PlayerHold()
{
    _key = L"A_PlayerHold";
    _spriteKey = L"S_PlayerSheet";
    _data = {
        {0, 0.2f},
        {1, 0.2f},
        {2, 0.2f},
        {3, 0.2f},
        {4, 0.2f},
        {5, 0.2f},
        {6, 0.2f}
    };
}

PlayerMove_Down::PlayerMove_Down()
{
    _key = L"PlayerMove_Down";
    _spriteKey = L"S_PlayerSheet";
    _data = {
        {7, 0.2f},
        {8, 0.2f},
        {9, 0.2f},
        {10, 0.2f},
        {11, 0.2f},
        {12, 0.2f},
        {13, 0.2f}
    };
}

PlayerIdle::PlayerIdle()
{
    _key = L"PlayerIdle";
    _spriteKey = L"S_PlayerSheet";
    _data = {
        {14, 0.2f},
        {15, 0.2f},
        {16, 0.2f},
        {17, 0.2f},
        {18, 0.2f},
        {19, 0.2f},
        {20, 0.2f}
    };
}

PlayerMove_RL::PlayerMove_RL()
{
    _key = L"PlayerMove_RL";
    _spriteKey = L"S_PlayerSheet";
    _data = {
        {14, 0.2f},
        {15, 0.2f},
        {16, 0.2f},
        {17, 0.2f},
        {18, 0.2f},
        {19, 0.2f},
        {20, 0.2f}
    };
}

PlayerMove_Top::PlayerMove_Top()
{
    _key = L"PlayerMove_Top";
    _spriteKey = L"S_PlayerSheet";
    _data = {
        {21, 0.2f},
        {22, 0.2f},
        {23, 0.2f},
        {24, 0.2f},
        {25, 0.2f},
        {26, 0.2f},
        {27, 0.2f}
    };
}

PlayerSkill::PlayerSkill()
{
    _key = L"PlayerSkill";
    _spriteKey = L"S_PlayerSheet";
    _data = {
        {28, 0.1f},
        {29, 0.1f},
        {30, 0.1f},
        {31, 0.1f},
        {32, 0.1f},
        {33, 0.1f},
        {34, 0.1f}
    };
}

Woman1_Idle::Woman1_Idle()
{
    _key = L"A_Woman1_Idle";
    _spriteKey = L"S_Woman1Sheet";
    _data = {
        {0, 0.07f},
        {1, 0.07f},
        {2, 0.07f},
        {3, 0.07f},
        {4, 0.07f},
        {5, 0.07f},
        {6, 0.07f},
        {7, 0.07f},
        {8, 0.07f},
        {9, 0.07f},
        {10, 0.07f},
        {11, 0.07f},
        {12, 0.07f}
    };
}

Woman1_Run::Woman1_Run()
{
    _key = L"A_Woman1_Run";
    _spriteKey = L"S_Woman1Sheet";
    _data = {
        {13, 0.07f},
        {14, 0.07f},
        {15, 0.07f},
        {16, 0.07f},
        {17, 0.07f},
        {18, 0.07f},
        {19, 0.07f},
        {20, 0.07f},
        {21, 0.07f},
        {22, 0.07f}
    };
}

Woman1_Surprise::Woman1_Surprise()
{
    _key = L"A_Woman1_Surprise";
    _spriteKey = L"S_Woman1Sheet";
    _data = {
        {23, 0.07f},
        {24, 0.07f},
        {25, 0.07f},
        {26, 0.07f},
        {27, 0.07f},
        {28, 0.07f},
        {29, 0.07f},
        {30, 0.07f},
        {31, 0.07f},
    };
}

Woman1_Walk::Woman1_Walk()
{
    _key = L"A_Woman1_Walk";
    _spriteKey = L"S_Woman1Sheet";
    _data = {
        {32, 0.07f},
        {33, 0.07f},
        {34, 0.07f},
        {35, 0.07f},
        {36, 0.07f},
        {37, 0.07f},
        {38, 0.07f},
        {39, 0.07f},
        {39, 0.07f},
        {40, 0.07f},
        {41, 0.07f},
        {42, 0.07f},
        {43, 0.07f},
        {44, 0.07f},
        {45, 0.07f}
    };
}

Man1_Idle::Man1_Idle()
{
    _key = L"A_Man1_Idle";
    _spriteKey = L"S_Man1Sheet";
    _data = {
        {0, 0.07f},
        {1, 0.07f},
        {2, 0.07f},
        {3, 0.07f},
        {4, 0.07f},
        {5, 0.07f},
        {6, 0.07f},
        {7, 0.07f},
        {8, 0.07f},
        {9, 0.07f},
        {10, 0.07f},
        {11, 0.07f},
        {12, 0.07f}
    };
}

Man1_Run::Man1_Run()
{
    _key = L"Man1_Run";
    _spriteKey = L"S_Man1Sheet";
    _data = {
        {13, 0.07f},
        {14, 0.07f},
        {15, 0.07f},
        {16, 0.07f},
        {17, 0.07f},
        {18, 0.07f},
        {19, 0.07f},
        {20, 0.07f},
        {21, 0.07f},
        {22, 0.07f}
    };
}

Man1_Surprise::Man1_Surprise()
{
    _key = L"Man1_Surprise";
    _spriteKey = L"S_Man1Sheet";
    _data = {
        {23, 0.07f},
        {24, 0.07f},
        {25, 0.07f},
        {26, 0.07f},
        {27, 0.07f},
        {28, 0.07f},
        {29, 0.07f},
        {30, 0.07f},
        {31, 0.07f},
    };
}

Man1_Walk::Man1_Walk()
{
    _key = L"A_Man1_Walk";
    _spriteKey = L"S_Man1Sheet";
    _data = {
        {32, 0.07f},
        {33, 0.07f},
        {34, 0.07f},
        {35, 0.07f},
        {36, 0.07f},
        {37, 0.07f},
        {38, 0.07f},
        {39, 0.07f},
        {39, 0.07f},
        {40, 0.07f},
        {41, 0.07f},
        {42, 0.07f},
        {43, 0.07f},
        {44, 0.07f},
        {45, 0.07f}
    };
}

Cat_Idle::Cat_Idle()
{
    _key = L"A_Cat_Idle";
    _spriteKey = L"S_CatSheet";
    _data = {
        {0, 0.1f},
        {1, 0.1f},
        {2, 0.1f},
        {3, 0.1f},
        {4, 0.1f}
    };
}

Cat_Walk::Cat_Walk()
{
    _key = L"A_Cat_Walk";
    _spriteKey = L"S_CatSheet";
    _data = {
        {5, 0.1f},
        {6, 0.1f},
        {7, 0.1f},
        {8, 0.1f},
        {9, 0.1f}
    };
}

Cat_Run::Cat_Run()
{
    _key = L"A_Cat_Run";
    _spriteKey = L"S_CatSheet";
    _data = {
        {10, 0.1f},
        {11, 0.1f},
        {12, 0.1f},
        {13, 0.1f},
        {14, 0.1f},
        {15, 0.1f},
        {16, 0.1f},
        {17, 0.1f},
        {18, 0.1f}
    };
}

Cat_Jump::Cat_Jump()
{
    _key = L"A_Cat_Jump";
    _spriteKey = L"S_CatSheet";
    _data = {
        {19, 0.1f},
        {20, 0.1f},
        {21, 0.1f},
        {22, 0.1f},
        {23, 0.1f},
        {24, 0.1f},
        {25, 0.1f},
        {26, 0.1f},
        {27, 0.1f},
        {28, 0.1f},
        {29, 0.1f}
    };
}

Cat_Appear::Cat_Appear()
{
    _key = L"A_Cat_Appear";
    _spriteKey = L"S_CatSheet";
    _data = {
        {30, 0.1f},
        {31, 0.1f},
        {32, 0.1f},
        {33, 0.1f}
    };
}

Cat_Disappear::Cat_Disappear()
{
    _key = L"A_Cat_Disappear";
    _spriteKey = L"S_CatSheet";
    _data = {
        {34, 0.1f},
        {35, 0.1f},
        {36, 0.1f},
        {37, 0.1f},
        {38, 0.1f},
        {39, 0.1f},
        {40, 0.1f},
        {41, 0.1f}
    };
}

OldBookAnimation::OldBookAnimation()
{
    _key = L"A_OldBook";
    _path = L"Csv/Animation/oldBook.txt";
}

DollAnimation::DollAnimation()
{
    _key = L"A_Doll";
    _path = L"Csv/Animation/doll.txt";
}

BroomAnimation::BroomAnimation()
{
    _key = L"A_Broom";
    _path = L"Csv/Animation/broom.txt";
}

ChairAnimation::ChairAnimation()
{
    _key = L"A_Chair";
    _path = L"Csv/Animation/chair.txt";
}

BedAnimation::BedAnimation()
{
    _key = L"A_Bed";
    _path = L"Csv/Animation/bed.txt";
}

//PianoAnimation::PianoAnimation()
//{
//    _key = L"A_Piano";
//    _path = L"Csv/Animation/piano.txt";
//}

ClockBigAnimation::ClockBigAnimation()
{
    _key = L"A_ClockBig";
    _path = L"Csv/Animation/clock_big.txt";
}

StatueAnimation::StatueAnimation()
{
    _key = L"A_Statue";
    _path = L"Csv/Animation/statue.txt";
}

MannequinAnimation::MannequinAnimation()
{
    _key = L"A_Mannequin";
    _path = L"Csv/Animation/mannequin.txt";
}

MiddleWindow1Animation::MiddleWindow1Animation()
{
    _key = L"A_MiddleWindow1";
    _path = L"Csv/Animation/m_window01.txt";
}

TVAnimation::TVAnimation()
{
    _key = L"A_TV";
    _path = L"Csv/Animation/TV.txt";
}

MirrorAnimation::MirrorAnimation()
{
    _key = L"A_Mirror";
    _path = L"Csv/Animation/mirror.txt";
}

ChandelierAnimation::ChandelierAnimation()
{
    _key = L"A_Chandelier";
    _path = L"Csv/Animation/chandelier.txt";
}

Lamp1Animation::Lamp1Animation()
{
    _key = L"A_Lamp1";
    _path = L"Csv/Animation/s_lamp.txt";
}

BottleAnimation::BottleAnimation()
{
    _key = L"A_Bottle";
    _path = L"Csv/Animation/bottle.txt";
}

PotAnimation::PotAnimation()
{
    _key = L"A_Pot";
    _path = L"Csv/Animation/pot.txt";
}

FrameAnimation::FrameAnimation()
{
    _key = L"A_Frame";
    _path = L"Csv/Animation/s_frame01.txt";
}

TeaCupAnimation::TeaCupAnimation()
{
    _key = L"A_TeaCup";
    _path = L"Csv/Animation/teaCup.txt";
}

CandleLightAnimation::CandleLightAnimation()
{
    _key = L"A_CandleLight";
    _path = L"Csv/Animation/candleLight.txt";
}

LoadingTextAnimation::LoadingTextAnimation()
{
    _key = L"A_LoadingText";
    _spriteKey = L"S_LoadingText";
    _data = {
        {0, 0.3f},
        {1, 0.3f},
        {2, 0.3f},
        {3, 0.3f},
        {4, 0.3f},
        {5, 0.3f},
    };
}