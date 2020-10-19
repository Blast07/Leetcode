class Solution {
public:
    bool circularArrayLoop(vector<int>& arr) {
       for (int i=0;i<arr.size();i++){
           int trip = 1000*(i+1);
           if (arr[i]>1000)
               continue;
           else{
               int cur = i;
               bool forward = (arr[cur]>0);
               if (forward){
                  while(1){
                      if (arr[cur]>1000 && arr[cur]<1000*(i+1))
                          break;
                      else if(arr[cur]>1000*(i+1)){
                          if(trip-arr[cur]>=1)
                              return true;
                          break;
                      }else if(arr[cur]<0){
                          break;
                      }
                      else{
                          int temp = arr[cur]%arr.size();
                          arr[cur] = ++trip;
                          if (cur+temp<arr.size())
                              cur = cur+temp;
                          else
                              cur = cur+temp - arr.size();
                      }
                  } 
               }else{
                   while(1){
                       if (arr[cur]>1000 && arr[cur]<1000*(i+1))
                           break;
                       else if(arr[cur]>1000*(i+1)){
                           if(trip - arr[cur]>=1)
                               return true;
                           break;
                       }else if(arr[cur]>0){
                           break;
                       }
                       else{
                          cout<<"i"<<cur<<endl; 
                           int temp = -((-arr[cur])%arr.size());
                          cout<<"t"<<temp<<endl; 
                           arr[cur] = ++trip;
                             
                           if(cur+temp>=0)
                               cur = cur+temp;
                           else
                               cur = arr.size() + (cur+temp);
                          cout<<cur<<endl; 
                           
                       }
                   }
                   
                   
               }
           }
       } 
       return false;
    }
};