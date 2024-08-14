#pragma once
#include "PauseUIBase.h"

class BGMVolumeBarUI : public PauseUIBase
{
public:
	void Start();
	virtual void SelectedLogic();
	virtual void UnSelectedLogic();
	void OnDestroy();

protected:
private:
	bool m_isMove = false;
	SpriteRenderer2D* volumeGauge;
};


