#pragma once
#include "../Object/Object.h"
#include "../Object/Actor/Actor.h"

class Layer
{
public:

	Layer(LayerTag _type);
	~Layer();

	void FixedUpdate();
	void EarlyUpdate();
	void Update();
	void LateUpdate();
	void Render();
	void StateUpdate();

	LayerTag GetLayerTag() { return m_layerTag; }
	std::vector<Object*>& GetObjectList() { return m_objectList; }

	enum BlendType
	{
		Default,
		Blending,
		Culling,
	};

private:

	LayerTag m_layerTag;
	std::vector<Object*> m_objectList;

	ID2D1BitmapRenderTarget* m_layerRenderTarget;  // ���̾��� ���� ����Ÿ��
	ID2D1Bitmap*			 m_bitmap;			   // ���̾� ������ �����

	// ���������� ���� �ڵ��
	void ProcessDestroy(std::vector<Object*>& _objList);
	void SortingObject();

};

