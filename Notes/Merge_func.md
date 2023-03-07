```cpp
// Original List , where List[l:m] and List[m+1:n] is sorted separately
// Merge List[l:m] and List[m+1:n] to MergedList[l:n]
void Merge(int List[], int MergedList[], int l, int m, int n) {
    // i_a is index of List[l:m], i_b for List[m+1:n] , i_result for MergeList[l:m]
    // Both input List aren't finished, i.e. l != m != n
    int i_a, i_b, i_result;
	for (i_a = l, i_b = m+1, i_result = l; i_a <= m && i_b <= n; i_result++) {
        if (List[i_a] <= List[i_b])
            MergedList[i_result] = List[i_a++];
        else
            MergedList[i_result] = List[i_b++];
    }
    // if List a have leftovers, copy to end of MergeList
    copy(List + i_a, List + m+1, MergedList + i_result);
    // if List b have leftovers, copy to end of MergeList
    copy(List + i_b, List + n+1, MergedList + i_result);
}
```
