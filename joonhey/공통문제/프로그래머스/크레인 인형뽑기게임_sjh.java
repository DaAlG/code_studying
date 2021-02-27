import java.util.Arrays;
import java.util.Stack;

class Solution {
    static int[] topDoll;
    static int N;
    static Stack<Integer> bucket;
    static int answer;
    
    public void pushBucket(int doll){
        if(bucket.isEmpty() || doll != bucket.peek()){
            bucket.push(doll);
        }
        else{
            //같으면 pop 하면서 answer 증가
            answer++; 
            while(!bucket.isEmpty() && doll == bucket.peek()){
                answer++;
                bucket.pop();
            }
        }
    }
    
    
    public void moveCrain(int position, int[][] board){
        //하나라도 있을 경우만 시행
        if(topDoll[position] != N){
            pushBucket(board[(topDoll[position]++)][position]);
        }
    }
    
    public int solution(int[][] board, int[] moves) {
        N = board.length;
        bucket = new Stack<>();
        //1. topDoll 초기화 -> board 읽기.
        topDoll = new int[N]; //열 개수 만큼
        //열 우선탐색
        for(int j=0; j<N; j++){
            topDoll[j] = N;
            for(int i=0; i<N; i++){
                if(board[i][j] != 0)
                    topDoll[j]--;
            }
        }
        
        //2. moves 하나하나 읽으면서 topDoll 감소 & 스택 처리(인덱스 -1 유의)
        for(int i=0; i<moves.length; i++){
            moveCrain(moves[i]-1, board);
        }
        
        
        return answer;
    }
}