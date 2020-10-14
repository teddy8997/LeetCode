class RecentCounter {
    Queue<Integer> q;
    public RecentCounter() {
        q = new LinkedList<Integer>();
    }
    
    public int ping(int t) {
        while(!q.isEmpty()){
            if(q.peek() + 3000 >= t){
                break;
            }
            q.poll();
        }
        q.offer(t);
        return q.size();
    }
}