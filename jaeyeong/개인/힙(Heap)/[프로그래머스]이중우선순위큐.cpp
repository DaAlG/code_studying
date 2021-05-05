#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq;
    int pq_size = 0;

    int n = operations.size();
    for (int i = 0; i < n; i++) {
        string req = operations[i];
        if (req[0] == 'I') {
            string s = "";
            for (int i = 2; i < req.size(); i++)
                s += req[i];
            pq.push(stoi(s));
            pq_size++;
        }
        else if (req == "D 1") { //ÃÖ´ñ°ª »èÁ¦
            if (pq_size == 0) continue;
            pq.pop();
            pq_size--;
        }
        else { //ÃÖ¼Ú°ª »èÁ¦
            if (pq_size == 0) continue;
            pq_size--;
        }
    }
    if (pq_size == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(pq.top());
        for (int i = 1; i < pq_size; i++)
            pq.pop();
        answer.push_back(pq.top());
    }

    return answer;
}