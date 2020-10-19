typedef pair<int, int> Item;
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        constexpr int modv = pow(10,9) + 7;
        stack<Item> myst;
        int res = 0, presum = 0;
        for(int a: A){
            Item item(a, 1);
            while(!myst.empty() && myst.top().first > item.first){
                item.second += myst.top().second;
                presum -= myst.top().first * myst.top().second;
                myst.pop();
            }
            myst.push(item);
            presum = (presum + (item.first * item.second) % modv) % modv;
            res = (res + presum) % modv;
        }
        return res;
    }
};