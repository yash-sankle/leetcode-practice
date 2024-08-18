class Solution {
public:
    int nthUglyNumber(int n) {
      vector<int> v(n+1);

      int i2,i3,i5;
      i5=i2=i3=1;
      v[1]=1;

      for(int i=2;i<=n;i++){
        int i2ug = v[i2]*2;
        int i3ug = v[i3]*3;
        int i5ug = v[i5]*5;

        int minug = min({i2ug,i3ug,i5ug});

        v[i] = minug;

        if(minug == i2ug)
          i2++;
        if(minug == i3ug)
          i3++;
        if(minug == i5ug)
          i5++;
    }

      return v[n];
};
