class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    priority_queue <int> pq;
    for (int x :stones)
        pq.push(x);
    while(pq.size()){
        int max2;
        int max1 = pq.top();pq.pop();
        if (pq.size()){
          max2 = pq.top();pq.pop();}
        else {
            pq.push(max1);
            break;
             }
        if (max1!=max2)
            pq.push(abs(max1-max2));
        
    }
    return pq.size()?pq.top():0;
}
};