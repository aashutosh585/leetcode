class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenDigitsCnt = 0;

        int sizeOfNums = nums.size();
        for(int num = 0;num<sizeOfNums;num+=1){
            int numberOfDigits = log10(nums[num]) + 1;
            if(!(numberOfDigits&1)) evenDigitsCnt+=1;
        }
        return evenDigitsCnt;
    }
};