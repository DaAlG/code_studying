
import java.util.*;

class Solution {
    static int res;
    static int[][] dist;
    static boolean[] visited;
    static int n, k;
    static class Node implements Comparable<Node>{
        int point;
        int dist;
        
        @Override
        public int compareTo(Node o){
            return this.dist - o.dist;
        }
        
        public Node(int point, int dist){
            this.point = point;
            this.dist = dist;
        }
    }
    static final int INF = Integer.MAX_VALUE;
    static int[] minDist;
    
    static PriorityQueue<Node> pq;
    
    //1번을 출발점으로 설정하기 위해 필요한 작업들 수행.
    public void startFromOne(){
        for(int i=2; i<=n; i++){
            minDist[i] = dist[1][i];
            pq.offer(new Node(i, minDist[i]));            
        }
        visited[1] = true;
    }
    //현재 점으로부터 거리를 재었을때 기존 비용보다 감소되는가?
    public static void updateDist(int start){
        for(int i=2; i<=n; i++){
            //방문된 점이거나 업데이트 할 수 없는 길이면 관심 없음...
            if(visited[i] || dist[start][i] == Integer.MAX_VALUE)
                continue;
//            만약 minDist가 max int 면 overflow 일어나서 음수 나옴.
            // 갈 수 있는 길일 때에만 재계산....
            if(minDist[i] > minDist[start] + dist[start][i]){
                minDist[i] = minDist[start] + dist[start][i];
                pq.offer(new Node(i, minDist[i]));
            }
        }        
    }
    //가장 가까운 점부터 방문해본답.
    public void dijikstra(){
        
        while(res != n){
            Node curNode = pq.poll();
            //방문한 점이면 필요 x
            if(visited[curNode.point])
                continue;
            //지금 가장 작은 점인 요 점이 k 보다 큰가 ?
            if(curNode.dist > k)
                break;
            //조건 통과 -> 답 추가
            visited[curNode.point] = true;
            res++;
            //경로 업데이트
            updateDist(curNode.point);
        }
    }
    
    public int solution(int N, int[][] road, int K) {
    //전역변수 설정
        n = N;
        k = K;
        visited = new boolean[N+1];
        dist = new int[N+1][N+1];
        minDist = new int[N+1];
        pq = new PriorityQueue<>();
        res = 1;
        //최대 거리 초기화
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                dist[i][j] = INF;
        //  기본 거리 정보 받아오기 
        for(int[] rInfo : road){
            //0, 1 은 도시, 2는 비용
            int city1 = rInfo[0];
            int city2 = rInfo[1];
            int curDist = rInfo[2];
            int savedDist = dist[city1][city2]; //저장된값.
            //정보가 중복 될 수 있으니 최소 경로만 저장하도록 처리한다.
            dist[city1][city2] = savedDist > curDist ? curDist : savedDist;
            dist[city2][city1] = dist[city1][city2];
        }
        startFromOne();
        dijikstra();
        //다익스트라
        return res;
    }

}