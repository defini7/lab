// x - LOWORD(lParam), y - HIWORD(lParam)
// When you change size of the window, then
// case WM_SIZE:
//     WndResize(LOWORD(lParam), HIWORD(lParam));
//     break;
void WndResize(int x, int y)
{
    glViewport(0,0, x,y);
    float k = x / (float)y;
    float sz = 0.1f;
    glLoadIdentity();
    glFrustum(-k*sz, k*sz, -sz,sz, sz*2, 100);
}
