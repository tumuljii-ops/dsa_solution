class Solution {
  public:
    int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> answer;
        int i = low;
        int j = mid + 1;
        int count = 0;

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                answer.push_back(arr[i]);
                i++;
            }
            else {
                count = count + (mid - i + 1);
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

    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int ans = merge_sort(arr, 0, n - 1);
        return ans;
    }
};