#include "pch.h"
#include "Script.h"
#include "World/World.h"
#include "World/Manager/WorldManager.h"

Script::Script()
{
	m_type = ComponentType::Script;
}

Script::~Script()
{
}

void Script::Destroy(Object* _object)
{
	_object->SetDestroy();
}

void Script::SetPersistentObject(Object* _obj, bool _isPersistent)
{
	_obj->SetPersistent(_isPersistent);
}

void Script::ChangeWorld(std::string _key)
{
	WorldManager::ChangeWorld(_key);
}

void Script::ChangeWorld(World* _world)
{
	WorldManager::ChangeWorld(_world);
}

std::vector<Object*>& Script::GetObjectList(LayerTag _layer)
{
	return WorldManager::GetActiveWorld()->GetLayerList()[(int)_layer]->GetObjectList();
}
