    void reverseArray(vector<int> &arr) {
        int l=arr.size() - 1;
        int f=0;
        int temp;
        while(f<l){
            temp=arr[f];
            arr[f]=arr[l];
            arr[l]=temp;
            f++;
            l--;
        }   
    }
