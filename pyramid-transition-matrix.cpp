class Solution {
public:
bool pyramidTransition(int cur,string &curLevel, string &nextLevel,unordered_set <string> &allowedSet,
					   string &letters){
	if(curLevel.size()==1)
		return true;
	else{
		for (char ch:letters){
			string triplet = "";
			//string triplet = curLevel[cur] + ch + curLevel[cur+1];
			triplet += curLevel[cur];
			triplet += curLevel[cur+1];
			triplet += ch;
            
			if (allowedSet.find(triplet)!= allowedSet.end()){ //valid triplet
				if (cur+1 == curLevel.size()-1){
					//last element
					string newCur = nextLevel+ch;
					string newNext = "";

					if (pyramidTransition(0,newCur,newNext,allowedSet, letters)){
						return true;
					}

				}else{
					//if not last element
					nextLevel += ch;
					if (pyramidTransition(cur+1, curLevel, nextLevel,allowedSet,letters)){
						return true;
					}else{
						nextLevel.pop_back();
					
					}
				}


			}
		}	
		return false;

	}

}

bool pyramidTransition(string bottom, vector <string> &allowed){
	unordered_set <string> allowedSet;
	for (string str:allowed){
		allowedSet.insert(str);
	}
	string letters = "ABCDEFG";
	string nextLevel = "";
	return pyramidTransition(0,bottom, nextLevel,allowedSet, letters);
}




};