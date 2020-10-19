class Solution {
public:
    string timeToString(int h,int s){
	string res=to_string(h) 
			   + ":" 
			   + ((s>9) ? to_string(s): "0"+to_string(s));
    
	return res;

}

void getAllTimes(int i,int bits,int h,int s, vector <string> &res){
	if (bits==0){
		res.push_back(timeToString(h,s));
	}else{
		if (i<4){
			//hour bit
			//2 options set this bit not set this bit
			
			int newh = pow(2,i) + h; 
			if(newh <12)
				getAllTimes(i+1,bits-1,newh,s,res);//setting this bit

			getAllTimes(i+1,bits,h,s,res); //not setting this bit

		}else{
			//second bit
			int news = pow(2,i-4) + s;
			if (news < 60){
				getAllTimes(i+1,bits-1,h,news,res);
				getAllTimes(i+1,bits,h,s,res);
			}
		
		}	
	}
}

vector <string> readBinaryWatch(int num){
	vector <string> res;

	getAllTimes(0,num,0,0,res); //(ithBit,bitsleft, hour, second,res);
	
	return res;
}

};