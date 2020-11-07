//1461
//The number of distinct sub-strings should be exactly 2^k.
bool hasAllCodes(string s, int k) {
    if (s.size() < k)
        return false;
    unordered_set <string> codes;
    for (int i=0;i<= s.size()-k;i++){
        string code = s.substr(i,k);
        codes.insert(code);
    }
    return codes.size() == (1<<k);
}
