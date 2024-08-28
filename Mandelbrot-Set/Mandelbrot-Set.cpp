#include <complex>
#include <iostream>
#include <windows.h>
using namespace std;
#pragma comment(lib, "user32")
void maxsc()
{
    HWND Hwnd = GetForegroundWindow();
    ShowWindow(Hwnd, SW_MAXIMIZE);
}
void fullsc()
{
    HWND Hwnd = GetForegroundWindow();
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    LONG winstyle = GetWindowLong(Hwnd, GWL_STYLE);
    SetWindowLong(Hwnd, GWL_STYLE, (winstyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
    SetWindowPos(Hwnd, HWND_TOP, 0, 0, x, y, 0);

}
int main() {
    fullsc();
    maxsc();
    const size_t limit = 1000, size = 100;
    const char letters[] = " 0O@#?!-o*";
    for (size_t iy = 0; iy <= size; iy++) {
        for (size_t ix = 0, count = 0; ix <= size; ix++, count = 0) {
            complex<double> c(-2.0 + ix * 2.5 / size, 1.15 - iy * 2.3 / size), z(0.0, 0.0);
            while (norm(z) < 4.0 && count++ < limit) z = z * z + c;
            cout << ((count >= limit) ? letters[0] : letters[min(count, sizeof(letters) - 2)]);
        }
        cout << endl;
    }
    return 0;
}
