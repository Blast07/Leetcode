class Solution {
public:
string intToRoman(int num){
	vector <pair <int, string>> v;
	v.push_back({1,"I"});
	v.push_back({2,"II"});
	v.push_back({3,"III"});
	v.push_back({4,"IV"});
	v.push_back({5,"V"});
	v.push_back({6,"VI"});
	v.push_back({7,"VII"});
	v.push_back({8,"VIII"});
	v.push_back({9,"IX"});
	v.push_back({10,"X"});
	v.push_back({40,"XL"});
	v.push_back({50,"L"});
	v.push_back({90,"XC"});
	v.push_back({100,"C"});
	v.push_back({400,"CD"});
	v.push_back({500,"D"});
	v.push_back({900,"CM"});
	v.push_back({1000,"M"});
	
	string res = "";
	int i = v.size()-1;
	while(i>=0 && num){
		if (v[i].first <= num){
			res += v[i].second;
			num -= v[i].first;
		}else
			i--;
	}

	return res;


}

};