#include <iostream>
#include <vector>
#include <string>
using namespace std;
int count(int mask, vector<int>& words) {
    int cnt = 0;
    for (int word : words) {
        if ((word & ((1 << 26) - 1 - mask)) == 0) { //i��° �ܾ �����ϴ� ���ĺ�
            //mask: ���ٰ� �� ���ĺ�
            //����� ���� ���ĺ��� �ܾ��� �ִ��� �˻��ؾ� ��(& ����)
            cnt += 1;
        }
    }//��� �ܾ ���ؼ� �� ���ĺ��� ����� �ִ��� ������ �ϳ��� �� ������������ �̰Ŵ� ��Ʈ����ũ�� �ذ� ����
   
    return cnt;
}
int go(int index, int k, int mask, vector<int>& words) {
    /*
    index: ���ĺ�
    k: �ε���
    mask: ��� ���ĺ��� ��Ʈ����ũ
    &words: �ܾ�
    */
    if (k < 0) return 0; //��� �� �ִ� �ܾ� 0��
    if (index == 26) {
        return count(mask, words); // ���� ����
    }
    int ans = 0;
    int t1 = go(index + 1, k - 1, mask | (1 << index), words);//index ��° ���ĺ��� ���� ��� ������ϱ� k-1, ��Ʈ����ũ�� �߰�
    if (ans < t1) ans = t1;
    if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
        t1 = go(index + 1, k, mask, words);//����� �ʴ� ���
        if (ans < t1) ans = t1;
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> words(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char x : s) {
            words[i] |= (1 << (x - 'a'));
        }
    }
    cout << go(0, m, 0, words) << '\n';
    return 0;
}
