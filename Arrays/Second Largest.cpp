int getSecondLargest(vector<int> &arr) {
  
        int l=-1000000, s=-1000000;
        for(int num:arr){
            if(num > l){s=l;l=num;}
            else if(num>s && num!=l){s=num;}
        }
        return (s==-1000000)?-1:s;
    }
