#include <complex>
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    MoveWindow(console, r.left, r.top, 1200, 600, TRUE); // 800 breite, 100 höhe
    const size_t limit = 1000, size = 100;
    const char letters[] = " 0@#?!-o*";
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