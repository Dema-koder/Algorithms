class Solution {
    private void f(int[] nums, List<Integer>cur, int ind, List<List<Integer>>ans) {
        if (ind == nums.length) {
            ans.add(new ArrayList<>(cur));
            return;
        }
        f(nums, cur, ind + 1, ans);
        cur.add(nums[ind]);
        f(nums, cur, ind + 1, ans);
        cur.remove(cur.size() - 1);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>>ans = new ArrayList<>();
        List<Integer>cur = new ArrayList<>();
        f(nums, cur, 0, ans);
        return ans;
    }
}
