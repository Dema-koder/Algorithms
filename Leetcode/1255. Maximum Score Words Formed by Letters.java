class Solution {
    private int f(String[] words, Map<Character, Integer>mp, int[] score, Map<Character, Integer>cur, int ind) {
        if (ind == words.length) {
            int ans = 0;
            for (char c: cur.keySet()) {
                ans += score[c - 'a'] * cur.get(c);
            }
            return ans;
        }
        int res = f(words, mp, score, cur, ind + 1);
        for (var c: words[ind].toCharArray()) 
            if (cur.containsKey(c))
                cur.put(c, cur.get(c) + 1);
            else 
                cur.put(c, 1);
        boolean b = true;
        for (var c: mp.keySet())
            if (cur.containsKey(c))
                if (cur.get(c) > mp.get(c))
                    b = false;
        for (var c: cur.keySet())
            if (cur.get(c) != 0)
                if (!mp.containsKey(c))
                    b = false;
        if (b) {
            res = Math.max(res, f(words, mp, score, cur, ind + 1));
        }
        for (var c: words[ind].toCharArray()) 
            cur.put(c, cur.get(c) - 1);
        return res;
    }

    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        Map<Character, Integer>mp = new HashMap<>();
        for (int i = 0; i < letters.length; i++) {
            if (mp.containsKey(letters[i]))
                mp.put(letters[i], mp.get(letters[i]) + 1);
            else
                mp.put(letters[i], 1);
        }
        return f(words, mp, score, new HashMap<>(), 0);
    }
}
