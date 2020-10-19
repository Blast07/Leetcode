class Solution {
public:
struct TrieNode{
	//end is not required in this case
	TrieNode *zero;
	TrieNode *one;
	TrieNode(){
		zero = NULL;
		one = NULL;
	}
};

void insert(TrieNode *root, int num, int i){
	if(i<0)
		return;
	else{
		TrieNode *newNode = NULL;
		int bit = (num>>i) & 1;
		if(bit){
            if (root->one)
			    newNode = root->one;
            else{
                newNode = new TrieNode();
               root->one = newNode;
            }
        }else{
            if(root->zero)
                newNode = root->zero;
            else{
                newNode = new TrieNode();
                root->zero = newNode;
            }
        }
		insert(newNode, num, i-1);
	}

}
void findMax(TrieNode *one, TrieNode *zero, int tillNow, int &res, int i,bool flag){
	if( !(one || zero)){ //both null{
		return;
    }
	else if(!one){ //one is null
		findMax(zero->one, zero->zero, tillNow, res, i-1,flag);
	}else if(!zero){
		findMax(one->one, one->zero, tillNow, res, i-1,flag);
	}else{ //both not null;
        if(flag)
		    tillNow += pow(2,i);
		if ((one->one && zero->zero) || (one->zero && zero->one)){
			if (one->one && zero->zero){ //both not null
				findMax(one->one, zero->zero, tillNow, res, i-1,true);	
			}
			if(one->zero && zero->one){ //both not null
				findMax(zero->one, one->zero, tillNow, res, i-1,true);
			}
		}else{
			if((one->one && zero->one) || (one->zero && zero->zero) ){
				if(one->one && zero->one){
					findMax(one->one, zero->one, tillNow, res, i-1,false);
				}
				if(one->zero && zero->zero){
					findMax(one->zero, zero->zero, tillNow, res, i-1,false);
				}
			}else{
				//these are the last elements
				res= max (res,tillNow);
				return;	
			}
		}
	}
}

int findMaximumXOR(vector <int> &nums){
	TrieNode *root= new TrieNode();
	for (int i=0;i<nums.size();i++)	insert(root, nums[i],31);

	int res = 0;
	findMax(root->one, root->zero, 0,res, 31,true);
	return res;

}

};