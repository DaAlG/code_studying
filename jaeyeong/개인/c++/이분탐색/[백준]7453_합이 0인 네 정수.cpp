#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
typedef long long LL;

int n;
vector<int> a, b, c, d;
vector<int> ab, cd;

LL st2_2() {
    LL res = 0, cnt = 0;
    // 전략 2. 정렬 ==>
    // 전략 2-2. 안쓰고 ==> 
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    int p_cd = cd.size() - 1;
    for (int p_ab = 0; p_ab < ab.size(); p_ab++) {
        int target = -ab[p_ab];
        if (0 < p_ab && ab[p_ab] == ab[p_ab - 1]) {
            res += cnt;
        }
        else {
            while (0 <= p_cd && target < cd[p_cd]) {
                p_cd--;
            }
            cnt = 0;
            while (0 <= p_cd && target == cd[p_cd]) {
                cnt++;
                p_cd--;
            }
            res += cnt;
        }
    }
    return res;
}

LL st1_2() {
    LL res = 0, cnt = 0;
    // 전략 2. 정렬 ==>
    // 전략 2-2. 안쓰고 ==>
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    for (int i = 0 ; i < ab.size() ; i++) {
        int b_pre = lower_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
        int b_end = upper_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
        res += (b_end - b_pre);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v, w, x;
        cin >> u >> v >> w >> x;
        a.push_back(u);
        b.push_back(v);
        c.push_back(w);
        d.push_back(x);
    }
    // a,b 로 만들수 있는 합의 조합 ==> ab
    // c,d로 만들수 있는 합의 조합 ==> cd
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }

    //printf("%lld", st_1());
    //printf("%lld", st_2_1());
    cout << st2_2() << '\n';
    return 0;
}