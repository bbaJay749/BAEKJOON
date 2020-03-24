/* Dumb way cannot beat the time limit*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> change(vector<int> children, int origin, int at);
bool check(vector<int> children, int N);
int cal(vector<int> children, int N);

int main() {
	int N = 0, counter = 0;
	cin >> N;
	vector<int> children(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &children[i]);
	}

	while (!check(children, N)) {
		int k = cal(children, N);
		children = change(children, k, children[k]);
		counter++;
	}

	printf("%d\n", &counter);

	return 0;
}

vector<int> change(vector<int> children, int origin, int at) {
	int origin_temp = children[origin];

	if (origin > at) {
		for (int i = 0; i <= origin - at; i++) {
			children[origin - i] = children[origin - i - 1];
		}
		children[at] = origin_temp;
	}
	else if (origin < at) {
		for (int i = 0; i < at - origin; i++) {
			children[origin + i] = children[origin + i + 1];
		}
		children[at] = origin_temp;
	}

	return children;
}

int cal(vector<int> children, int N) {   // find the index has the biggest diff
	vector<int> diff(N + 1, 0);
	int result = 0;

	for (int i = 1; i <= N; i++) {
		diff[i] = abs(children[i] - i);
	}

	for (int i = 1; i < N; i++) {
		if (diff[i] > diff[i + 1]) {
			result = i;
		}
	}

	return result;
}

bool check(vector<int> children, int N) {
	bool checker = true;

	for (int i = 1; i <= N; i++) {
		if (children[i] != i) checker = false;
	}

	return checker;
}
