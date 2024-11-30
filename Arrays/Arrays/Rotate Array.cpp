    void rotateArr(vector<int>& arr, int d) {
        d=d%arr.size();
        int temp[d];
        int j;
        for(int i=0;i<d;i++){temp[i]=arr[i];}
        for( j=0;j<arr.size()-d;j++){arr[j]=arr[j+d];}
        for(int k=0;k<d;k++){arr[j+k]=temp[k];}
    }
