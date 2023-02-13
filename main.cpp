#include "pch.h"
#include "main.h"

namespace
{
    constexpr auto CLASS_NAME = L"UPDATENAME"; // TODO: update class name
    constexpr auto WINDOW_TITLE = L"UPDATETITLE"; // TODO: update window title
}

inline void CareHR(HRESULT hr)
{
    if (FAILED(hr)) { winrt::throw_hresult(hr); }
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hwnd, msg, wp, lp);
}

int main()
{
    auto const hInstance = GetModuleHandle(0);

    WNDCLASSEX wcx;
    wcx.cbSize = sizeof(wcx);
    wcx.style = CS_HREDRAW | CS_VREDRAW;
    wcx.lpfnWndProc = WindowProc;
    wcx.cbClsExtra = 0; // no extra class memory 
    wcx.cbWndExtra = 0; // no extra window memory 
    wcx.hInstance = hInstance; 
    wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcx.lpszMenuName = nullptr;
    wcx.lpszClassName = CLASS_NAME;
    wcx.hIconSm = nullptr; 

    CareHR(::RegisterClassEx(&wcx));

    auto const hwnd = ::CreateWindowEx(
        0,
        CLASS_NAME,
        WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW,
        0, 0, 960, 540, // x, y, w, h
        nullptr, // parent window
        nullptr, // menu
        hInstance,
        nullptr // additional application data
    );

    ::ShowWindow(hwnd, SW_NORMAL);

    MSG msg{};
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}