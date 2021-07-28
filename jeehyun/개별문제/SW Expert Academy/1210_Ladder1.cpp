#include<iostream>
#include <cstring>
using namespace std;

int map[100][100];

int main(int argc, char** argv)
{
    int T = 10;

    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> test_case;

        int x = 99;
        int y = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> map[i][j];
                if (map[i][j] == 2)
                    y = j;
            }
        }

        while (x--) {
            bool check = false;
            while (y + 1 < 100 && map[x][y + 1]) {
                check = true;
                y++;
            }

            if (!check) {
                while (y - 1 >= 0 && map[x][y - 1]) y--;
            }
        }
        cout << "#" << test_case << " " << y << "\n";
    }
    return 0;
}