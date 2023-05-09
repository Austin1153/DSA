> A very good average sorting scheme

We select a ==pivot== record from among the records to be sorted.
* The keys of records to the ==left== of the pivot $\leq$ pivot 
* The keys of records to the ==right== of the pivot $\geq$ pivot.
Finally, the records to the left of the pivot and those to its right are sorted independently
遞迴的持續找樞紐與分類
```cpp
// initial def: value of a[n+1] >= all value in a[1:n]
template <class T>
// sort a[left:right] ascending
void QuickSort(T *a, const int left, const int right) {
	// Using a[left] as pivot, to sort that at any time
	// a[m] ≤ pivot & m < i, also a[m] ≥ pivot & m > j
	// assume a[left] <= a[right+1]
	if (left < right) {
		int i = left;
		int j = right + 1;
		int pivot = a[left];
		do {
			do i++; while (a[i] < pivot);
			do j--; while (a[j] > pivot);
			if (i < j) swap(a[i], a[j]);
		} while (i < j);
		swap(a[left], a[j]);
		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}
}
```
![[HW01.pdf]]

#### Variation QuickSort
###### median-of-three
*  this pivot in the median of the first, middle and last keys in the current sublist
* pivot = *median* {K<sub>l</sub>, K<sub>(l+r)/2</sub>, K<sub>r</sub>}
  Ex: *median* {10, 5, 7}=7; *median* {10, 7, 7}=7