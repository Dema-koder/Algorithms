class Solution {

    public long maximumValueSum(int[] a, int k, int[][] edges) {
        long ans = 0;
        for (int x: a)
            ans += x;
        
        long kol = 0, minAbs = Long.MAX_VALUE;
        for (int to: a) {
            long dif = (to ^ k) - to;
            if (dif > 0) {
                ans += dif;
                kol += 1;
            } 
            minAbs = Math.min(minAbs, Math.abs(dif));
        }
        if (kol % 2 == 1) 
            ans -= minAbs;
        return ans;
    }
}
