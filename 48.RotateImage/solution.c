//
// Created by maxim on 24.02.2022.
//

void mirrorMainDiag(int** matrix, const int matrixSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < i; ++j) {
            if (i!=j) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
}
void mirrorColumn(int** matrix, const int matrixSize) {
    for (int i = 0; i < matrixSize / 2; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            int tmp = matrix[j][matrixSize - 1 - i];
            matrix[j][matrixSize - 1 - i] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    mirrorMainDiag(matrix, matrixSize);
    mirrorColumn(matrix, matrixSize);
}