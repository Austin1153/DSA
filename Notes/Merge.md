We merge two lists List A\[1:m\] and B\[m+1:n\] into a single list
The resulting merged list is mergedList\[l:n\], as below.

<table style="font-family: Arial, Helvetica, sans-serif;border-collapse: collapse;width: 100%;">
	<tr style="border: 2px solid #362c28;padding: 6px;">
		<th style="background-color: #f3c969; color: #362c28; text-align: center; padding-top: 12px; padding-bottom: 12px;">1 : m</th><th style="background-color: #fff5b2; color: #362c28; text-align: center; padding-top: 12px; padding-bottom: 12px;">m+1 : n</th>
	</tr>
	<tr style="border: 0px; padding: 6px;">            
		<th style="border: 0px; color: #362c28; text-align: center; padding-top: 12px; padding-bottom: 12px;"></th><th style="border: 0px; color: #362c28; text-align: center; padding-top: 12px; padding-bottom: 12px;"></th>
	</tr>
	<tr style="background-color: #d4fcc3;border: 2px solid #362c28;padding: 6px;">
		<th colspan="2" style="color: #362c28; text-align: center; padding-top: 12px; padding-bottom: 12px;">1 : n</th>
	</tr>
</table>

Code(Template version) :
```cpp
template <class T>
void Merge(T*initList, T*mergedList, const int l, const int m, const int n){
	// initList[l:m] 與initList[m+ 1:n] 是排序好的串列。
	// 我們將它們合併成排序好的串列mergedList[l:n]。
	for(int i1 = l, iResult= l, i2 = m + 1; i1 <= m && i2 <= n; iResult++)
	// i1, i2, 與iResult是串列位置
	// 兩個輸入串列都還沒用盡
		if (initList[i1] <= initList[i2]) {
			mergedList[iResult] = initList[i1];i1++;
		} else {
			mergedList[iResult] = initList[i2];i2++;
		}
	}
	// 如果第一個串列有剩下的記錄，那麼把它複製完
	copy (initList + i1, initList + m + 1, mergedList + iResult);
	// 如果第二個串列有剩下的記錄，那麼把它複製完
	copy(initList + i2, initList + n + 1, mergedList + iResult);
}
```

Merge_func modify by myself, without templete
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

#### [[Analysis of Merge]] 
