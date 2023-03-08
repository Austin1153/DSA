On the i<sup>th</sup> pass the lists being merged are of size 2<sup>i-1</sup>
* 1st pass : size =1 的merge
* 2nd pass : size =2 的merge
* ....
Total of $\lceil \log_2 n \rceil$ passes are made over the data. 
Each pass of merge sort takes $O(n)$ time. The total of computing time is $O(n \log n)$ 

### [[Variation-Nature Merge Sort]]