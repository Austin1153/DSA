The element to be ==deleted== is the one with **highest/lowest priorty**
We can insert elements with priorty attribute into queue at any time
==Queue 但有優先順序，而非單純FIFO==

#### Implementation & Analysis
The simplest way to represent a priority queue is as an **unsorted linear list** (sequentially or as a chain) 沒排序過的線性串列
If a unsorted linear list is used : 
* the **IsEmpty** function takes $O(1)$ time 
* the **Top** function takes $Θ(n)$ time, where n is the number of elements in the priority queue這裡的top指的是找出最大值
* A **Push** can be done in $O(1)$ time as it doesn’t matter where in the list the new element is inserted. Push是指把任意資料放進去heap tree
* A **Pop** takes $Θ(n)$ time as me must first find the element with max priority and then delete it. Pop是指把最⼤值從heap tree當中取出來
因為沒有排序，所以要找最⼤大值，只好把線性串串列列從頭到尾看⼀遍

#### Improvement
As we shall see shortly, when a [max heap](Heap) is used, the complexity of **IsEmpty** and **Top** is $O(1)$ and that of **Push** and **Pop** is $O(\log n)$
