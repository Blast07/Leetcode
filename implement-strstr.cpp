class Solution {
public:
    int strStr(string haystack, string needle){
	if (needle.size()==0)
		return 0;
	if(needle.size()>haystack.size())
		return -1;
	int i=0;
	while(i<haystack.size()){
		if (haystack[i]==needle[0]){
			int k=i+1;
			int j = 1;
			while(k<haystack.size() && j<needle.size()){
				if (haystack[k]!=needle[j])
					break;
				k++;
				j++;
			}
			if (j==needle.size())
				return i;
			if (k==haystack.size())
				return -1;

		}
		i++;
	}
      return -1; 
}

};