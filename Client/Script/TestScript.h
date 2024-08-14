#pragma once
#include "Application.h"

class TestScript
	: public Script
{
	
private:
	RectRenderer* rect;
	SpriteRenderer2D* sprite;
	Button* button;
public:
	void Start();
	void Update();
	void Fixedupdate();
	void OnEnable();
	void OnDisable();
	void OnDestroy();
	void OnCollisionEnter(Actor* _collision);
	void OnCollisionStay(Actor* _collision);
	void OnCollisionExit(Actor* _collision);
	void OnMouseEnter();
	void OnMouseStay();
	void OnMouseExit(); 
};

