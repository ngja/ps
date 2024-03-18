import java.util.HashMap;
import java.util.Map;

public class Solution {
    private final Map<String, Integer> giftMap = new HashMap<>();
    private final Map<String, Integer> giftIndexMap = new HashMap<>();
    private final Map<String, Integer> receivedCount = new HashMap<>();

    public int solution(String[] friends, String[] gifts) {
        int answer = 0;

        for (String gift : gifts) {
            Integer givingCount = giftMap.getOrDefault(gift, 0);
            giftMap.put(gift, givingCount + 1);
            String[] split = gift.split(" ");
            String giver = split[0];
            String receiver = split[1];
            Integer plusGiftIndex = giftIndexMap.getOrDefault(giver, 0);
            giftIndexMap.put(giver, plusGiftIndex + 1);
            Integer minusGiftIndex = giftIndexMap.getOrDefault(receiver, 0);
            giftIndexMap.put(receiver, minusGiftIndex - 1);
        }


        for (int i = 0; i < friends.length; i++) {
            for (int j = i + 1; j < friends.length; j++) {
                String a = friends[i];
                String b = friends[j];

                Integer aToB = giftMap.getOrDefault(getGiftMapKey(a, b), 0);
                Integer bToA = giftMap.getOrDefault(getGiftMapKey(b, a), 0);

                if (aToB > bToA) {
                    addNextMonthReceivedCount(a);
                } else if (aToB < bToA) {
                    addNextMonthReceivedCount(b);
                } else {
                    Integer aGiftIndex = giftIndexMap.getOrDefault(a, 0);
                    Integer bGiftIndex = giftIndexMap.getOrDefault(b, 0);

                    if (aGiftIndex > bGiftIndex) {
                        addNextMonthReceivedCount(a);
                    } else if (aGiftIndex < bGiftIndex) {
                        addNextMonthReceivedCount(b);
                    }
                }
            }
        }

        for (Integer value : receivedCount.values()) {
            if (answer < value) {
                answer = value;
            }
        }

        return answer;
    }

    private void addNextMonthReceivedCount(String name) {
        Integer count = this.receivedCount.getOrDefault(name, 0);
        receivedCount.put(name, count + 1);
    }

    private String getGiftMapKey(String giver, String receiver) {
        return giver + " " + receiver;
    }
}
