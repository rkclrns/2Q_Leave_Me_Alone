#pragma once
#include "../../Component/Transform2D.h"

class Layer;

class Object abstract
{
public:

	Object(std::wstring _name, ObjectTag _tag = ObjectTag::Defalut);
	virtual ~Object();

	virtual void		Initialize() {}

	virtual void		FixedUpdate();
	virtual void		EarlyUpdate();
	virtual void		Update();
	virtual void		LateUpdate();
	virtual void		Draw(Camera2D* _camera);
	virtual void		Render();

	virtual void		SetActive(bool _val);
	virtual void		SetDestroy();
	void                SetName(const std::wstring& _name) { m_name = _name; }
	void		        SetState(GameState _state) { m_state = _state; }
	void                SetLayerOwner(Layer* _layer) { m_ownerLayer = _layer; }
	void                SetPersistent(bool _isPersistent);
	Layer*		        GetLayerOwner() { return m_ownerLayer; }
	std::wstring        GetName() { return m_name; }
	ObjectTag	        GetTag() { return m_tag; }
	ObjectType          GetType() { return m_type; }
	GameState	        GetState() { return m_state; }
	bool                IsPersistent() { return isPersistent; }

	Transform2D*        transform;
	// ���� �񱳿� �ε��Ҽ��� �񱳽ð��� ���̸� �׽�Ʈ�ؔf���� ���� �� ���̰� ������.
	float				depthsLevel;

protected:

	bool                isPersistent;
					    
	Layer*		        m_ownerLayer;
	std::wstring		m_name;
	ObjectTag		    m_tag;
	ObjectType		    m_type;
	GameState		    m_state;
};
