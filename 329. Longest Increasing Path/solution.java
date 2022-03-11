class Solution {
    private enum States {
        UPPER(0, -1),
        LOWER(0, 1),
        LEFT(-1, 0),
        RIGHT(1, 0);
        private int x;
        private int y;

        States(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }

    public int longestIncreasingPath(int[][] matrix) {
        int[][] distances = new int[matrix.length][matrix[0].length];
        int max = 1;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                int tmp = dfs(matrix, i, j, distances);
                max = Math.max(tmp, max);
            }
        }
        return max;
    }

    int dfs(int[][] matrix, int i, int j, int[][] distances) {
        if (distances[i][j] > 0) {
            return distances[i][j];
        }
        int max = 1;
        for (States value : States.values()) {
            int current_i = i + value.getX();
            int current_j = j + value.getY();
            if (current_i >= 0 && current_j >= 0
                && current_i < matrix.length && current_j < matrix[0].length
                && matrix[i][j] < matrix[current_i][current_j]) {
                int tmpLength = 1 + dfs(matrix, current_i, current_j, distances);
                max = Math.max(tmpLength, max);
            }
        }
        distances[i][j] = max;
        return max;
    }
}