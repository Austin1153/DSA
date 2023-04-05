A graph, $G$, consists of two set, $V$ and $E$.
* $V$ : vertices/vertex(頂點)的集合, is a finite, nonempty set.
* $E$ : edges(邊)的集合, a set of pairs of vertices.

$G=(V,E)$ represent a graph
```mermaid
---
title: Graph
---
graph LR
A(vertex頂點) -- edge --- B(vertex頂點)
```
## Types
* Undirected graph 無向圖
  The pairs of vertices $(u, v)$ representing any edge is unordered.
```mermaid
---
title: Undirected graph G1
---
graph TD
	A((0)) --- B((1)) --- D((3))
	B --- C((2))
	A --- D
	A --- C --- D
```
* * $V(G1) = \{0,1,2,3\}$
  * $E(G1) = \{(0,1),(0,2),(0,3),(1,2),(1,3),(2,3)\}$

* Directed graph(digraph) 有向圖
  Each edge is representing by a directed pair $<u, v>$
  * $u$ : tail  
  * $v$ : head
```mermaid
---
title: digraph G2
---
graph TD
	A((0)) --> B((1)) --> A
	B --> C((2))
```
* * $V(G2) = \{0,1,2\}$
  * $E(G2) = \{<0,1>,<1,0>,<1,2>\}$