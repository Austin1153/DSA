Path路徑 : 從vertax(頂點)$u$ 到$v$ 所經過的edge的集合
i.e. $(u,i_1),(i_1,i_2),\cdots ,(i_n, v)$ or $<u,i_1>,<i_1,i_2>,\cdots ,<i_n, v>$
#### length
長度 : number of edge in a path
### Simple Path
除了頭尾之外,other vertex on the path cannot repeat
### Cycle
A Simple Path where 頭尾相同

E.g.
* $(0, 1) (1, 3) (3, 2) \rightarrow$ 0, 1, 3, 2 simple path
* $(0, 1) (1, 3) (3, 1) \rightarrow$ 0, 1, 3, 1 not simple path
* Both length are 3
* $(0, 1) (1, 3) (3, 0) \rightarrow$ cycle