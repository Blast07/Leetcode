class Solution {
public:
    int maxWidthRamp(std::vector <int> &A){
 int first_pos[50001]={0};// first_pos[i] is the first pos where i appears 
        int lowest_pos_before[50001]={0}; // ith index shows the value of lowest index for elements<= i 
        
        for(int i=0;i<A.size();i++){
            if(!first_pos[A[i]])
                first_pos[A[i]]=i+1;//using 1 based indexing
            
        }
        int mn=INT_MAX;
        int ans=0;
        
        for(int i=0;i<=50000;i++) { 
			if(first_pos[i]){
				mn=min(mn,first_pos[i]);
				lowest_pos_before[i]=min(mn,first_pos[i]);
            }
        }       
        
        for(int i=0;i<A.size();i++){
            ans=max(ans,i+1-lowest_pos_before[A[i]]);
        }
        
        return ans;
}


};