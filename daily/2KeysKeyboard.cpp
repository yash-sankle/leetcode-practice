class Solution {
public:
    bool prime(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0)
            return false;
        }
        return true;
    }

    int minSteps(int n) {
        if(n==1)
        return 0;
        if(n==2)
        return 2;
        if(n%2!=0)
        {
            if(prime(n))
            return n;
        }
    
        vector<int> v(n+1,0);
        v[0]=0;
        v[1]=0;
        v[2]=2;

        for(int i=3;i<=n;i++){
            int factor = i/2;
            while(factor>=1){
                if(i%factor == 0){
                    v[i] = v[factor] + 1 + (i/factor) - 1;
                    break;
                }
                else{
                    factor--;
                }
            }
        }

        return v[n];
    }
};
