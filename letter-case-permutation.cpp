class Solution {
public:

void getPermutations(string &S,int i,vector <string> &res){

	if (i==S.size()){
		res.push_back(S);
	}else{
		if (!(S[i]>='0' && S[i]<='9')){
			getPermutations(S,i+1,res);
			S[i] = 'A' + S[i] - 'a'; //to uppercase
			getPermutations(S,i+1,res);
			S[i] = 'a' + S[i] - 'A'; //to lowercase
		}else
			getPermutations(S,i+1,res);
	}

}

vector <string> letterCasePermutation(string S){

	//initially converting all alphabets to lower case
	for (int i=0;i<S.size();i++){
		if (S[i]>='A' && S[i]<='Z'){
			S[i] = 'a' + S[i] - 'A';
		}
	}
	vector <string> res;
	getPermutations(S,0,res);
	return res;

}




};