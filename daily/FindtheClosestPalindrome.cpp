class Solution {
public:
    long halfToPalindrome(long left, bool even){
        long resnum = left;
        if(!(even)){
            left /= 10;
        }

        while(left>0){
            int digit = left % 10;
            resnum = (resnum * 10) + digit;
            left /= 10;
        }

        return resnum;
    }

    string nearestPalindromic(string n) {
        int len = n.size();
        int mid = len/2;
        long firsthalf = stol(n.substr(0,(len%2==0) ? mid : mid + 1));

        vector<long> possibleAns;
        possibleAns.push_back(halfToPalindrome(firsthalf,len%2==0));
        possibleAns.push_back(halfToPalindrome(firsthalf + 1,len%2==0));
        possibleAns.push_back(halfToPalindrome(firsthalf - 1,len%2==0));
        possibleAns.push_back((long)pow(10,len-1) - 1);
        possibleAns.push_back((long)pow(10,len) + 1);


        long diff = LONG_MAX;
        long res = 0;
        long realnum = stol(n);

        for(long &num : possibleAns){
            if(num == realnum) continue;
            if(abs(num - realnum) < diff){
                diff = abs(num - realnum);
                res = num;
            }else if(abs(num - realnum) == diff){
                res = min(res,num);
            }
        }

        return to_string(res);
    }
};
