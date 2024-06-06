class Solution {
    public boolean isPossibleDivide(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0)
            return false;
        Arrays.sort(hand);
        Map<Integer, Integer>mp = new HashMap<>();

        for (int i = 0; i < hand.length; i++) {
            if (mp.containsKey(hand[i]))
                mp.put(hand[i], mp.get(hand[i]) + 1);
            else 
                mp.put(hand[i], 1);
        }

        for (int i = 0; i < hand.length; i++)
            if (mp.get(hand[i]) != 0) {
                for (int j = hand[i]; j < hand[i] + groupSize; j++) {
                    if (!mp.containsKey(j))
                        return false;
                    if (mp.get(j) < 1) 
                        return false;
                    mp.put(j, mp.get(j) - 1);
                }
            }
        return true;
    }
}
