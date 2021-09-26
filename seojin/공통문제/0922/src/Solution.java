// 프로그래머스 거리두기 확인하기
// https://velog.io/@yanghl98/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B1%B0%EB%A6%AC%EB%91%90%EA%B8%B0-%ED%99%95%EC%9D%B8%ED%95%98%EA%B8%B0-JAVA%EC%9E%90%EB%B0%94 참고
class Solution {
    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];

        for(int t=0; t<places.length; t++) {
            String[] map = places[t];
            boolean flag = false;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (map[i].charAt(j)=='P') {
                        if (checkperson(i, j, map)) {
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag){ // 거리두기 안 지켜졌으면
                    answer[t] = 0;
                    break;
                }
            }
            if(!flag){ // 지금 대기실의 사람들의 거리두기가 잘 지켜졌으면
                answer[t] = 1;
            }
        }

        return answer;
    }

     public static boolean checkperson(int x, int y, String[] map){

        // 상하좌우 맨해튼 거리 1 
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
            if(map[nx].charAt(ny)=='P') return true;
        }
        
        // 상하좌우 맨해튼 거리 2
        int[] dx2 = {0, 0, 2, -2};
        int[] dy2 = {2, -2, 0, 0};
        for (int d = 0; d < 4; d++) {
            int nx = x + dx2[d];
            int ny = y + dy2[d];
            if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
            if(map[nx].charAt(ny)=='P') {
                if(map[(x+nx)/2].charAt((y+ny)/2)!='X'){  // 파티션이 있어야하는 위치에 없으면
                    return true;
                }
            }
        }

        // 대각선 확인
        int[] dx3 = {1, 1, -1, -1};
        int[] dy3 = {1, -1, 1, -1};

        for (int d = 0; d < 4; d++) {
            int nx = x + dx3[d];
            int ny = y + dy3[d];
            if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
            if(map[nx].charAt(ny)=='P') {
                if(!(map[x].charAt(ny)=='X' && map[nx].charAt(y)=='X')){ // 파티션이 있어야하는 위치에 없으면
                    return true;
                }
            }
        }

        return false;
    }
}
