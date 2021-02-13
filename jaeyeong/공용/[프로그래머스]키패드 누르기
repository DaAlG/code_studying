#include <string>
#include <vector>
#include <iostream>

using namespace std;

int pad[4][10] = {}, num2 = 0, num5 = 1, num8 = 2, num0 = 3;

int getLength(int num, int k) {
    if (num == 2)
        return pad[num2][k];
    else if (num == 5)
        return pad[num5][k];
    else if (num == 8)
        return pad[num8][k];
    else
        return pad[num0][k];
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int curR = -1, curL = -1, lenR=0, lenL=0, n;


    //키패드 거리
    pad[num2][1] = 1;
    pad[num2][3] = 1;
    pad[num2][4] = 2;
    pad[num2][5] = 1;
    pad[num2][6] = 2;
    pad[num2][7] = 3;
    pad[num2][8] = 2;
    pad[num2][9] = 3;
    pad[num2][0] = 3;

    pad[num5][1] = 2;
    pad[num5][2] = 1;
    pad[num5][3] = 2;
    pad[num5][4] = 1;
    pad[num5][6] = 1;
    pad[num5][7] = 2;
    pad[num5][8] = 1;
    pad[num5][9] = 2;
    pad[num5][0] = 2;

    pad[num8][1] = 3;
    pad[num8][2] = 2;
    pad[num8][3] = 3;
    pad[num8][4] = 2;
    pad[num8][5] = 1;
    pad[num8][6] = 2;
    pad[num8][7] = 1;
    pad[num8][9] = 1;
    pad[num8][0] = 1;

    pad[num0][1] = 4;
    pad[num0][2] = 3;
    pad[num0][3] = 4;
    pad[num0][4] = 3;
    pad[num0][5] = 2;
    pad[num0][6] = 3;
    pad[num0][7] = 2;
    pad[num0][8] = 1;
    pad[num0][9] = 2;
    
    //solution
    for (int i = 0; i < numbers.size(); i++) {
        n = numbers[i];
        if (n == 1 || n == 4 || n == 7) {
            curL = n;
            answer.append("L");
        }else if (n == 3 || n == 6 || n == 9) {
            curR = n;
            answer.append("R");
        }
        else {
            if (curL < 0)
                lenL = getLength(0, n) + 1;
            else
                lenL = getLength(n, curL);

            if (curR < 0)
                lenR = getLength(0, n) + 1;
            else
                lenR = getLength(n, curR);

            if (lenL == lenR) {
                if (hand == "right") {
                    answer.append("R");
                    curR = n;
                }
                else {
                    answer.append("L");
                    curL = n;
                }
                continue;
            }
            if (lenL < lenR) {
                answer.append("L");
                curL = n;
            }
            else {
                answer.append("R");
                curR = n;
            }
            
        }
    }
    return answer;
}


int main() {
    vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
    string hand= "right";

    cout << solution(numbers, hand);

}
