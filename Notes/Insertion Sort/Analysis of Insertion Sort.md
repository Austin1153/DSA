Insertion: $O(n)$
* In the worst case, Insert(e, a, i) makes i+1 comparisons
Insertion sort: $O(n^2)$
```cpp
template <class T>
void InsertionSort(T *a, const int n) { 
	for(int j= 2; j <= n; j++) { //j = 2~n
		T temp = a[j];
		Insert(temp, a, j–1);
	}
}
```
```cpp
template <class T>
void Insert(const T &e, T *a, int i) { //i = j-1 
	a[0] = e;
	while (e < a[i]) { //i = 1 ~ n-1(i -> i+1 comparisons)
		a[i+1] = a[i];
		i--;
	}
	a[i+1] = e;
}
```
$O( \sum_{i=1}^{n-1}(i+1)) = O(n^2)$

#### LOO
![[Insertion_sort_LOO.png]]

