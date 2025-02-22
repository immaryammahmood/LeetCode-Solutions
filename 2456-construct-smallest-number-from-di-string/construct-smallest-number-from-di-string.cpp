class Solution {
public:
    string smallestNumber(string pattern) {
        return to_string(findSmallestNumber(pattern, 0, 0, 0));
    }

private:
    // Recursively find the smallest number that satisfies the pattern
    int findSmallestNumber(string pattern, int currentPosition,
                           int usedDigitsMask, int currentNum) {
        // Base case: return the current number when the whole pattern is
        // processed
        if (currentPosition > pattern.size()) return currentNum;

        int result = INT_MAX;
        int lastDigit = currentNum % 10;
        bool shouldIncrement =
            currentPosition == 0 || pattern[currentPosition - 1] == 'I';

        // Try all possible digits (1 to 9) that are not yet used and follow the
        // pattern
        for (int currentDigit = 1; currentDigit <= 9; ++currentDigit) {
            if ((usedDigitsMask & 1 << currentDigit) == 0 &&
                currentDigit > lastDigit == shouldIncrement)
                result = min(result, findSmallestNumber(
                                         pattern, currentPosition + 1,
                                         usedDigitsMask | 1 << currentDigit,
                                         currentNum * 10 + currentDigit));
        }

        return result;
    }
};