class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> mpp;

    RandomizedSet() {

    }

    bool insert(int val) {

        if(mpp.find(val) != mpp.end()) {
            return false;
        }

        nums.push_back(val);
        mpp[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {

        if(mpp.find(val) == mpp.end()) {
            return false;
        }

        int idx = mpp[val];
        int lastElement = nums.back();

        nums[idx] = lastElement;
        mpp[lastElement] = idx;

        nums.pop_back();
        mpp.erase(val);

        return true;
    }

    int getRandom() {

        int index = rand() % nums.size();
        return nums[index];
    }
};