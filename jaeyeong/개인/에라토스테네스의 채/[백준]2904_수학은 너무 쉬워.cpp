#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

bool e[MAX];
int n, a[100];
vector<int> prime;
int cnt[100][80000];  // �鸸 ��Ʈ �ϸ� 80000 ������ ����
int totalCount[80000];  // ��ü ���ڿ��� �Ҽ��� ��Ÿ�� Ƚ�� 
int gcdCount[80000];    // gcd�� �� �� ���� Ƚ�� 
int answer1, answer2;   // ���� ū ����, �ּ� Ƚ��  

void era() {
    e[1] = true;
    for (int i = 2; i < MAX; i++) {
        if (e[i]) continue;
        // i is prime 
        for (int j = i*2; j < MAX; j += i) {
            e[j] = true;
        }
    }
    for (int i = 2; i < MAX; i++) {
        if (!e[i]) { //e[i]�� �����̶��
            prime.push_back(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    era();

    // �� ���ں��� �Ҽ��� ��� ������????? ==> ���μ����� 
    for (int i = 0; i < n; i++) {
        int num = a[i];
        for (int j = 0; j < prime.size(); j++) {
            while (num % prime[j] == 0) { //a[i]�� prime[j]�� � ��� ������
                cnt[i][j]++;
                totalCount[j]++;
                num /= prime[j];
            }
        }
    }
    for (int i = 0; i < prime.size(); i++) {
        gcdCount[i] = totalCount[i] / n;
    }
    answer1 = 1;
    for (int i = 0; i < prime.size(); i++) {
        for (int j = 0; j < gcdCount[i]; j++) {
            answer1 *= prime[i];
        }
        // �� ���ڵ鿡 ���ؼ� GCD�Ǳ� ���ؼ� �Ҽ��� �󸶳� �������� Ȯ���غ��� 
        for (int j = 0; j < n; j++) {
            if (cnt[j][i] < gcdCount[i]) {
                answer2 += gcdCount[i] - cnt[j][i];
            }
        }
    }
    cout << answer1 << ' ' << answer2 << '\n';
}