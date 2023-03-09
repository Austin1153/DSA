#### Introuction & advantages
* Merge sort needs **additional storage space** proportional to the number of records in the file being sorted, even though its computing time is $O(n \log n)$
* Heap sort only requires a **fixed amount of additional storage** and achieves the **worst-case and average computing time** $O(n \log n)$

### Method
Heap sort uses the **max-heap** structure.
1. The n records are inserted into an empty heap.
2. The records are extracted from the heap one at a time (**extracted from root**). With the use of a special function [[#Adjust Function]], we can create a heap of n records **faster**.
* If the depth of heap tree is d, the computing time of [[#Adjust Function]] is $O(d)$

#### Example
Initialize the heap
![[Heap Sort init.png]]
Sorting use Adjust function
![[Heap Sort adjust.png]]

### Adjust Function
```cpp
// 調整一棵樹根為root的二元樹使其符合堆積的性質。此時root的左、右子樹都已經符合堆積的性質。沒有一個節點的索引值 > n
template <class T>
void Adjust(T*a,const int root, const int n){ 
	// 找到e的適當位置
	T e = a[root];
	for (int j = 2*root; j <= n; j *= 2) {
		// let j become 它父親的最大兒子
		if (j < n && a[j] < a[j+1]) j++;
		// e可以插入成為j的父親
		if (e >= a[j]) break;
		// 把第j筆記錄往樹的上方移動
		a[j/2] = a[j];
	}
	a[j/2] = e;
}
```

### Heap Sort
```cpp
template <class T>
void HeapSort(T*a,const int n) {
// 將a[1:n] 排序成非遞減的順序for (inti= n/2;i>= 1; i--) // 建立堆積Adjust(a, i,n);for (i= n-1; i>= 1; i--)// 排序{swap(a[1], a[i+1]); // 對調目前堆疊中的第一個與最後一個Adjust(a, 1, i); // 建立堆疊}}
```