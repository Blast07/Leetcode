class Solution {
public:
    int mem[1000][1000];
    int visited[1000][1000];
    
    bool palindrome(string &s, int start, int end){
        if (start > end)
            return false;
        else if(start+1 ==end){
            if(s[start]==s[end]){
                mem[start][end] = 1;
                return true;
            }else{
                mem[start][end] = 0;
                return false;
                }
        }
            
        else if(mem[start][end]!=-1)
            return mem[start][end];
        else if(start==end){
             mem[start][end] = 1;
             return true;
        }
        else{
            if (s[start]!=s[end]){
                mem[start][end] = 0;
                return false;
            }
            else {
                if (palindrome(s,start+1,end-1)){
                    mem[start][end] = 1;
                    return true;
                }
                mem[start][end] = 0; 
                return false;
            }
        }        
    }
    int countSubstrings(string &s, int start, int end){
        if(start>end)
            return 0;
        else if(visited[start][end])
            return 0;
        else{
            int count = 0;
            if(palindrome(s,start,end))
                count++;
            count += countSubstrings(s,start+1,end-1);
            count += countSubstrings(s,start,end-1);
            count += countSubstrings(s,start+1,end);
            visited[start][end] = 1; 
            return count;
        }
    }
    int countSubstrings(string s) {
        for (int i=0;i<1000;i++){
            for (int j=0;j<1000;j++){
                mem[i][j] =-1;
                visited[i][j]=0;
            }
                
        }
        return countSubstrings(s,0,s.size()-1);
    }
};