#include <string>
#include <vector>
#include <algorithm>
#define MAX 10000000
using namespace std;

bool prime[MAX];

void eratosthenes() {
    fill_n(prime, MAX, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * 2; j < MAX; j += i)
                prime[j] = false;
        }
    }
}

void comb(vector<int>& arr, string numbers, string res, int now) {
    if (now == numbers.size())
        return;

    if (!res.empty())
        arr.push_back(stoi(res));
    comb(arr, numbers, res, now + 1);

    res += numbers[now];
    arr.push_back(stoi(res));
    comb(arr, numbers, res, now + 1);
}

int solution(string numbers) {
    eratosthenes();
    sort(numbers.begin(), numbers.end());

    vector<int> num;

    do {
        comb(num, numbers, "", 0);
    } while (next_permutation(numbers.begin(), numbers.end()));

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    int answer = 0;
    for (int k : num) {
        if (prime[k]) {
            answer++;
        }
    }

    return answer;
}