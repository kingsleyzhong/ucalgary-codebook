/** 
 * Author: Kingsley Zhong 
 * Date: 
 * Description: Simple binary search
 * License: 
 * Status: probably tested
 */
int binarySearch(const vi& arr, int t) {
    int l = 0;
    int r = arr.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= t) {// lower bound, switch around conditions for upper bound
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}
