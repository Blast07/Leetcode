class Solution {
public:
int longestValidParentheses(string s) {
        stack <char> st;
        int longest = 0;
        for (auto ch:s){
            if (ch=='(')
                st.push(ch);
            else if(ch==')'){
                if (!st.empty() && st.top()=='('){
                    st.pop();
                    st.push('2');
                }else if(!st.empty() && st.top()=='2'){
					int count = 0;
					while(!st.empty() && st.top()=='2'){
						st.pop();
						count++;
					}
					if (!st.empty() && st.top()=='('){
						st.pop();
						count++;
						int i=0;
						while (i<count){
							st.push('2');
							i++;
						}
					}else if( (!st.empty() && st.top()==')') || st.empty()){
						int i=0;
						while(i<count){
							st.push('2');
							i++;
						}
						st.push(')');
					}

				}
                
            }
                
        }
		int count =0;
		while(!st.empty()){
			if (st.top()=='2'){
				count++;
			}else{
				if (count>longest)
					longest = count;
				count =0;	
			}

			st.pop();
		}
        if (count>longest)
            longest = count;
        return 2*longest;
}
};