We first consider merge two sorted lists to get a single sorted list. (先了解一下怎樣合併兩個排序過的序列)

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

```cpp
template <class T>
void Merge(T*initList, T*mergedList, constintl, constintm, constintn){
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
		// 如果第一個串列有剩下的記錄，那麼把它複製完
		copy (initList + i1, initList + m + 1, mergedList + iResult);
		// 如果第二個串列有剩下的記錄，那麼把它複製完
		copy(initList + i2, initList + n + 1, mergedList + iResult);
}
```

