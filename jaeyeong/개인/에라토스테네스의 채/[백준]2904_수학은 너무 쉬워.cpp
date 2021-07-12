#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

bool e[MAX];
int n, a[100];
vector<int> prime;
int cnt[100][80000];  // 백만 루트 하면 80000 이정도 나옴
int totalCount[80000];  // 전체 숫자에서 소수가 나타난 횟수 
int gcdCount[80000];    // gcd가 될 것 같은 횟수 
int answer1, answer2;   // 가장 큰 점수, 최소 횟수  

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
        if (!e[i]) { //e[i]가 거짓이라면
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

    // 각 숫자별로 소수가 몇개씩 있을까????? ==> 소인수분해 
    for (int i = 0; i < n; i++) {
        int num = a[i];
        for (int j = 0; j < prime.size(); j++) {
            while (num % prime[j] == 0) { //a[i]에 prime[j]가 몇개 들어 있을까
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
        // 각 숫자들에 대해서 GCD되기 위해서 소수가 얼마나 부족한지 확인해본다 
        for (int j = 0; j < n; j++) {
            if (cnt[j][i] < gcdCount[i]) {
                answer2 += gcdCount[i] - cnt[j][i];
            }
        }
    }
    cout << answer1 << ' ' << answer2 << '\n';
}