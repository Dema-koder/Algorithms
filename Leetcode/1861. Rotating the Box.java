class Solution {
    public char[][] rotateTheBox(char[][] box) {
        char[][] ans = new char[box[0].length][box.length];
        for (int i = 0; i < box.length; i++)
            for (int j = 0; j < box[0].length; j++) {
                ans[j][i] = box[box.length - i - 1][j];
            }
        for (int i = 0; i < ans[0].length; i++) {
            int cnt = 0, ind = ans.length;
            for (int j = 0; j < ans.length; j++)
                if (ans[j][i] == '*') {
                    for (int l = j - cnt; l < j; l++)
                        ans[l][i] = '#';
                    cnt = 0; 
                } else 
                    if (ans[j][i] == '#') {
                        cnt += 1;
                        ans[j][i] = '.';
                    }
            for (int j = ind - cnt; j < ind; j++)
                ans[j][i] = '#';
        }
        return ans;
    }
}
