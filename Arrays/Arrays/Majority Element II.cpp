 vector<int> findMajority(vector<int>& arr) {
     int num=arr.size()/3;
     vector<int> res;
     map<int,int> m;
     
     for(auto i: arr){
         m[i]+=1;
     }
     for(auto i: m){
         if(i.second > num){
             res.push_back(i.first);
             
         }
     }
        return res;
    }
