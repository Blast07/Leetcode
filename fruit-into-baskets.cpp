class Solution {
public:
int totalFruit(vector <int> &tree){
	
	int res =0;
	int type1 = -1;
	int type2 = -1;
	int i =0,j=0;

	while(j<tree.size()){
		if(tree[j]==type1){
			j++;
		}else if(tree[j]==type2){
			j++;
		}else{
			if(type1==-1){
				type1 = tree[j++];
			}else if(type2 == -1){
				type2 = tree[j++];
			}else{
                
				type1 = tree[j-1];
                type2 = tree[j];
                i =j-1;
                while(tree[i]==type1){
                    i--;
                }
                i++;
                j++;
			
			}
			
		}
		res = max(res, j-i);
	}
	return res;

}

};