//1616

bool isPalindrome(string s, int l, int r){
	for (int i=l, j = r;i<j;i++,j--){
		if (s[i] != s[j])
			return false;
	}

	return true;
}

bool checkPalindromeFormation(string a, string b) {
	
	if (isPalindrome(a,0, a.size()-1) || isPalindrome(b, 0, b.size()-1))
		return true;

	if (a[0] != b.back() && a.back() != b[0])
		return false;

	int i=0, j = b.size()-1;
	for (; i<=j ; i++, j--){
		if (a[i] != b[j]){
			if (isPalindrome(a, i, j) || isPalindrome(b, i, j))
				return true;
			break;
		}	
	}
    
    if (i > j)
        return true;

	for (i=0, j = a.size()-1; i <=j; i++, j--){
		if (b[i] != a[j]){
			if (isPalindrome(a, i, j) || isPalindrome(b, i, j))
				return true;
			break;
		}
	}
    
	if (i > j)
        return true;
    return false;
}
