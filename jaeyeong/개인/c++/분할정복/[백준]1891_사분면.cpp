using namespace std;
#include <iostream>
#include <string>
long long two[51];

//사분면의 조각 번호가 저장되어 있는 문자열을 하나하나 검사하여 좌표를 얻는 함수
pair<long long, long long> go(string& a, int index, long long r, long long c, long long size) {
    if (size == 1) {
        return make_pair(r, c);
    }
    else {
        if (a[index] == '1') {
            return go(a, index + 1, r, c + size / 2, size / 2);
        }
        else if (a[index] == '2') {
            return go(a, index + 1, r, c, size / 2);
        }
        else if (a[index] == '3') {
            return go(a, index + 1, r + size / 2, c, size / 2);
        }
        else if (a[index] == '4') {
            return go(a, index + 1, r + size / 2, c + size / 2, size / 2);
        }
    }
    return make_pair(0, 0);
}

string solve(long long r, long long c, long long size, long long x, long long y) {
    if (size == 1) {
        return "";
    }
    if (x < r + size / 2 && y < c + size / 2) {
        return "2" + solve(r, c, size / 2, x, y);
    }
    else if (x < r + size / 2 && y >= c + size / 2) {
        return "1" + solve(r, c + size / 2, size / 2, x, y);
    }
    else if (x >= r + size / 2 && y < c + size / 2) {
        return "3" + solve(r + size / 2, c, size / 2, x, y);
    }
    else {
        return "4" + solve(r + size / 2, c + size / 2, size / 2, x, y);
    }
}
int main() {
    two[0] = 1;
    for (int i = 1; i <= 50; i++) {
        two[i] = two[i - 1] * 2LL;//long long 2를 곱하는 것과 같다
    }
    int n;
    string a;
	cin >> n >> a;
    long long size = two[n];

    //사분면 조각번호의 해당 좌표
	auto p = go(a, 0, 0, 0, size);
    //좌표 이동
    long long x, y;
    cin >> x >> y;
    y = -y;
    p.first += y;
    p.second += x;

    if (0 <= p.first && p.first < size && 0 <= p.second && p.second < size) {
        cout << solve(0, 0, size, p.first, p.second) << '\n';
    }
    else {
        cout << -1 << '\n';
    }
    return 0;
}