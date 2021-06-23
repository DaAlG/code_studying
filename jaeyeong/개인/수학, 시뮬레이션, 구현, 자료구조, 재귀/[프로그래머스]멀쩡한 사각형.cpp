using namespace std;
#include <iostream>

long long gcd(long long a, long long b) {
    long long minv = min(a, b);
    long long res;
    for (int i = 1; i <= minv; i++) {
        if (a % i == 0 && b % i == 0) res = i;
    }
    return res;
}

long long solution(int w, int h) {
    long long answer;
    long long lw = (long long)w;
    long long lh = (long long)h;
    long long g = gcd(w, h); //w와 h의 최대공약수
    answer = lw * lh - lw - lh + g;
    return answer;
}