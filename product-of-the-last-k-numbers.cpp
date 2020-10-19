class ProductOfNumbers {
    vector <int> pp;
public:
    ProductOfNumbers() {
    	vector <int> pp;    
    }
    
    void add(int num) {
		if (num==0)
			pp.clear();
		else if (pp.size()==0)
			pp.push_back(num);
		else 
			pp.push_back(pp.back()*num);
        
    }
    
    int getProduct(int k) {
		if (k > pp.size())
			return 0;

    	int div = pp.size() - k -1; 
		if (div <0)
			return pp.back();
		return pp.back()/pp[div];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */