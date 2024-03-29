
<h2 align="center">Algorithm Library</h2>
<p align="center"> </p>

[![Kahuka](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2FKahuka)](https://atcoder.jp/users/Kahuka)
[![Kahuka](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fcodeforces%2Fjson%2FKahuka)](https://codeforces.com/profile/Kahuka)

    
        
[List](./docs/index.md)

## Data Structure
[data_structure/README.md](./data_structure/README.md)

- Union-Find  `union_find.cpp`
- Wehited Unionf-Find `union_find_weighted.cpp`
- 座標圧縮 `compress.cpp`
- 累積和 
    - 1次元 `range_sum_dim1.cpp`
    - 2次元 `range_sum_dim2.cpp`
- Range Min/Max `range_min.cpp`
- Sparse Table `sparse_table.cpp`
- Fenwic Tree `fenwic_tree.cpp`   
- Segment Tree  `segment_tree.cpp`
    - Range Minimum Query  `segment_tree_RMQ.cpp`
    - Range Add Query  `segment_tree_RAQ.cpp`
- Lazy Swgmet Tree `lazy_segment_tree.cpp`
    - `lazy_segment_tree_RSQ_RUQ.cpp`
    - `lazy_segment_tree_RSQ_RAQ.cpp`
    - `lazy_segment_tree_RMQ_RUQ.cpp`
    - `lazy_segment_tree_RMQ_RAQ.cpp`
- kD-tree `kD_tree.cpp`
- トライ木 `trie.cpp`
- Heap
    - Heap `heap.cpp`
    - Interval-Heap `interval_heap.cpp`
    - Leftist-Heap `leftist_heap.cpp`
- Binary Search Tree
    - 二分探索木 `binary_search_tree.cpp`
    - Treap `treap.cpp`，`treap_map.cpp`
- Stack,Queue
    - Stack `stack.cpp`
    - Persistent Stack `persistent_stack.cpp`
    - Queue `queue.cpp`
    - Persistent Queue `persistent_queue.cpp`
    - Sliding Window Aggregation `sliding_window_aggregation.cpp`
    - Deque Aggregation `deque_aggregation.cpp`
- Mo Algorithm `mo_algorithm.cpp`


## Graph
[graph/README.md](./graph/README.md)

#### Shortest Path
- Dijkstra `dijkstra.cpp`, $O(E\text{log}(V))$ 
- Bellman-Ford `bellman_ford.cpp`, $O(EV)$ 
- Warshall-Floyd  `warshall_floyd.cpp`, $O(V^3)$ 


#### Minimam Spanning Tree (MST)
- プリム法 `mst_prim.cpp`, $O(E\text{log}(V))$ 
- クラスカル法 `mst_kruskal.cpp`, $O(E\text{log}(V))$     

#### Cycle
- 閉路検出 `cycle_detection.cpp`
- トポロジカルソート `topological_sort.cpp` Topological Sort

#### Connected Components
- 強連結成分分解 `scc.cpp`
- 橋 `bridge.cpp`
- 関節点 `articulation_point.cpp`
- 二辺連結成分分解 `two_edge_connected_components.cpp`

#### Flow
- フォードファルカーソン `ford_fulkerson.cpp` Maximum Flow, $ O(EF) $
- ディニツ `dinic.cpp` Maximum Flow, $ O(EV^2) $
- プリプロープッシュ法
- 最小費用流(負閉路除去) `min_cost_flow_negative_cycle.cpp.cpp` Minimax Fost Flow
- 最小費用流(主双対法) `min_cost_flow_primal_dual.cpp.cpp` Minimax Fost Flow


#### Matching
- 二部グラフ
- 二部グラフのマッチング 
    - 最大流(Dinic) `biparate_matching_dinic.cpp` 
    - 増加道アルゴリズム `biparate_matching.cpp` $ O(EV) $
    - Hopcroft-Karp `biparate_matching_HopcroftKarp.cpp` $ O(E\sqrt(V)) $

#### other
- 最大クリーク数，最大独立点集合 `maximum_indepenedent_set.cpp`
- 彩色数


## Math
[math/README.md](./math/README.md)
  
- 高速フーリエ変換 (FFT) `fast_fourier_transform.cpp`
- 行列冪乗 
- Matrix Product `matrix_product.cpp`
- Matrix Determinant `matrix_determinait.cpp`
- Matrix Inverse `matrix_inverse.cpp` 
- Matrix Linear-Equation`matrix_linear_equation.cpp`
- Kitamasa法 `kitamasa_method.cpp`
- ラグランジュ補完 `lagrange_interpolation.cpp` mod書き換え


## Number
[number/README.md](./number/README.md)
  
- 桁和 `digit_sum.cpp`  
- 約数列挙  `enum_divisors.cpp`  
- 最小共約数・最大公倍数  `gcd_lcm.cpp`  
- 拡張ユークリッド互助法 `extgcd.cpp`  
- $_nC_m$計算 `combination.cpp`
- mod-Library  `mod.cpp`
- mod計算 `mint.cpp`
- 素因数分解  `prime.cpp`  
- エラストテネスの篩い `prime_eratosthenes.cpp`
- Floor-Sum
- 中国剰余定理 Chinese-Remainder-Theorem (CRT) `crt.cpp`  

 


## String
[string/README.md](./string/README.md)

- Z-Algorithm`z_algorithm.cpp`     
文字列$S$，$S$と$S[i:|S|]$の最長共通接頭辞(LCP,Longest common prefix)の長さを記録した配列を$O(|S|)$で構築．
- KMP
- Manacher
- Rolling-Hash`rolling_hash.cpp`  
- Suffix Array`suffix_array.cpp`





## Tree
[tree/README.md](./tree/README.md)
 
- 木の直径 `tree_diameter.cpp`
- 木の高さ `tree_height.cpp`
- 最小共通祖先，Lowest-Common-Ancestor (LCA) 
    - `lca.cpp`
    - `lca_RMQ.cpp`
    - `lca_HLD.cpp`
- オイラーツアー `euler_tour.cpp`
- HL分解，Heavy-Light Decomposition (HLD)   
    - `hld.cpp` 
    - `hld_exec.cpp` 
- Cartesian Tree `cartesian_tree.cpp`


