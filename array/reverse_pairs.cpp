class Solution {
public:
    int merge(vector<int>& arr, int low, int mid, int high) {

        int count = 0;

        int j = mid + 1;
        for(int i = low; i <= mid; i++){
            while(j <= high && (long long)arr[i] > 2LL * arr[j]){
                j++;
            }
            count += (j - (mid + 1));
        }

        vector<int> answer;
        int i = low;
        j = mid + 1;

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                answer.push_back(arr[i]);
                i++;
            } else {
                answer.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) {
            answer.push_back(arr[i]);
            i++;
        }

        while (j <= high) {
            answer.push_back(arr[j]);
            j++;
        }

        for (int k = low; k <= high; k++) {
            arr[k] = answer[k - low];
        }

        return count;
    }

    int merge_sort(vector<int>& arr, int low, int high) {
        if (low >= high) {
            return 0;
        }

        int mid = (low + high) / 2;

        int a = merge_sort(arr, low, mid);
        int b = merge_sort(arr, mid + 1, high);
        int c = merge(arr, low, mid, high);

        return a + b + c;
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() - 1); 
    }
};

