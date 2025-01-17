#pragma once

class Camera2D;
class Object;
class Actor;

class Component abstract
{
public:
	virtual			~Component() {}
	void			SetState(GameState _state) { m_state = _state; }
	ComponentType	GetType() { return m_type; }
	GameState		GetState() { return m_state; }

	virtual void	Initialize() {}
	virtual void	FixedUpdate() {}
	virtual void	EarlyUpdate() {}
	virtual void	Update() {}
	virtual void    LateUpdate() {}
	virtual bool	Draw(Camera2D* _camera) { return false; }
	virtual void	Render() {}

	Actor* gameObject = nullptr; // 자신을 소유한 오브젝트 (const로 바꿀 방법을 찾자)

protected:

	ComponentType  	m_type;
	GameState	    m_state = GameState::Active;

};