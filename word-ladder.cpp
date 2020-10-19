class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map <string, int> words;
        for (int i=0;i<wordList.size();i++){
            words[wordList[i]] = -1;//not visited
        }
        int n = beginWord.size();
        queue <string> q;
        q.push(beginWord);
        while(!q.empty()){
            string front = q.front(); q.pop();
            if (front == endWord)
                return words[front];
            
            string temp = front;
            for (int i=0;i<n;i++){
                char ch = temp[i];
                for (int j=0;j<26;j++){
                    temp[i] = 'a'+j;
                    if (words.find(temp)!=words.end()){
                        if(words[temp]==-1){
                            q.push(temp);
                            if (front!=beginWord)
                                words[temp] = words[front]+1;
                            else words[temp] = 2;
                        }
                    }
                 
                }
                temp[i] = ch;
                
            }
        }
        
        return 0;
    }
};