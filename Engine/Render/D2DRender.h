#pragma once

class D2DRender
{
public:

	static void Initialize(HWND _hwnd);
	static void BeginDraw();
	static void EndDraw();
	static void Release();

	static HWND GetHWND() { return m_hwnd; }
	static ID2D1Factory* GetFactory() { return m_factory; }
	static IDWriteFactory* GetWriteFactory() { return m_writeFactory; }
	static IWICImagingFactory* GetIMGFactory() { return m_imgFactory; }
	static ID2D1HwndRenderTarget* GetRenderTarget() { return m_renderTarget; }
	static IDWriteTextFormat* GetTextFormat() { return m_textFormat; }
	static ID2D1SolidColorBrush* GetBrush() { return m_brush; }
	static ID2D1DeviceContext* GetDeviceContext() { return m_deviceContext; }

private:

	static HWND						 m_hwnd;
	static ID2D1Factory*			 m_factory;
	static IDWriteFactory*			 m_writeFactory;
	static IWICImagingFactory*		 m_imgFactory;
	static ID2D1HwndRenderTarget*	 m_renderTarget;
	static IDWriteTextFormat*		 m_textFormat;
	static ID2D1SolidColorBrush*	 m_brush;
	static ID2D1DeviceContext*		 m_deviceContext;

};

