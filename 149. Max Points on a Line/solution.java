import java.util.HashMap;

class Solution {
    public int maxPoints(int[][] points) {
        final int LENGTH = points.length;
        int max = 1;
        for (int i = 0; i < LENGTH; i++) {
            HashMap<Double, Integer> map = new HashMap<>();
            for (int j = i + 1; j < LENGTH; j++) {
                double k = Double.POSITIVE_INFINITY;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if (dx != 0) {
                    k = (double)dy/dx;
                }
                if (k == 0)
                    k = 0;
                if (map.containsKey(k)) {
                    map.put(k, map.get(k) + 1);
                } else {
                    map.put(k, 2);
                }
                max = Math.max(max, map.get(k));
            }
        }
        return max;
    }

}