﻿#ifndef PCH_H
#define PCH_H
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <assert.h>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>	
#include <unordered_map>
#include <map>
#include <cmath>
#include <algorithm>
#include <codecvt>
#include <random>

//Direct2D
#include <d2d1.h>
#include <dwrite.h>
#include <d2d1_1helper.h>
#include <wincodec.h>
#include <comdef.h>
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxguid.lib")

// FMOD
#include "Library/FMOD/Include/fmod.hpp"
#include "Library/FMOD/Include/fmod_studio.hpp"
#include "Library/FMOD/Include/fmod_common.h"
#include "Library/FMOD/Include/fmod_codec.h"
#pragma comment (lib, "../Engine/Library/FMOD/fmod_vc.lib")
#pragma comment (lib, "../Engine/Library/FMOD/fmodstudio_vc.lib")

// Xinput
#include <Xinput.h>
#pragma comment(lib, "xinput.lib")

#include "Helper/CommonEnum.h"
#include "Helper/CommonDef.h"
#include "Helper/Math/MathH.h"
#include "Helper/Math/Random.h"
#include "Helper/DataType/Vector2.h"
#include "Helper/DataType/Rect_F.h"
#include "Helper/ReferenceCounter.h"
#include "Helper/Utillity.h"
#include "Helper/Debug/Debug.h"
#include "Helper/Time/Time.h"
#include "Helper/Input/Input.h"
#endif //PCH_H