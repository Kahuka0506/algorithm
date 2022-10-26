<h2 align="center">Algorithm Library</h2>
<p align="center"> </p>

[![Kahuka](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2FKahuka)](https://atcoder.jp/users/Kahuka)
[![Kahuka](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fcodeforces%2Fjson%2FKahuka)](https://codeforces.com/profile/Kahuka) 

 

## [Graph](./graph/)

### Shortest Path
- Dijkstra  `dijkstra.cpp`, $O(E\text{log}(V))$ 
- Bellman-Ford `bellman_ford.cpp`, $O(EV)$ 
- Warshall-Floyd  `warshall_floyd.cpp`, $O(V^3)$ 


### Minimam Spanning Tree (MST)
- プリム法 `mst_prim.cpp`, $O(E\text{log}(V))$ 
- クラスカル法 `mst_kruskal.cpp`, $O(E\text{log}(V))$     

### Cycle
- 閉路検出 `cycle_detection.cpp`
- トポロジカルソート `topological_sort.cpp` Topological Sort

### Connected Components
- 強連結成分分解 `scc.cpp`
- 橋 `bridge.cpp`
- 関節点 `articulation_point.cpp`
- 二辺連結成分分解 `two_edge_connected_components.cpp`

### Flow
- フォードファルカーソン `ford_fulkerson.cpp` Maximum Flow 
- ディニツ `dinic.cpp` Maximum Flow 
- プリプロープッシュ法
- 最小費用流(負閉路除去) `min_cost_flow_negative_cycle.cpp.cpp` Minimax Fost Flow
- 最小費用流(主双対法) `min_cost_flow_primal_dual.cpp.cpp` Minimax Fost Flow


### Matching
- 二部グラフ
- 二部マッチング





 

## [Tree](./tree/)
- 木の直径 `tree_diameter.cpp`
- 木の高さ `tree_height.cpp`
- 最小共通祖先   `lca.cpp`,`lca_RMQ.cpp` Lowest-Common-Ancestor (LCA) 
- オイラーツアー `euler_tour.cpp`
- HL分解 `HLD.cpp` Heavy-Light Decomposition (HLD)   
- Cartesian Tree `cartesian_tree.cpp`
 
 
 

## [Data Structure](./data_structure/)
- Union-Find  `union_find.cpp`
- Wehited Unionf-Find `union_find_weighted.cpp`
- 座標圧縮 `compress.cpp`
- 累積和 `cumulative_sum.cpp`
- Sparse Table `sparse_table.cpp`
- Binary index tree `binary_index_tree.cpp`   
- Segment Tree  `segment_tree.cpp`
    - Range Minimum Query  `segment_tree_RMQ.cpp`
    - Range Add Query  `segment_tree_RAQ.cpp`
- Lazy Swgmet Tree `lazy_segment_tree.cpp`
    - Range Updata Query  `lazy_segment_tree_RUQ.cpp`
    - Range Add Query  `lazy_segment_tree_RAQ.cpp`
- トライ木 `trie.cpp`
- 二分探索木 `binary_search_tree.cpp`
- Treap `treap.cpp`，`treap_map.cpp`
 
 
## [Number](./number/)
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

 
 
## [Math](./math/)
- 高速フーリエ変換 (FFT) `fast_fourier_transform.cpp`
- 行列冪乗 
- Matrix Product `matrix_product.cpp`
- Matrix Determinant `matrix_determinait.cpp`
- Matrix Inverse `matrix_inverse.cpp` 
- Matrix Linear-Equation`matrix_linear_equation.cpp`
- Kitamasa法 `kitamasa_method.cpp`
- ラグランジュ補完 `lagrange_interpolation.cpp` mod書き換え
 
 
## [String](./string/)
### Z-Algorithm
`z_algorithm.cpp`     
文字列$S$，$S$と$S[i:|S|]$の最長共通接頭辞(LCP,Longest common prefix)の長さを記録した配列を$O(|S|)$で構築．


### KMP

### Manacher

### Rolling-Hash
`rolling_hash.cpp`  

### Suffix Array
`suffix_array.cpp`


 
## Game
- Nim
- Grundy

 
## [Other](./other/)
- Xor-Shirft `xorshift.cpp`
- 再帰下降構文解析 EBNF(Extended Backus–Naur Form) `EBNF.cpp`
- 二分探索木 Binary Search Tree `binary_search_tree.cpp`
- 赤黒木
