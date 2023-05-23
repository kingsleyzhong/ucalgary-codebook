/** 
 * Author: Kingsley Zhong 
 * Date: 
 * License: 
 * Description: Merge sort with inversion count
 * Time: $O(N \log N)$
 * Status: probably tested
 */
vi merge_sort(vi& arr, int s, int f, ll& inv){
    if(s == f){
        vi ret = {arr[s]};
        return ret;
    }
    int mid = s + (f - s)/2;
    vi v1 = merge_sort(arr, s, mid, inv);
    vi v2 = merge_sort(arr, mid+1, f, inv);
    int n = f-s+1;
    ll s1 = v1.size(), s2 = v2.size();
    vi ret(n);
    ll p1=0, p2=0;
    for(int i=0;i<n;++i){
        if((p2 == s2 or v1[p1] <= v2[p2]) and p1 != s1){
            ret[i] = v1[p1];
            p1++;
        }
        else{
            ret[i] = v2[p2];
            p2++;
            inv += s1 - p1;
        }
    }
    return ret;
}