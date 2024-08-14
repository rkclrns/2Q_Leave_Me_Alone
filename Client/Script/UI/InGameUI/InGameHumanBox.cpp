#include "InGameHumanBox.h"
#include "Resource.h"

void InGameHumanBox::Start()
{
	__super::Start();

	mainSprite->SetSprite(InGameHumanBoxSprite().Get());
	gameObject->SetActive(false);
}

void InGameHumanBox::Update()
{
	
}

void InGameHumanBox::OnDestroy()
{

}


