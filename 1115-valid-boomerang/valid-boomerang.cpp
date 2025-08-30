class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];

        // Area of triangle method to check collinearity
        //determinant formula of triangle 
        //    |x1 y1 1|
        //1/2 |x2 y2 1|
        //    |x3 y3 1|
        //If the three points are collinear (lie on the same straight line), the “triangle” they form has zero area.
        //If they form a real triangle, the area is non-zero.
        float area = abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;

        return (area == 0) ? false : true;
    }
};



//sala code sai jadya too explanation da diya maine\U0001f602\U0001f602