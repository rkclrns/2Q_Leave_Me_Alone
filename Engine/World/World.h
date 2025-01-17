#pragma once
#include "../World/Layer/Layer.h"

class Object;
class Layer;
class Actor;

class World
{
public:

	World();
	~World();

	static void Release();

	void FixedUpdate();
	void EarlyUpdate();
	void Update();
	void LateUpdate();
	void StateUpdate();
	void Render();

	virtual void WorldLoad() {}
	virtual void WorldDestroy() {}
	virtual void WorldEnter() {}
	virtual void WorldExit() {}

	template <typename T>
	T* CreateObject(std::wstring _name = ""
		, LayerTag _type = LayerTag::Defalut
		, ObjectTag _tag = ObjectTag::Defalut)
	{
		T* obj = new T(_name, _tag);
		obj->SetLayerOwner(m_layers[(int)_type]);
		obj->Initialize();
		m_layers[(int)_type]->GetObjectList().push_back(obj);
		return obj;
	}

	template <typename T>
	T* FindObject(std::wstring _name, LayerTag _tag = LayerTag::Defalut)
	{
		T* temp;
		for (int i = (int)_tag; i < (int)LayerTag::SIZE; i++)
		{
			for (Object* obj : m_layers[i]->GetObjectList())
			{
				if (obj->GetName() == _name)
				{
					if (temp = dynamic_cast<T*>(obj))
						return temp;
				}
			}
		}
		return nullptr;
	}
	void             Clear(bool _isAll);

	std::string		 GetName()const { return m_WorldName; }
	WorldTag		 GetTag()const { return m_WorldTag; }
	Layer**			 GetLayerList() { return m_layers; }
	GameState	     GetState() { return m_type; }
	void			 SetName(std::string _name) { m_WorldName = _name; }
	void			 SetTag(WorldTag _tag) { m_WorldTag = _tag; }
	void			 SetDestroy() { m_type = GameState::Destroy; }

protected:

	Camera2D* Maincamera;

private:

	GameState		 m_type = GameState::Active;

	std::string		 m_WorldName;
	WorldTag		 m_WorldTag;		 
	Layer*			 m_layers[(int)LayerTag::SIZE];

};