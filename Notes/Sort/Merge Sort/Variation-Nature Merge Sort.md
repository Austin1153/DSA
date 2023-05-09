* MergeSort could be modified to take into account the prevailing order within the input list
* To determine the sublists of record that are **in order already**
* Merge sort then uses these initially ordered sublist for the remainder of the passes
```mermaid
graph TD
	26 --> L2_1[5, 26, 77]
	L1_2[5, 77] --> L2_1
	L1_3[1, 61] --> L2_2[1, 11, 50, 61]
	L1_4[11, 59] --> L2_2
	L1_5[15, 48] --> L2_3[15, 19, 48]
	19 --> L2_3
	%% 2-3
	L2_1 --> L3_1[1, 5, 11, 26, 50, 61, 77]
	L2_2 --> L3_1
	L2_3 --> L3_2[15, 19, 48]
	%% 3-4
	L3_1 --> L4[1, 5, 11, 15, 19, 26, 48, 50, 61, 77]
	L3_2 --> L4
```
