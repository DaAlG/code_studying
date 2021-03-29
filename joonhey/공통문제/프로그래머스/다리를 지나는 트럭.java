import java.util.Queue;
import java.util.LinkedList;

class Solution {
    static class Truck{
        int b;
        int w;
        public Truck(int b, int w){
            this.b = b;
            this.w = w;
        }
    }
    static Queue<Truck> queue;
    
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int curTime = 0;
        queue = new LinkedList<>();
        int curWeight = 0; //현재 도로 위의 트럭 무게.
        //맨 처음꺼 넣기.
        queue.offer(new Truck(curTime, truck_weights[0]));
        int lastTime = 0;
        curWeight += truck_weights[0];
        int size = truck_weights.length;
        for(int i = 1; i<size; i++){
            int truckWeight = truck_weights[i];
            //공존 ㄱㄴ
            if(curWeight + truckWeight <= weight){
                queue.offer(new Truck(++curTime, truckWeight));
                lastTime = curTime;

            }
            //공존ㅂㄱㄴ
            else{
                //무게 될 때까지 빼내긔.
                Truck lastTruck;
                while(!queue.isEmpty() && curWeight + truckWeight > weight){
                    lastTruck = queue.poll();
                    curWeight -= lastTruck.w;
                    curTime = lastTruck.b + bridge_length;
                }
                //내 앞 바로 다음 vs 큰 거 지나가고 둘 중 뒤늦게 -> 교통사고 예방.
                curTime = curTime >= lastTime + 1 ? curTime : lastTime + 1;
                queue.offer(new Truck(curTime, truckWeight));
                lastTime = curTime;
            }
            curWeight += truckWeight;
        }
        
        //비어있지 않음 -> while로 처리해줘야.
        while(!queue.isEmpty()){
            curTime = queue.poll().b + bridge_length + 1;
        }
        
        return curTime;
    }
}