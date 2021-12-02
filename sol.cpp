#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int len_a = a.size();
	int len_b = b.size();
	// check if all the digits are a and/or b are equal to 0
	bool checker_a = true;
	for (int i = 0; i < len_a; i++) {
		if (a[i] != '0') {
			checker_a = false;
			break;
		}
	}
	bool checker_b = true;
	for (int i = 0; i < len_b; i++) {
		if (b[i] != '0') {
			checker_b = false;
			break;
		}
	}
	if (checker_a && checker_b) {
		cout << '=';
	} else if (checker_a) {
		cout << '<';
	} else if (checker_b) {
		cout << '>';
	}
	if (checker_a || checker_b) {
		return 0;
	}
	// remove the leading zeroes in a and b (if there are)
	int start = -1;
	for (int i = 0; i + 1 < len_a; i++) {
		if (a[i] == '0' && a[i + 1] != '0') {
			start = i + 1;
			break;
		} else if (a[i] != '0') {
			break;
		}
	}
	if (start != -1) {
		a = a.substr(start, len_a - start + 1);
		len_a = a.size();
	}
	start = -1;
	for (int i = 0; i + 1 < len_b; i++) {
		if (b[i] == '0' && b[i + 1] != '0') {
			start = i + 1;
			break;
		} else if (b[i] != '0') {
			break;
		}
	}
	if (start != -1) {
		b = b.substr(start, len_b - start + 1);
		len_b = b.size();
	}
	// compare digit by digit starting from the left side
	char ans = '=';
	if (len_a < len_b) {
		ans = '<';
	} else if (len_a > len_b) {
		ans = '>';
	} else {
		for (int i = 0; i < len_a; i++) {
			if (a[i] < b[i]) {
				ans = '<';
				break;
			} else if (a[i] > b[i]) {
				ans = '>';
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
