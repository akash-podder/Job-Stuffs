class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int currentMaxCharFreq = 0;
        int maxLength = 0;
        unordered_map<char, int> Map;

        while(right<s.size()){
            Map[s[right]]++;

            // we are Finding out which is the "Max Freq" among the characters & the Freq value
            currentMaxCharFreq = max(currentMaxCharFreq, Map[s[right]]);

            // we are Finding Out how many "characters" that needs to be "changed"
            // Length - current Max Character Frequency
            // here, Lenght = right-left+1
            int numberOfCharOperationsNeeded = (right-left+1) - currentMaxCharFreq;
            
            // if number of operations is greater than "k" we go to Left until it's (number of operations<=k)
            while(numberOfCharOperationsNeeded>k) {
                numberOfCharOperationsNeeded--;
                Map[s[left]]--; // first we need to Decrease the Frequency of the "Left" Pointer character
                left++; // then, we move the Left Pointer to the Right
            }

            if(numberOfCharOperationsNeeded<=k){
                maxLength = max(maxLength, right-left+1);
            }

            right++;
        }

        return maxLength;
    }
};