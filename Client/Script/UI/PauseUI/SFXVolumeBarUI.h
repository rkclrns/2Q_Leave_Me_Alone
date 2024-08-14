#pragma once
#include "Script/UI/PauseUI/PauseUIBase.h"

class SFXVolumeBarUI 
	: public PauseUIBase
{
public:
	void Start();
	virtual void SelectedLogic();
	virtual void UnSelectedLogic();
	void OnDestroy();

	bool isSelect = false;

protected:
private:
	bool m_isMove = false;
	SpriteRenderer2D* volumeGauge;
};


