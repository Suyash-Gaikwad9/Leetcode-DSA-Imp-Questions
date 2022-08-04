class Solution {
public:
    long long int binarySer(int n){
        int start =0;
        int end = n;
        long long int mid = start+ (end-start)/2;
        long long int ans = -1;
        while(start<=end){
            long long  int sqr = mid*mid;
            
            if(sqr==n){
                return mid;
            }
            if(sqr<n){
                ans = mid;
                start = mid+1;
                
            }
            else{
                end = mid-1;
            }
            mid = start+ (end-start)/2;
        }
        return ans;
    }
    
    int mySqrt(int x) {
        return binarySer(x);
    }
};