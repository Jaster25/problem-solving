package pg60059;

class Solution {

    static int[][] extendedLock;
    static int keySize;
    static int lockSize;

    static int[][] rotate(int[][] key) {
        int[][] rotatedKey = new int[keySize][keySize];
        for (int i = 0; i < keySize; i++) {
            for (int j = 0; j < keySize; j++) {
                rotatedKey[j][keySize - i - 1] = key[i][j];
            }
        }

        return rotatedKey;
    }

    static int[][] combine(int[][] key, int startY, int startX) {
        int[][] combinedExtendedLock = new int[lockSize + keySize * 2][lockSize + keySize * 2];
        for (int i = 0; i < lockSize + keySize * 2; i++) {
            for (int j = 0; j < lockSize + keySize * 2; j++) {
                combinedExtendedLock[i][j] = extendedLock[i][j];
            }
        }

        for (int i = 0; i < keySize; i++) {
            for (int j = 0; j < keySize; j++) {
                combinedExtendedLock[i + startY][j + startX] += key[i][j];
            }
        }

        return combinedExtendedLock;
    }

    static boolean isRightKey(int[][] combinedExtendedLock) {
        for (int i = keySize; i < keySize + lockSize; i++) {
            for (int j = keySize; j < keySize + lockSize; j++) {
                if (combinedExtendedLock[i][j] != 1) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean solution(int[][] key, int[][] lock) {

        keySize = key.length;
        lockSize = lock.length;

        extendedLock = new int[lockSize + keySize * 2][lockSize + keySize * 2];
        for (int i = 0; i < lockSize; i++) {
            for (int j = 0; j < lockSize; j++) {
                extendedLock[i + keySize][j + keySize] = lock[i][j];
            }
        }

        int[][] rotatedKey = new int[keySize][keySize];
        for (int i = 0; i < keySize; i++) {
            for (int j = 0; j < keySize; j++) {
                rotatedKey[i][j] = key[i][j];
            }
        }

        for (int i = 0; i < 4; i++) {
            rotatedKey = rotate(rotatedKey);
            for (int startY = 0; startY < keySize + lockSize; startY++) {
                for (int startX = 0; startX < keySize + lockSize; startX++) {
                    int[][] combinedExtendedLock = combine(rotatedKey, startY, startX);
                    if (isRightKey(combinedExtendedLock)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}