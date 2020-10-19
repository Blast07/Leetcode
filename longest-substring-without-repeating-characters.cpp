class Solution {
public:

    

int lengthOfLongestSubstring(string s){
	if (s.size()==0)
		return 0;
    else if(s.size()==1)
        return 1;
	else{
		int map[128]={0};
		int count =0;
		int max_count=0;
		int i=0;
		while(i<s.size()){
                
			if (map[s[i]]==0){
				map[s[i]] = i+1;
				count++;
			}else{
				if(count>max_count)
					max_count = count;
				int j  = map[s[i]];
				int temp = j;
				while(temp>0){
					if (map[s[temp-1]]<j)
						map[s[temp-1]] = 0;
					temp--;
				}
				map[s[i]] =i+1;
				count = i-j+1;
			}
			
		i++;
        }
        if (count>max_count)
            max_count = count;
		return max_count;
	}
}



};