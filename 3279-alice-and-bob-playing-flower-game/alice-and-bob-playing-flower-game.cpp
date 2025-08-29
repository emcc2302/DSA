// class Solution {
// public:
//     long long flowerGame(int n, int m) {
//         return 1LL * n * m / 2;
//     }
// };



class Solution {
public:
    long long flowerGame(int n, int m) {
        long e1,o1,e2,o2=0;
        long ans=0;

        if(n%2==0){
            e1=n/2,o1=n/2;
        }
        else{
            e1=n/2,o1=(n/2 +1);
        }

        if(m%2==0){
            e2=m/2,o2=m/2;
        }
        else{
            e2=m/2,o2=(m/2 +1);
        }

        ans+=1L*e1*o2+e2*o1;
        return ans;
    }
};