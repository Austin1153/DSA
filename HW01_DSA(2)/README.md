# DSA(2) Program HW01
Contain following files
* Each Sorting algorithm and random generator
  * Insertion_Sort.cpp
  * Heap_Sort.cpp
  * Quick_Sort.cpp
  * Random.cpp
* main.cpp
* export.cpp
* Result and discussion
  * Sorting.csv
  * Sorting.xlsx
  * Sorting.docx

### main.cpp
This is for demo where you can choose Sorting Algorithm and input size.
Note that the random function is use as following
`rand()%50000`
only suits for mac environment, if windows system
`(rand()+rand())%50000`is required

### export.cpp
Auto generate the execute time of each sort into Sorting.csv
From Insertion, Heap to Quick Sort, using data input from 10 to 10000, each input size runs 10 times