class Solution {
    boolean check(char x) {
        return x == ' ' || x == ',' || x == '.' || x == '?' || x == ';' || x == '!' || x == '\'';
    }
    
    public String mostCommonWord(String paragraph, String[] banned) {
        List<String>words = new ArrayList<>();
        String cur = "";
        paragraph += " ";
        for (int i = 0; i < paragraph.length(); i++) {
            if (check(paragraph.charAt(i))) {
                if (cur.length() != 0) words.add(cur.toLowerCase());
                cur = "";
            } else {
                cur += paragraph.charAt(i);
            }
        }
        Map<String, Integer>mp = new HashMap<>();
        for (int i = 0; i < words.size(); i++) {
            mp.putIfAbsent(words.get(i), 1);
            mp.put(words.get(i), mp.get(words.get(i)) + 1);
        }
        for (var str: banned)
            if (mp.containsKey(str))
                mp.remove(str);
        String ans = "";
        int kol = 0;
        for (var key: mp.keySet())
            if (kol < mp.get(key)) {
                kol = mp.get(key);
                ans = key;
            }
        return ans;
    }
}
