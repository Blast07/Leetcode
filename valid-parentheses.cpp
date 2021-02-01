//20

bool isValid(string s){
	string st;
	for (char ch in s){
		if (ch == '(' || ch=='{' || ch=='[')
			st.push_back(ch);
		else if (ch == ')'){
			if (st.back() == '('){
				st.pop_back();
			}else
				return false;
		}
		else if (ch == '}'){
			if (st.back() == '{'){
				st.pop_back();
			}else
				return false;
		}
		else if (ch == ']'){
			if (st.back() == '['){
				st.pop_back();
			}else
				return false;
		}
	}

	return st.empty();
}

