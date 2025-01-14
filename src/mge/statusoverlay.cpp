
#include "statusoverlay.h"
#include "configuration.h"
#include "mged3d8device.h"
#include "proxydx/d3d9header.h"

#include <cstdio>



namespace StatusOverlay {
    char statusText[512];
    char fpsText[16];
    DWORD statusTimeout;
    int currentPriority;

    ID3DXFont* font;
    RECT statusRect, fpsRect;
}

bool StatusOverlay::init(IDirect3DDevice9* device) {
    D3DXCreateFont(device, 12, 0, 400, 1, false, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                   DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Lucida Console", &font);

    statusRect = {5, 5, 635, 20};
    fpsRect = {5, 25, 160, 40};
    return true;
}

void StatusOverlay::release() {
    font->Release();
}

void StatusOverlay::show(IDirect3DDevice9* device) {
    if (!(Configuration.MGEFlags & DISPLAY_MESSAGES)) {
        return;
    }

    if ((Configuration.MGEFlags & FPS_COUNTER) || statusTimeout) {
        if (Configuration.MGEFlags & FPS_COUNTER) {
            font->DrawTextA(NULL, fpsText, -1, &fpsRect, DT_NOCLIP, 0xffffffff);
        }

        if (statusText[0] != 0) {
            if (GetTickCount() < statusTimeout) {
                font->DrawTextA(NULL, statusText, -1, &statusRect, DT_NOCLIP, 0xffffffff);
            } else {
                statusTimeout = 0;
                currentPriority = 0;
            }
        }
    }
}

void StatusOverlay::setStatus(const char* s, int priority) {
    if (priority >= currentPriority) {
        std::snprintf(statusText, sizeof(statusText), "%s", s);
        statusTimeout = GetTickCount() + priority * Configuration.StatusTimeout;
        currentPriority = priority;
    }
}

void StatusOverlay::setFPS(float fps) {
    std::snprintf(fpsText, sizeof(fpsText), "%4.0f", fps);
}

void StatusOverlay::showLastStatus() {
    statusTimeout = GetTickCount() + Configuration.StatusTimeout;
}
