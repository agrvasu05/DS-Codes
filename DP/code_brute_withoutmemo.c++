class Solution {
public:
    
    bool ispossible(int i, int j, int h, vector<vector<int>>& dungeon) {

        if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
            if (h + dungeon[i][j] > 0)
                return true;
            else
                return false;
        }
         if (i >= dungeon.size() || j >= dungeon[0].size()) {
            return false;
        }
        h=h+dungeon[i][j];

        if(h<=0) return false;


        bool take = ispossible(i + 1, j, h , dungeon);
        bool take2 = ispossible(i, j + 1, h , dungeon);
        return take || take2;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int left = 1;
        int right = 4 * (1e7);
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (ispossible(0, 0, mid, dungeon)) {
                right = mid - 1;
                ans = mid;

            } else {

                left = mid + 1;
            }
        }
        return ans;
    }
};
