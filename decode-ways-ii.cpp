//639

const int M = 1000000007;

int f(string &s, int i, vector <int> &mem){
	if (i == s.size())
		return 1;
    else if (mem[i] != -1)
        return mem[i];
	else{
		int single_ch = 0;
		int double_ch = 0;

        if (s[i] == '0'){
			return mem[i] = 0;
		}
		else if (s[i] == '*'){
			single_ch = ((long long)9*(f(s, i+1, mem)%M))%M;

			if (i + 1 <s.size()){
                int count = 0;
                if (s[i+1] == '*' )
                    count = 15;
                else{
                    int val = 10*1 + (s[i+1] - '0');
                    if (val <= 26)
                        count++;

                    if (val + 10 <=26)
                        count++;

                }
                double_ch = ((long long)count*(f(s, i+2, mem)%M))%M;
                    
               
			}

		}
		else{

        	single_ch = (long long)f(s,i+1, mem) %M;
        	if (i+1 < s.size()){
				if (s[i+1] != '*'){
        	    	int val = 10*(s[i] - '0') + (s[i+1] - '0');
        	    	if (val <= 26){
        	       		double_ch = f(s,i+2, mem);
        	    	}
				}else{
					int val = 10*(s[i] - '0') + 1;
					int count = 0;
					while(val<=26 && count < 9){
						count++;
						val ++;
					}

					double_ch = ((long long)count*(f(s, i+2, mem)%M))%M;
					
				}
        	}
		}
        mem[i] = ((long long)single_ch + double_ch)%M;
        return mem[i];
        
        
	}
	
}

int numDecodings(string s) {
    vector <int> mem(s.size(), -1);
    return f(s, 0, mem);
}
