class Solution {
public:

vector <int> numberOfLines(vector <int> &widths, string S){
	vector <int> res(2,0);
	int n =0;
	int curWidth =0;
	for (int i=0;i<S.size();i++){
		if(curWidth + widths[S[i]- 'a'] > 100){
			curWidth = 0;
			n++;
			i--;
		}else{
			curWidth += widths[S[i] - 'a'];
		}
	}
    n++;
	res[0] = n;
	res[1] = curWidth;
	return res;
}

};