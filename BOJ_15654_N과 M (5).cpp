#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int n, int m, int input[], int output[], bool chk[], int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << output[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!chk[i]) {
            chk[i] = true;
            output[cnt] = input[i];
            dfs(n, m, input, output, chk, cnt + 1);
            chk[i] = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int* input = new int[n]();
    int* output = new int[n]();
    bool* chk = new bool[n]();

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input, input + n);

    dfs(n, m, input, output, chk, 0);

    return 0;
}

/* revised from https://jdselectron.tistory.com/26  */
