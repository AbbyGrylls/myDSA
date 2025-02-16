#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "9959387572";
    string b = "8328346124";
    int n = a.size();
    int k = 0;
    int c[10];

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            k = 1;
            break;
        } else if (a[i] < b[i]) {
            swap(a, b); // Correct way to swap strings
            k = 2;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < b[i]) {
            a[i - 1] = a[i - 1] - 1;
            a[i] = a[i] + 10;
            c[i] = a[i] - b[i];
        } else {
            c[i] = a[i] - b[i];
        }
    }

    if (k == 2) {
        c[0] = -(a[0] - b[0]);
    } else {
        c[0] = a[0] - b[0];
    }

    for (int i = 0; i < n; i++) {
        cout << c[i];
    }

    return 0;
}
