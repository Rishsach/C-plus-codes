
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2) +
                    findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }
    }

    int findKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                                 int k) {
        const int m = A.size();
        const int n = B.size();


        if (m > n) {
            return findKthInTwoSortedArrays(B, A, k);
        }

        int left = 0;
        int right = m;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (0 <= k - 1 - mid && k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : numeric_limits<int>::min();
        int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : numeric_limits<int>::min();

        
        return max(Ai_minus_1, Bj);
    }
};


class Solution_Generic {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int> *> arrays{&nums1, &nums2};
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKthInSortedArrays(arrays, (nums1.size() + nums2.size()) / 2 + 1);
        } else {
            return (findKthInSortedArrays(arrays, (nums1.size() + nums2.size()) / 2) +
                    findKthInSortedArrays(arrays, (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }
    }

private:
    int findKthInSortedArrays(const vector<vector<int> *>& arrays, int k) {
        int left = numeric_limits<int>::max();
        int right = numeric_limits<int>::min();
        for (const auto array : arrays) {
            if (!array->empty()) {
                left = min(left, array->front());
                right = max(right, array->back());
            }
        }
        
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (match(arrays, mid, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool match(const vector<vector<int> *>& arrays, int num, int target) {
        int res = 0;
        for (const auto array : arrays) {
            if (!array->empty()) {
                res += distance(upper_bound(array->cbegin(), array->cend(), num),
                                array->cend());
            }
        }
        return res < target;
    }
};