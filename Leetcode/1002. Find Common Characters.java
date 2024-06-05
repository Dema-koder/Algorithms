class Solution {
    public List<String> commonChars(String[] words) {
        int[] arr = new int[26];
        Arrays.fill(arr, 100000);
        for (int i = 0; i < words.length; i++) {
            int[] tmp = new int[26];
            for (int j = 0; j < words[i].length(); j++)
                tmp[(int)words[i].charAt(j) - 'a']++;
            
            for (int j = 0; j < 26; j++)
                arr[j] = Math.min(arr[j], tmp[j]);
        }
        List<String>ans = new ArrayList<>();
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < arr[i]; j++)
                ans.add(String.valueOf((char)('a' + i)));
        return ans;
    }
}
