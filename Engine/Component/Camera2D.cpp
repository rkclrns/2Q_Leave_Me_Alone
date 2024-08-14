#include "pch.h"
#include "Camera2D.h"
#include "Transform2D.h"
#include "../World/Object/Object.h"
#include "../World/Manager/WorldManager.h"
#include "../Render/D2DRender.h"

Camera2D::Camera2D()
    : viewRectPosition({ 0.f,0.f }),
    viewportSize({ 0.f,0.f }),
    m_BackGroundColor(D2D1::ColorF(D2D1::ColorF::CadetBlue)),
    m_bitmap(nullptr)
{
    m_type = ComponentType::Camera;
    // �⺻ ���� ȭ�� �ػ󵵿� �°�
    RECT rc;
    GetClientRect(D2DRender::GetHWND(), &rc);
    D2D_SIZE_F res = { rc.right - rc.left, rc.bottom - rc.top };
    viewportSize = res;
}

Camera2D::~Camera2D()
{
}

void Camera2D::Initialize()
{
    D2DRender::GetDeviceContext()->CreateCompatibleRenderTarget(&m_cameraRenderTarget);
    D2DRender::GetDeviceContext()->CreateCompatibleRenderTarget(&m_blendRenderTarget);
}

void Camera2D::LateUpdate()
{
}

void Camera2D::Render()
{
    // bitmapRenderTarget�� BeginDraw ȣ��� ���ÿ� clearColor�� ������� Clear()�� ȣ�����ش�.
    m_cameraRenderTarget->BeginDraw();
    m_blendRenderTarget->BeginDraw();
    m_cameraRenderTarget->Clear(m_BackGroundColor);
    m_blendRenderTarget->Clear(D2D1::ColorF(0, 0, 0, 0));

    // ���� ����Ÿ���� �޾ƿ´�.
    ID2D1DeviceContext* deviceContext = D2DRender::GetDeviceContext();
    ID2D1Effect* blendEffect;
    deviceContext->CreateEffect(CLSID_D2D1Blend, &blendEffect);
    // ActiveWorld���� m_cullingLayer�� false�� ���̾ ��ȸ�ؼ� �ش� ������Ʈ�� Draw�� ȣ�� (���⼭ Draw�޼ҵ�� ���� Camera*�� �Ű������� �޴´�.)
    World* activeWorld = WorldManager::GetActiveWorld();

    // ���̾� �������� ī�޶� ��´�.
    for (int i = 0; i < (int)LayerTag::SIZE; i++)
    {
        RenderProcess = i;
        if (m_LayerRenderProperty[i] != Layer::Culling)
        {
            for (Object*& obj : activeWorld->GetLayerList()[i]->GetObjectList())
            {
                if (obj->GetTag() != ObjectTag::Camera || obj == gameObject)
                {
                    if (obj->GetState() == GameState::Active)
                    {
                            obj->Draw(this);
                    }
                }
            }
        }
    }
    // ������Ʈ�� Render���� ī�޶��� bitmapRenderTarget�� ��� ������ ��ġ�� �������� EndDraw�� ȣ���Ѵ�.
    m_cameraRenderTarget->EndDraw();
    m_blendRenderTarget->EndDraw();

    // bitmapRenderTarget�� GetBitmap�޼ҵ带 ȣ���� m_bitmap�� ��Ʈ�ʵ����͸� �����Ѵ�.
    SAFE_RELEASE(m_bitmap);
    m_cameraRenderTarget->GetBitmap(&m_bitmap);
    ID2D1Bitmap* blendBitmap;
    m_blendRenderTarget->GetBitmap(&blendBitmap);

    blendEffect->SetInput(0, m_bitmap);
    blendEffect->SetInput(1, blendBitmap);
    blendEffect->SetValue(D2D1_BLEND_PROP_MODE, D2D1_BLEND_MODE_OVERLAY);
    // ���� ����Ÿ�ٿ� ī�޶� ����ִ� ������Ʈ�� transform ���� ������� DrawBitmap�� �Ѵ�.
    D2D1_POINT_2F targetOffset = D2D1::Point2F(viewRectPosition.x, viewRectPosition.y);
    deviceContext->DrawImage(blendEffect);

    // ���� ����Ÿ�ٿ� ī�޶� ����ִ� ������Ʈ�� transform ���� ������� Drawbitmap�� �Ѵ�.
    /*D2D_RECT_F viewportRect = D2D1::RectF(viewRectPosition.x, viewRectPosition.y,
        viewRectPosition.x + viewportSize.width, viewRectPosition.y + viewportSize.height);

    deviceContext->DrawBitmap(m_bitmap, viewportRect);*/
    SAFE_RELEASE(blendBitmap);
    SAFE_RELEASE(blendEffect);
}

D2D1_MATRIX_3X2_F Camera2D::CameraMatrix()
{
    RECT rc;
    GetClientRect(D2DRender::GetHWND(), &rc);
    Vector2 res = { rc.right - rc.left, rc.bottom - rc.top };
    res *= gameObject->transform->scale;
    D2D1_MATRIX_3X2_F cameraMatrix = gameObject->transform->GetWorldMatrix();
    cameraMatrix = cameraMatrix * Transform2D::TranslateMatrix((-res.x) * 0.5f, (-res.y) * 0.5f);

    D2D1InvertMatrix(&cameraMatrix);

    return cameraMatrix;
}

Vector2 Camera2D::ScreenSize()
{
    RECT rc;
    GetClientRect(D2DRender::GetHWND(), &rc);
    Vector2 res = { rc.right - rc.left, rc.bottom - rc.top };
    return res;
}

Vector2 Camera2D::ScreenPosition(Transform2D* _dest)
{
    D2D1_MATRIX_3X2_F matrix = _dest->GetWorldMatrix() * CameraMatrix();
    return { matrix.dx, matrix.dy };
}

Vector2 Camera2D::ViewportPosition(Transform2D* _dest)
{
    Vector2 screenSize = ScreenSize();
    Vector2 screenPosition = ScreenPosition(_dest);

    Vector2 viewRectPosition = {
        screenPosition.x / screenSize.x,
        screenPosition.y / screenSize.y
    };

    return viewRectPosition;
}
