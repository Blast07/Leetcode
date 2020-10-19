class MedianFinder {
public:
    /** initialize your data structure here. */

	double cur_median;
	priority_queue <int> max_heap;
	priority_queue <int, vector <int>, greater<int>> min_heap;

    MedianFinder() {
		cur_median = 0;
    }
	double mean(){
		double med =  ((double)max_heap.top() + (double)min_heap.top())/2;
		return med;
	}
    
    void addNum(int num) {
		if (num >=cur_median ){ //insert in min heap
			if (min_heap.size() == max_heap.size()){
				min_heap.push(num);
				cur_median = min_heap.top();
			}
			else if (min_heap.size() < max_heap.size()){
				min_heap.push(num);
				cur_median = mean();
			}else{
				max_heap.push(min_heap.top()); min_heap.pop();
				min_heap.push(num);
				cur_median = mean();
			}
		
		}else{ //insert in max heap
			if (min_heap.size() == max_heap.size()){
				max_heap.push(num);
				cur_median = max_heap.top();
			}
			else if (min_heap.size() < max_heap.size()){
				min_heap.push(max_heap.top()); max_heap.pop();
				max_heap.push(num);
				cur_median = mean();
			}else{
				max_heap.push(num);
				cur_median = mean();
			}
		}
    }
    
    double findMedian() {
		return cur_median;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */