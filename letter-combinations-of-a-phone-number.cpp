class Solution {
public:
    vector <string> num2str;
    vector <string> res;
    Solution(){
        num2str.push_back("");   //0
        num2str.push_back("");   //1
        num2str.push_back("abc");//2
        num2str.push_back("def");//3
        num2str.push_back("ghi");//4
        num2str.push_back("jkl");//5
        num2str.push_back("mno");//6
        num2str.push_back("pqrs");//7
        num2str.push_back("tuv");//8
        num2str.push_back("wxyz");//9
    }
    
    void generateCombinations(string &digits, int i, string str){
        if(i==digits.size())
            res.push_back(str);
        else{
            for (auto ch:num2str[digits[i]-'0']){
                generateCombinations(digits,i+1,str+ch);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) 
            return vector <string>();
        res.clear();
        generateCombinations(digits,0,"");
        return res;
    }
};