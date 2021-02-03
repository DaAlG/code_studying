package practice;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;
public class Solution {
    static int posX, posY;
    static char[][] map;
    static char curDir; // 현재 방향
    static int Width, Height;
    static int[] di = { -1, 1, 0, 0 };
    static int[] dj = { 0, 0, -1, 1 };
    static char[] shape = {'^','v','<','>'};
    static HashMap<Character, Integer> Direction = new HashMap<>();
    public static void updateMap(char keyInput) {
        int ni, nj;
        ni = posX;
        nj = posY;
        if (keyInput == 'S') { // 포탄 발사
            do {
            ni += di[Direction.get(curDir)];
            nj += dj[Direction.get(curDir)];
            //범위를 뚫거나 벽을 만날 때까지 이동.
            }while(ni >=0 && nj >=0 && ni<Height && nj < Width && map[ni][nj] != '#' && map[ni][nj] != '*');
             
            //벽돌 벽이라면 평지로 바꾼다. indexOutOfBound 에러 주의
            if(ni >=0 && nj >=0 && ni<Height && nj < Width &&  map[ni][nj] == '*') {
                map[ni][nj] = '.';
            }
        } else { // 위치 확인 후 이동, 방향 무조건 변경
            // 이동못해도 방향 변경은 ㄱㄴ
            curDir = keyInput;
            map[posX][posY] = shape[Direction.get(curDir)];
            ni += di[Direction.get(curDir)];
            nj += dj[Direction.get(curDir)];
            // 범위 내, 평지일 때만 이동. 아니면 이동 X
            if (ni >= 0 && ni < Height && nj >= 0 && nj < Width && map[ni][nj] == '.') {
                map[posX][posY] = '.';
                posX = ni;
                posY = nj;
                //멥에 기록도
                map[posX][posY] = shape[Direction.get(curDir)];
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        int T;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        String inputLine;
        boolean carFound;
        char input;
        int keyLength;
        Direction.put('U',0);  Direction.put('D',1);  Direction.put('L',2);  Direction.put('R',3);
        for (int t = 1; t <= T; t++) {
            carFound = false;
            StringTokenizer st = new StringTokenizer(br.readLine());
            // 지도, 전차 정보 입력
            Height = Integer.parseInt(st.nextToken());
            Width = Integer.parseInt(st.nextToken());
            map = new char[Height][Width];
            for (int i = 0; i < Height; i++) {
                inputLine = br.readLine();
                for (int j = 0; j < Width; j++) {
                    input = inputLine.charAt(j);
                    map[i][j] = input;
                    // 현재 전차 위치 기록
                    if (!carFound && "^v<>".indexOf(input) != -1) {
                        carFound = true;
                        posX = i;
                        posY = j;
                        switch (input) {
                        case '^':
                            curDir = 'U';
                            break;
                        case 'v':
                            curDir = 'D';
                            break;
                        case '<':
                            curDir = 'L';
                            break;
                        case '>':
                            curDir = 'R';
                            break;
                        default:break;
                        }
                    }
 
                }
            }
            keyLength = Integer.parseInt(br.readLine()); // 키 개수
            // 사용자 입력에 따라 지도 상태 업데이트
            inputLine = br.readLine();
            for (int i = 0; i < keyLength; i++) {
                updateMap(inputLine.charAt(i));
            }
 
            // 출력
            System.out.print("#" + t + " ");
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    System.out.print(map[i][j]);
                }
                System.out.println();
            }
        }
    }
}