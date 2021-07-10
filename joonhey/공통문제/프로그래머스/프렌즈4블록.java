import java.util.*;

class Solution {
    static int M, N;
    static char[][] cBoard; //게임판.
    static ArrayList<Character>[] col; //열별로 저장 -> 사라지는 캐릭터 처리 위함.
    static int[] di, dj;
    static boolean[][] visited;
    static int answer;
    static Queue<Point> queue;
    static class Point{
            int x;
            int y;
            public Point(int x, int y){
                this.x = x;
                this.y = y;
            }
        }
    //이것부터 탐색 시작.
    public void bfs(int i, int j){
        answer++;
        visited[i][j] = true;
        queue.offer(new Point(i, j));
        int ni, nj;
        
        while(!queue.isEmpty()){
            Point cur = queue.poll();
            //현재 값 주변으로 popping이 가능하다면
            if(checkBingo(cur.x, cur.y)){
                for(int d = 0; d<3; d++){
                   ni =  cur.x + di[d];
                    nj = cur.y + dj[d];
                    //걔네들을 방문체크하고, answer을 증가시켜서 offer 한다.
                    if(!visited[ni][nj]){
                        visited[ni][nj] = true;
                        answer++;
                        queue.offer(new Point(ni, nj));
                    }
                }
            }
     
        }
        
    }
    
    //현재 위치 기준으로 4블록이 같나?
    public boolean checkBingo(int i, int j){
        char standard = cBoard[i][j];
        int ni, nj;
        for(int d=0; d<3; d++){
            //하나라도 범위 밖이거나 기준과 다르면 false
            ni = i + di[d];
            nj = j + dj[d];
            if(ni < 0 || ni >= M || nj < 0 || nj >= N || cBoard[ni][nj] != standard)
                return false;
        }
        return true;
    }
    public void updateBoard() {
    	//arrlist 업데이트
    	for(int j=0; j<N; j++) {
    		int cnt = 0; //몇개를 줄였느냐에 따라 뒤에 인덱스가 댕겨져서 값이 달라짐.
    		for(int i=0; i<M; i++) {
    			if(visited[i][j]) {
    				col[j].remove(i - cnt++);
    			}
    		}
    	}
    	//arrlist에 따라 담기.
    	for(int j=0; j<N; j++) {
    		int i = 0;
    		for(char c : col[j]) {
    			cBoard[i++][j] = c;
    		}
    		//비어있는 칸 -> Empty 처리.
    		while(i != M) {
    			cBoard[i++][j] = '1';
    		}
    	}
    }
    public int solution(int m, int n, String[] board) {
        //전역변수 초기화
        M = m;
        N = n;
        cBoard = new char[M][N];
        col = new ArrayList[N];
        di = new int[]{0,-1,-1};
        dj = new int[]{1,1,0};
        
        queue = new LinkedList<Point>();
        for(int i=0; i<N; i++)
        	col[i] = new ArrayList<>();
        
        //맨 윗칸부터 주어짐
        for(int i=0; i<M; i++){
            String str = board[M-1-i];
            for(int j=0; j<N; j++){
                cBoard[i] = str.toCharArray();
                col[j].add(cBoard[i][j]);
            }      
        }
        
        boolean found = false;
        int n1 = 0;
        //터지는 게 없을 때 까지 확인
        do{
        	//터지는 것에 따라 배열 재정비.
        	if(found) {
        		updateBoard();
        	}
            found = false;
            visited = new boolean[M][N];
            for(int i=0; i<M; i++){
                for(int j=0; j<N; j++){
                   //현재 위치 기준으로 세 방향 확인
                    if(cBoard[i][j] != '1' && !visited[i][j] && checkBingo(i,j) ){
                        found = true;
                        //bfs 탐색 시작.
                        bfs(i, j);
                    }
                }
            }
            
        } while(found);
        
        
        return answer;
    }
    

}