#include <iostream>
using namespace std;

int depth = 0;
int max_depth = 0;

int Ackermann(int m, int n) {
    depth++;
    if (depth > max_depth) {
        max_depth = depth;
    }

    if (m == 0) {
        depth--;
        return n + 1;
    }
    else if (n == 0) {
        int result = Ackermann(m - 1, 1);
        depth--;
        return result;
    }
    else {
        int result = Ackermann(m - 1, Ackermann(m, n - 1));
        depth--;
        return result;
    }
}

int main() {
    int m, n;
    cout << "m: ", cin >> m;
    cout << "n: ", cin >> n;

    int result = Ackermann(m, n);
    cout << "A(" << m << ", " << n << ") = " << result << endl;
    cout << "Max depth: " << max_depth << endl;

    return 0;
}
