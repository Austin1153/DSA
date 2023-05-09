Insertion sort is a good algorithm for sorting a **small number** of elements.

### method
* The basic step in this method is to insert a new record into a sorted sequence of i record
* The resulted sequence of size i+1 is also ordered.
#### Insert
insert 2 into a list of size i=3 \[1,3,5\], require a size of i+2 list

|\[0\]|\[1\]|\[2\]|\[3\]|\[4\]|
|---|---|---|---|---|
|||||
||1|3|5|
|||||
|2|1|3|5||
|||||
|2|1|3||5|
|||||
|2|1||3|5|
|||||
|2|1|2|3|5|
```cpp
template <class T>
// Insert e into a sorted list a[1:i]
// where resulted a[1:i+1] is also sorted
// requires a to have space for i+2 elements
void Insert(const T &e, T *a, int i) {
	a[0] = e;
	// if e < a[i], move a[i] back
	// else insert e
	while (e < a[i]) {
		a[i+1] = a[i];
		i--;
	}
	a[i+1] = e;
}
```
The use of a\[0\] enables us to avoid a test for end of list (i<1)
#### Insertion Sort
```cpp
template <class T>
void InsertionSort(T *a, const int n) {
	for(int j= 2; j <= n; j++) {
		T temp = a[j];
		Insert(temp, a, j–1);
	}
}
```
[Complete view](HW01.pdf)

### ![[Analysis of Insertion Sort]]
### ![[Insertion Sort Variations]]
