class Solution {
public:
    int findPeak(MountainArray& arr) {
        int left = 0;
        int right = arr.length() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            int current = arr.get(mid);
            int next = arr.get(mid + 1);

            if (current < next) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    int searchIncreasing(MountainArray& arr, int target,
                         int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = arr.get(mid);

            if (value == target) {
                return mid;
            }

            if (value < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    int searchDecreasing(MountainArray& arr, int target,
                         int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = arr.get(mid);

            if (value == target) {
                return mid;
            }

            if (value < target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();

        int peak = findPeak(mountainArr);

        int index = searchIncreasing(
            mountainArr, target, 0, peak
        );

        if (index != -1) {
            return index;
        }

        return searchDecreasing(
            mountainArr, target, peak + 1, n - 1
        );
    }
};