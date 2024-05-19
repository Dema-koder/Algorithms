class Solution {
    Map<Integer, String>dp = new HashMap<>();
    List<String>a = new ArrayList<>();

    private boolean f(String str) {
        Set<Character> map = new HashSet<>();
        boolean b = true;
        for (int i = 0; i < str.length(); i++) {
            char chr = str.charAt(i);
            if (map.contains(chr))
                b = false;
            else 
                map.add(chr);
        }
        return b;
    }

    void f(String cur, int mask, int ind) {
        if (dp.containsKey(mask))
            return;
        dp.put(mask, cur);
        for (int i = ind + 1; i < a.size(); i++)
            if ((mask & (1 << i)) == 0) {
                String tmp = cur + a.get(i);
                if (f(tmp))
                    f(tmp, mask + (1 << i), i);
            }
    }

    public int maxLength(List<String> arr) {
        for (var str: arr) {
            if (f(str))
                a.add(str);
        }
        f("", 0, -1);
        int ans = 0;
        for (var key: dp.keySet())
            ans = Math.max(ans, dp.get(key).length());
        return ans;
    }
}
