#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#define PI 3.1415927
using namespace std;
int D = 0;
void move(int a, int b) {
    cout << ++D << ": ";
    cout << a << ' ' << b << endl;
}

void hanoi(int n, int a, int b, int c, int d) {
    if (n == 1) move(a, b);
    if (n == 2) {
        move(a, b);
        move(b, c);
        move(a, b);
        move(c, d);
        move(d, a);
        hanoi(n - 1, a, b, c, d);
    } else if (n != 1 && n != 2) {
        hanoi(n - 1, a, b, c, d);
        hanoi(n - 1, b, c, d, a);
        move(a, b);
        hanoi(n - 1, c, d, a, b);
        hanoi(n - 1, d, a, b, c);
        hanoi(n - 1, a, b, c, d);
    }
}
int main() {
    int n;
    cin >> n;
    hanoi(n, 0, 1, 2, 3);
}