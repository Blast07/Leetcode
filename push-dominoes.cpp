class Solution {
public:
string pushDominoes(string dominoes){
	
	int i=0;
	while(i<dominoes.size()){
		if (dominoes[i] == 'L'){
			int x = i-1;
			while(x>=0 && (dominoes[x]=='.')){
				dominoes[x] = 'L';
				x--;
			}
			//increment i pending
		//	i++;
		}else if(dominoes[i] == 'R'){
			int x = i;	
			i++;

			while(i<dominoes.size() && dominoes[i]=='.'){
				dominoes[i] = 'R';
				i++;
			}
			if(i == dominoes.size())
				break;
			if(dominoes[i] == 'R')
				continue;
			if(dominoes[i] == 'L'){
				int mid = (x+i)/2;
				int j=i-1;
				while(j>mid){
					dominoes[j] = 'L';
					j--;
				}
				if ((x-i-1)%2!=0){ //odd betwwen R L
					dominoes[mid] = '.';
				
				}
			
			}
		}
		i++;

	}
	
	return dominoes;

}

};