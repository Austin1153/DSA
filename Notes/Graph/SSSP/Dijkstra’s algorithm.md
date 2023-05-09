Weights are ==non-negative==
### algorithm concept
* maintains $S$ where all vertax in it 都已經找到v<sub>0</sub>出發最短路徑
* 重複選擇 $u$ **not in $S$** and with **minimum shortest-path** estimate, add to $S$, and [[Ralax]] all edge leaving $u$
* uses [[Greedy algorithm]]
#### pseudo-code
```python
# init single source for Dijkstra
def Init_SS(G, s):
	for v in G:
		v.d = -1
		v.pi = NULL
	s.d = 0
# w = weights, s = source
def Dijkstra(G, w, s):
	Init_SS(G, s)
	s = {} # s = empty set
	Q = G.v
	while !Q.empty() :
		u = Q.extract_min() # Q is min priority queue
		S.add(u) # u is the vertax with shortest path for all not in S
		for v in G.Adj(u) :
			relax(u, v, w)
```
`relax(u, v, w` see [[Ralax]]
