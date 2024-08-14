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
    D2D1_MATRIX_3X2_F CameraMatrix();               // 카메라 행렬
    Vector2 ScreenSize();                           // 카메라 화면 크기 (걍 윈도우 사이즈임)
    Vector2 ScreenPosition(Transform2D* _dest);     // 스크린 좌표계
    Vector2 ViewportPosition(Transform2D* _dest);   // 스크린좌표계를 정규화해서 나타냄.

    Vector2 viewRectPosition;                       // 화면에 배치할 카메라 위치
    D2D_SIZE_F viewportSize;                        // 화면에 배치할 카메라 사이즈

    int GetRenderProcess() { return RenderProcess; }

private:
    int                         m_LayerRenderProperty[(int)LayerTag::SIZE];
    D2D1_COLOR_F                m_BackGroundColor; 

    ID2D1BitmapRenderTarget*    m_cameraRenderTarget; 
    ID2D1BitmapRenderTarget*    m_blendRenderTarget;
    ID2D1Bitmap*                m_bitmap;

    int RenderProcess = 0;

};

