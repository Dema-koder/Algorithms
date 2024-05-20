class Solution {

    private int f(int[][] grid, int x, int y, boolean[][] mp, int dx[], int dy[]) {
        mp[x][y] = true;
        int res = 0;
        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx >= 0 && newx < grid.length && newy >= 0 && newy < grid[0].length)
                if (grid[newx][newy] != 0 && !mp[newx][newy])
                    res = Math.max(res, f(grid, newx, newy, mp, dx, dy) + grid[x][y]);
        }
        mp[x][y] = false;
        return (res == 0 ? grid[x][y] : res);
    }

    private int kol(int x, int y, int[][] grid, int[] dx, int[] dy) {
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx >= 0 && newx < grid.length && newy >= 0 && newy < grid[0].length)
                if (grid[newx][newy] != 0)
                    ans++;
        }
        return ans;
    }

    public int getMaximumGold(int[][] grid) {
        int ans = 0;
        int[] dx = new int[]{-1, 0, 1, 0};
        int[] dy = new int[]{0, 1, 0, -1};
        boolean map[][] = new boolean[15][15];
        for (int i = 0; i < grid.length; i++)
            for (int j = 0; j < grid[0].length; j++)
                if (grid[i][j] != 0 && kol(i, j, grid, dx, dy) < 3) {
                    ans = Math.max(ans, f(grid, i, j, map, dx, dy));
                }
        return ans;
    }
}
