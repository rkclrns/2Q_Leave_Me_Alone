#pragma once
#include "Component.h"

class Transform2D;
class Object;

class Camera2D
    : public Component
{
public:

    Camera2D();
    virtual ~Camera2D();

    virtual void Initialize()final;
    virtual void LateUpdate()final;
    virtual void Render()final;

    void         SetLayerProperty(LayerTag _layer, int _type) { m_LayerRenderProperty[(int)_layer] = _type; }
    void         SetBackGroundColor(D2D1_COLOR_F _color) { m_BackGroundColor = _color; }

    ID2D1BitmapRenderTarget* GetBitmapRenderTarget() { return m_cameraRenderTarget; }
    ID2D1BitmapRenderTarget* GetBlendingRenderTarget() { return m_blendRenderTarget; }
    int                      GetLayerRenderProperty(int _layer) { return m_LayerRenderProperty[_layer]; }
    D2D1_MATRIX_3X2_F CameraMatrix();               // ī�޶� ���
    Vector2 ScreenSize();                           // ī�޶� ȭ�� ũ�� (�� ������ ��������)
    Vector2 ScreenPosition(Transform2D* _dest);     // ��ũ�� ��ǥ��
    Vector2 ViewportPosition(Transform2D* _dest);   // ��ũ����ǥ�踦 ����ȭ�ؼ� ��Ÿ��.

    Vector2 viewRectPosition;                       // ȭ�鿡 ��ġ�� ī�޶� ��ġ
    D2D_SIZE_F viewportSize;                        // ȭ�鿡 ��ġ�� ī�޶� ������

    int GetRenderProcess() { return RenderProcess; }

private:
    int                         m_LayerRenderProperty[(int)LayerTag::SIZE];
    D2D1_COLOR_F                m_BackGroundColor; 

    ID2D1BitmapRenderTarget*    m_cameraRenderTarget; 
    ID2D1BitmapRenderTarget*    m_blendRenderTarget;
    ID2D1Bitmap*                m_bitmap;

    int RenderProcess = 0;

};

