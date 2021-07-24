void ScreenToOpenGL(HWND hwnd, int x, int y, float* ox, float* oy)
{
    RECT rct;
    GetClientRect(hwnd, &rct);
    *ox = x / (float)rct.right * mapW;
    *oy = mapH - y / (float)rct.bottom * mapW;
}
