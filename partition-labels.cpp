class Solution {
public:
   vector <int> partitionLabels(string S){
	vector <int> mem(26,-1);
	vector <int> res;

	for (int i=0;i<S.size();i++){
		if (mem[S[i]-'a'] == -1){
			mem[S[i]-'a'] = res.size();
			res.push_back(1);
		}else{
			int ind = mem[S[i]-'a'];
			int j = res.size()-1;
			while(j>ind){
				res[j-1] += res[j];
				res.pop_back();
				j--;
			}
           res[res.size()-1]++; 

			for (int k=i-res.back()+1; k <= i;k++){
				mem[S[k]-'a'] = ind;	
			}
		}
	}
	return res;

}

};