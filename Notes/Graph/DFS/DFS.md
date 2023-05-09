class Graph G = {V,E} 
class vertax in Graph
* color : white grey black
* d : distance w/ root & discover time
* pi : predecessor 祖先
* f : finish time
```python
def DFS(G) :
	# init the graph
	for u in G :
		u.color = white
		u.pi = NULL
		time = 0;
	# start DFS
	# 會產生連通圖(DFS Tree)
	for u in G :
		# a node in tree goes in if
		# then this tree will complete
		# goes in if n times, have n tree
		if u.color == white :
			DFS-Visit(G, u)
```
```python
def DFS-Visit(G, u) :
	time++
	u.d = time
	u.color = grey
	for v in G.adj(u) :
		if v.color == white :
			v.pi = u
			DFS-Visit(G, v)
	u.color = black
	time++
	u.f = time
```
