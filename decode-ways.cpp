class Solution {
public:

    int decode(string s,int cur,int *DP){
	if(cur > s.size())
		return 0;
	else if(cur==s.size()|| cur==s.size()-1){
		if (s[cur]!='0')
			return 1;
		else return 0;
	}
	else{
		if (DP[cur]!=-1)
			return DP[cur];
		
		int first_only=0,both=0;
		if (s[cur]!='0')
			first_only = decode(s,cur+1,DP); //considering only first digit
		if (cur+2<=s.size() && s[cur]!='0'){
			int t = stoi(string(s,cur,2));
			if (t>0 && t<27)
				both = decode(s,cur+2,DP);
		}

		DP[cur] = first_only + both;
		return DP[cur];
	

	}

}
    int numDecodings(string s) {
        	int *DP;
	DP = new int[s.size()];

	for (int i=0;i<s.size();i++)
		DP[i] = -1;

        return decode(s,0,DP);   
    }
};