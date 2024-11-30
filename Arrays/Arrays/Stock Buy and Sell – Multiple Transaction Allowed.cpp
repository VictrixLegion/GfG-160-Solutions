 int maximumProfit(vector<int> &prices) {
        int p = 0, b=prices[0], l=prices[0];
        for(int i=1; i < prices.size(); i++){
            if (prices[i]<l){
                p += l-b;
                b = l = prices[i];
            }else{
                l = prices[i];
            }
            //profit += l-b;
        }
        p += l-b;
        return p;

    }
