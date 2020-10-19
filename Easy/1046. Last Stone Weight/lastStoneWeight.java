class Solution {
    public int lastStoneWeight(int[] stones) {
        if(stones == null || stones.length == 0){
            return 0;
        }
        Comparator<Integer> cmp = (o1, o2) -> o2-o1;
        PriorityQueue<Integer> q = new PriorityQueue<>(cmp);
        for(int n : stones){
            q.offer(n);
        }
        while(q.size() >= 2){
            int y = q.poll();
            int x = q.poll();
            if(x != y){
                q.add(y - x);
            }
        }
        return q.isEmpty()? 0 : q.peek();
    }
}