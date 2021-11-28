/*
 * BOJ 10775 공항
 */

#include <iostream>
#define MAX 100001
using namespace std;

int gate[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int G, P;
    cin >> G >> P;

    int answer = 0;
    bool shutdown = false;
    for (int i = 0; i < P; i++) {
           int g;
           cin >> g;

           if (!shutdown) {
               while (g > 0 && gate[g] > 0) {
                   int t = gate[g];
                   gate[g]++;
                   g -= t;
               }
               if (g > 0) {
                   gate[g] = 1;
                   answer++;
               }
               else {
                   shutdown = true;
               }
           }
    }
    cout << answer;
    return 0;
}