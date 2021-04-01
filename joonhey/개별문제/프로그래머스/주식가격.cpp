#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    stack<pair<int, int>> s; //pair<돈, 시간>
    //prices 하나 하나 스택에 집어넣으면서 .. 
    int size = prices.size();
    int* tmpAns = new int[size];
    //as time goes by~~
    for(int curTime=0; curTime<size; curTime++){
        int curMoney = prices[curTime];
        pair<int, int> cur = make_pair(curMoney, curTime);
        //비어있지 않다면 확인
        if(s.size() != 0){
//cout<<"뭔가있음"<<endl;
           while(s.size() != 0 && s.top().first > curMoney){
               int highMoney = s.top().first;
                int pastTime = s.top().second;
      //         cout<<"top money "<< highMoney<<endl;
      //         cout<<"top time "<< pastTime<<endl;
                tmpAns[pastTime] = curTime - pastTime;
            //    cout<<"삽입 ?" << tmpAns[pastTime]<<endl;
                s.pop();
          }
       }
        s.push(cur);
    }
    //스택에 남은 거 -> 아직 안떨어진 애들.
    while(s.size() != 0){
        pair<int, int> cur = s.top();
        int pastTime = cur.second;
        tmpAns[pastTime] = size - 1 - pastTime; ///존버 탄 시각 기록.
        s.pop();
    }
    for(int i=0; i<size; i++){
        answer.push_back(tmpAns[i]);
    }
    return answer;
}