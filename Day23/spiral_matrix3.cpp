
/*You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.
Return an array of coordinates representing the positions of the grid in the order you visited them.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        vector<vector<int>>ans;
        int count = rows * cols;
        vector<vector<int>> direction = {
            {0, 1} // East
            ,
            {1, 0} // South
            ,
            {0, -1} // West
            ,
            {-1, 0} // North
        };
        int steps = 0;
        int dir = 0;
        ans.push_back({rStart,cStart});
        while (ans.size() < count){
            if(dir==0 || dir==2) // 0 = east , 2 = West
                steps++;
            
            for(int i=0;i<steps;i++)
            {
                rStart += direction[dir][0];
                cStart += direction[dir][1];

                if(rStart >=0 && rStart < rows && cStart >=0 && cStart < cols  ){
                    // VAlid CEll
                    ans.push_back({rStart,cStart});     
                }
            }
                dir = (dir+1)%4;
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();