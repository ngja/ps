// 정답 = ans
// 시그마 times : ans / time 의 결과가 n 이 되는 ans 가 정답
// 시간 복잡도 심사관 100,000 * log 
// 입국 심사를 기다리는 사람 1,000,000,000명
// 심사관 1명, 걸리는 시간 1,000,000,000분 -> 걸리는 시간 1,000,000,000,000,000,000
class Solution {

    public long solution(int n, int[] times) {
        long answer = 0;

        long low = 0L;
        long high = 1_000_000_000_000_000_001L;

        while (low < high) {
            long temp = low + (high - low) / 2;
            long tempAns = getPassPersonCount(times, temp);

            // 더 많거나 같은 처리량, 더 줄일 수 있는지 확인 필요
            if (tempAns >= n) {
                high = temp;
                answer = temp;
            } else if (tempAns <= n) { // 더 늘려야한다
                low = temp + 1;
            }
        }

        return answer;
    }

    private long getPassPersonCount(int[] times, long totalCount) {
        long result = 0L;
        for (int time : times) {
            result += (totalCount) / time;
        }
        return result;
    }
}