#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
char a[MAX + 1], b[MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string x;
	cin >> x;
	string y;
	cin >> y;
	// store the letters in a char array
	int index = 0;
	for (int i = 0; i < (int) x.size(); i++) {
		a[index++] = x[i];
	}
	index = 0;
	for (int i = 0; i < (int) y.size(); i++) {
		b[index++] = y[i];
	}
	int n = int(strlen(a));
	int m = int(strlen(b));
	// add leading zeroes to make a and b equal in length
	reverse(a, a + n);
	reverse(b, b + m);
	while (n < m) {
		a[n++] = '0';
	}
	while (m < n) {
		b[m++] = '0';
	}
	// start from the end (meaning from the right side)
	// find the first index where the digits are different
	int p = n - 1;
	while (p >= 0 && a[p] == b[p]) {
		p--;
	}
	/*
		there will be three (3) cases:
		case 1: p < 0
		output: the two given numbers are equal
		
		case 2: a[p] < b[p]
		output: a is less than b
		
		case 3: a[p] > b[p]
		output: a is greater than b
	*/
	if (p < 0) {
		cout << "=";
	} else if (a[p] < b[p]) {
		cout << "<";
	} else {
		cout << ">";
	}
	cout << '\n';
	return 0;
}
