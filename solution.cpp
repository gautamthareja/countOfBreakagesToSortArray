#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

// To execute C++, please define "int main()"

int countOfBreakagesToSortArrayUtil(vector<int>& nums, int currentIndex, int rightElement) {
    if(currentIndex < 0) {
        return 0;
    }
    
    int currentElement = nums[currentIndex];
    
    if(currentElement <= rightElement) {
        return countOfBreakagesToSortArrayUtil(nums, currentIndex - 1, currentElement);
    }
    
    int numberOfDivisions = 1;
    float averageOfDivisions = currentElement;
    
    while(averageOfDivisions > rightElement) {
        numberOfDivisions++;
        averageOfDivisions = (float)currentElement / (float)numberOfDivisions;
    }
    
    
    return (numberOfDivisions - 1) + countOfBreakagesToSortArrayUtil(nums, currentIndex - 1, floor(averageOfDivisions));
    
}

int countOfBreakagesToSortArray(vector<int>& nums) {
    if(nums.size() <= 1) {
        return 0;
    }
    return countOfBreakagesToSortArrayUtil(nums, nums.size() - 2, nums.back());
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i = 0; i < n; i++) {
      cin >> nums[i];
  }
  cout << countOfBreakagesToSortArray(nums) << endl;
}
