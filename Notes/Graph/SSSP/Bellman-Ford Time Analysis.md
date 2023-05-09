```python
def Bellman_Ford(G, w, s):
	Init_SS(G, s) # init all node O(|V|)

	# evaluate every node (|V-1| time)
	# each cycle check every edge -> O(|V||E|)
	for i in range(1, len(G.V)):
		for edge in G.E: 
			Relax(u, v, w)

	# check all edge for negative-cylce O(|E|)
	for edge in G.E:
		if v.d > u.d + w(u, v)
			return false 
	return true
```
total time analysis : $O(|V||E|)$ 