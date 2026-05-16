class Solution {
public:

    // This function checks:
    // "Can we allocate books to k students
    // such that maximum pages assigned
    // to a student is at most mid ?"

    bool possible(vector<int>& arr, int k, int mid) {

        // Start with first student
        int student = 1;

        // Current pages assigned to current student
        int pages = 0;

        for (int i = 0; i < arr.size(); i++) {

            // If a single book itself has more pages than mid
            // then allocation is impossible
            if (arr[i] > mid) {
                return false;
            }

            // If adding current book exceeds limit
            if (pages + arr[i] <=mid) {

                // Current book assigned to new student
                pages += arr[i];
            }
            else {

                pages=arr[i];
                student++;
            }
        }

        // If students required are within k
        // then this maximum page limit is possible
        return student <= k;
    }

    int findPages(vector<int>& arr, int k) {

        int n = arr.size();

        // If students are more than books
        // allocation impossible
        if (k > n) {
            return -1;
        }

        // Minimum possible answer:
        // maximum element
        // because one student must take that book
        int low = *max_element(arr.begin(), arr.end());

        // Maximum possible answer:
        // one student takes all books
        int high = accumulate(arr.begin(), arr.end(), 0);

        int ans = -1;

        while (low <= high) {

            // Candidate maximum pages
            int mid = low + (high - low) / 2;

            // Check if allocation possible
            if (possible(arr, k, mid)) {

                // mid is valid answer
                ans = mid;

                // Try to minimize maximum pages
                high = mid - 1;
            }
            else {

                // Need larger limit
                low = mid + 1;
            }
        }

        return ans;
    }
};