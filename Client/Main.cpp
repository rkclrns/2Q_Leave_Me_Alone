#include "Application.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    GameApplication App;

    Debug::Get();
    App.Initialize(hInstance, TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
    App.Run();
    App.Release();
    Debug::Free();
    return 0;
}
