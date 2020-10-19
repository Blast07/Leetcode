class Solution {
public:
 vector<double> sampleStats(vector<int>& count) {
        vector<double> res;
        long int n=0;
        int mn = 256;
        int mx = 0;
        long int sum = 0;
        pair <long int,long int> mode(0,0); //first = number, second = count
        
        for(int i=0;i<count.size();i++){
            sum += count[i]*i;
            n += count[i];
            if (count[i]){
                mn = min(mn, i);
                mx = max(mx, i);
                if (mode.second < count[i]){
                    mode.first = i;
                    mode.second = count[i];
                }
            }
        }
		long int mid = ceil(n/2);
		double median =0;
		if(n%2!=0){ //odd
			long int c =0;
			for (int i=0;i<count.size();i++){
				if (c+count[i]>=mid){
					median = i;
					break;
				}else
					c += count[i];
			
			}
		}else{
			long int c =0;
			bool flag = false;
			for (int i=0;i<count.size();i++){
				if (c+count[i]>=mid && flag == false){
					flag = true;
					median += i;
					if (c+count[i]>=mid+1){
						median = i; break;
					}
					c += count[i];
					mid++;
				}else if(flag == true && c+count[i] >=mid ){
					median += i;
					median = double(median)/double(2);
					break;

				}else
					c += count[i];
			
			}
		}

        //minimum, maximum, mean, median, and mode of the sample
		res.push_back(mn); res.push_back(mx); res.push_back(double(sum)/double(n)); res.push_back(median);res.push_back(mode.first);
		return res;
        
    }

};