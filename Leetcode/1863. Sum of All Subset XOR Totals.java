class Solution {

    private int f(int[] a, int xor, int ind) {
        if (ind == a.length) return xor;
        return f(a, xor ^ a[ind], ind + 1) + f(a, xor, ind + 1);
    }

    public int subsetXORSum(int[] nums) {
        return f(nums, 0, 0);
    }
}
