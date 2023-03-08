##### Time complexiety
* The time required is $n-l+1$ as all elements in List a & b going throngh the Merge only. So is $O(n-l+1)$ when each record have size of 1.
* If record have size s (contain multiple data in a record), is $O(s(n-l+1))$ as each record has to be moved entirely.
* Using Linked List can reduce to $O(n-l+1)$ when record > 1, as only change links, won't required to move the whole records.

##### Space Complexiety
* Require $n-l+1$ record space to store Merged result.
* Using Linked List only need $n-l+1$ Links, independent from record size s.