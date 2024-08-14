#pragma once
#include "Component.h"

class Actor;
class WorldManager;
class Collider;
class World;

class Script : public Component
{
public:

	Script();
	virtual ~Script();

	virtual void Start() {} // ������Ʈ�� �߰��� ���� �ٷ� ȣ��˴ϴ�.

	virtual void Initialize() override
	{
		Start();
	}
	virtual void Update() {}
	virtual void FixedUpdate() {}
	virtual void LateUpadte() {}

	// ============��ũ��Ʈ���� ����ϴ� �Լ�============
	void         Destroy(Object* _obj);
	void         SetPersistentObject(Object* _obj, bool _isPersistent);

	template<typename T>
	T*			 CreateObject(const std::wstring& _name = "", const LayerTag _layerTag = LayerTag::Defalut, ObjectTag _objectTag = ObjectTag::Defalut);
	template<typename T>
	T*			 FindObject(const std::wstring& _name, const LayerTag _tag = LayerTag::Defalut);

	void		 ChangeWorld(std::string _key); // �� �Ѿ��
	void		 ChangeWorld(World* _world); // �� �Ѿ��

	std::vector<Object*>& GetObjectList(LayerTag _layer);

	// ============�ܺο��� ȣ��޴� �Լ� (�浹, ��ư, Ȱ��ȭ ���)============
	virtual void OnEnable() {}; // ������Ʈ�� Ȱ��ȭ �Ǹ� ȣ��˴ϴ�.
	virtual void OnDisable() {}; // ������Ʈ�� ��Ȱ��ȭ �Ǹ� ȣ��˴ϴ�.
	virtual void OnDestroy() {}; // ������Ʈ�� �ı��� �� ȣ��˴ϴ�.
	virtual void OnCollisionEnter(Collider* _origin, Collider* _destination) {};
	virtual void OnCollisionStay(Collider* _origin, Collider* _destination) {};
	virtual void OnCollisionExit(Collider* _origin, Collider* _destination) {};
	virtual void OnMouseEnter() {}; // ���콺�� �ش� ��ư ���� ó������ ������ �� ȣ��˴ϴ�.
	virtual void OnMouseStay() {}; // ���콺�� �ش� ��ư ���� �ִµ��� �� ������Ʈ���� ȣ��˴ϴ�.
	virtual void OnMouseExit() {}; // ���콺�� �ش� ��ư���� ���� �� ȣ��˴ϴ�.
	virtual void OnAnimationEnter(int _index) {};
};

template<typename T>
inline T* Script::CreateObject(const std::wstring& _name, const LayerTag _layerTag, ObjectTag _objectTag)
{
	return WorldManager::GetActiveWorld()->CreateObject<T>(_name, _layerTag, _objectTag);
}

template<typename T>
T* Script::FindObject(const std::wstring& _name, const LayerTag _tag)
{
	return WorldManager::GetActiveWorld()->FindObject<T>(_name, _tag);
}