//67

string addBits(char a, char b, char carry){
	string res = "00"; //res[0] == 'carry bit', res[1] == 'sum bit'
	if (a == '1' && b == '1'){
		res[0] = '1';
		if (carry == '1')
			res[1] = '1';
	}else if (a == '1' || b == '1'){
		if (carry == '1'){
			res[0] = '1';
		}else
			res[1] = '1';
	}else{
		if (carry == '1')
			res[1] = '1';
	}
	return res;
}

string addBinary(string a, string b) {
	string res = "";
	char carry = '0';	
    
    int i=a.size()-1, j=b.size()-1;
	for (;i>=0 && j>=0 ;i--,j--){
		string temp = addBits(a[i], b[j], carry);
		res.push_back(temp[1]);
		carry = temp[0];
	}

	while(i>=0){
		string temp = addBits(a[i],'0', carry);
		res.push_back(temp[1]);
		carry = temp[0];
		i--;
	}

	while(j>=0){
		string temp = addBits(b[j],'0', carry);
		res.push_back(temp[1]);
		carry = temp[0];
		j--;
	}

	if (carry == '1')
		res.push_back('1');

	reverse(res.begin(), res.end());

	return res;

	

}
