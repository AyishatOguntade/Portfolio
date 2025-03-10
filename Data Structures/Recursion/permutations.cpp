#include<iostream> 
#include<vector>

void print(std::vector<int>& vec) {
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void permutations(std::vector<int>nums, int start){
    // if there is only one thing in the vector ??  
    if(start == nums.size()- 1){
        print(nums);
    }
    for (int i = start; i < nums.size(); ++i) {
        std::swap(nums[start], nums[i]);   
        permutations(nums, start + 1);// mth 180 notes 
        std::swap(nums[start], nums[i]); // put it back  
    }

}
int main(int argc, char*argv[]){
    int n = std::stoi(argv[1]);
    std::vector<int> nums;
    for(int i =1; i <= n; i++){
        nums.push_back(i);
    }
    int start = 0;
    permutations(nums,start);

    return 0;
} 

