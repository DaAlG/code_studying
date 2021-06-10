using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> gem(gems.begin(), gems.end()); //������ ����
    map<string, int>selected; //(����, ���� ���� ����)
    int start = 0, end = 0;
    int minDist = gems.size();
    int ansStart= 1 , ansEnd = gems.size();

    while (1) {
        if (minDist == 0) break;
        //��� ������ �� ��� ���
        if (selected.size() == gem.size()) {
            if (minDist > end - start) {
                minDist = end - start;
                ansStart = start + 1;
                ansEnd = end;
            }
            //������ �ϳ��� �����ϰ� ���� �ε��� ����
            if (selected[gems[start]] == 1) {
                selected.erase(gems[start]);
                start++;
            }
            //���� ������ ������ ���� ���� 1�� ���ҽ�Ű�� ���� �ε��� ����
            else if (selected[gems[start]] > 1) {
                selected[gems[start]]--;
                start++;
            }
        }
        //������ Ž���ϸ� ����
        else if (end == gems.size()) break;
        //���� ������ �� �������� ���ϸ� end �ε��� ����
        else {
            selected[gems[end]]++;
            end++;
        }
    }

    answer.push_back(ansStart);
    answer.push_back(ansEnd);
    return answer;
}

int main() {
    vector<string> gems = { "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
    vector<int> ans = solution(gems);
}

/*
* �� ������ ó�� �а� ���ö��� �˰����� LIS.
* LIS ����ϰ� �ڵ带 ¥������ �־��ǰ�� 100000*100000�� ����� �ð����⵵�� ���� �����̴� ^_��
* �����Ͽ� �������͸� ���� �Ұ����� �ʴµ�.. 6�� �߿� �н��ϴ� �� �� ����� �־���.
* ȿ�뼺 ���� �ڵ�
int length[MAX];
set<string> gem;
int minV = MAX + 1;
int ans = MAX + 1;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int n = gems.size();
    for (int i = 0; i < n; i++)
        gem.insert(gems[i]);

    for (int k = 0; k < n; k++) {
        set<string> selected;
        length[k] = MAX + 1;
        for (int i = k; 0 <= i; i--) {
            if (selected.find(gems[i]) == selected.end())
                selected.insert(gems[i]);
            if (gem == selected) {
                length[k] = i;
                if (k - i < minV) {
                    minV = k - i;
                    ans = k;
                }
                break;
            }
        }
    }
    answer.push_back(length[ans]+1);
    answer.push_back(ans+1);
    return answer;
}
*
*/