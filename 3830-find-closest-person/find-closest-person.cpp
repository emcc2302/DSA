// class Solution {
// public:
//     int findClosest(int x, int y, int z) {
//         if(abs((z-x))<abs((z-y))) return 1;
//         else if(abs((z-x))>abs((z-y))) return 2;
//         else return 0;
//     }
// };


//using ternary operator 

class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(z - x) < abs(z - y) ? 1 : (abs(z - x) > abs(z - y) ? 2 : 0);
    }
};
