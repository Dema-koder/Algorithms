class Solution {

    private boolean isPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l) != s.charAt(r))
                return false;
            l++; r--;
        }
        return true;
    }

    private void f(List<List<String>>ans, String s, String cur, int ind, List<String>res) {
        if (ind == s.length()) {
            if (cur == "")
                ans.add(new ArrayList<>(res));
            return;
        }
        cur += s.charAt(ind);
        f(ans, s, cur, ind + 1, res);
        if (isPalindrome(cur)) {
            res.add(cur);
            f(ans, s, "", ind + 1, res);
            res.remove(res.size() - 1);
        } 
    }

    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        f(ans, s, "", 0, new ArrayList<>());
        return ans;
    }
}
