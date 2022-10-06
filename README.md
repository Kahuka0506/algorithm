# Algorithm Library

[![Kahuka](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2FKahuka)](https://atcoder.jp/users/Kahuka)
[![Kahuka](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fcodeforces%2Fjson%2FKahuka)](https://codeforces.com/profile/Kahuka) 


## [Graph](./graph/)
- ベルマンフォード   `bellman_ford.cpp`  Shortest-Path
- ダイクストラ   `dijkstra.cpp`  Shortest-Path
- ワーシャルフロイド  `warshall_floyd.cpp`  Shortest-Path
- プリム法   `mst_prim.cpp` minimam-spanning-tree (MST)
- クラスカル法  `mst_kruskal.cpp` minimam-spanning-tree (MST)
- 閉路検出 `cycle_detection.cpp`
- 強連結成分分解 `scc.cpp` Strongly Connected Component (SCC) 
- フォードファルカーソン `ford_fulkerson.cpp` Maximum Flow 
- ディニツ `dinic.cpp` Maximum Flow 
- プリプロープッシュ法
- 最小費用流(負閉路除去) `min_cost_flow_negative_cycle.cpp.cpp` Minimax Fost Flow
- 最小費用流(主双対法) `min_cost_flow_primal_dual.cpp.cpp` Minimax Fost Flow
- 二部グラフ
- 二部マッチング


## [Tree](./tree/)
- トポロジカルソート `topological_sort.cpp` Topological Sort
- 木の直径 `tree_diameter.cpp`
- 木の高さ
- 最小共通祖先   `lca.cpp` Lowest-Common-Ancestor (LCA) 
- オイラーツアー `euler_tour.cpp`
- HL分解 `HLD.cpp` Heavy-Light Decomposition (HLD)   



## [Data Structure](./data_structure/)
- Union Find  `union_find.cpp`
- 重みつきUnion Find `union_find.cpp`
- 座標圧縮 `compress.cpp`
- Binary index tree `binary_index_tree.cpp`   
- セグメント木  `segment_tree.cpp`
- セグメント木 Range Minimum Query  `segment_tree.cpp`
- セグメント木 Range Sum Query  `segment_tree.cpp`
- 遅延評価セグメント木 Range Updata Query  `lazy_segment_tree_RUQ.cpp`
- 遅延評価セグメント木 Range Add Query  `lazy_segment_tree_RAQ.cpp`
- トライ木 `trie.cpp`


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

## Game
- Nim
- Grundy



## [String](./string/)
- Rolling-Hash `rolling_hash.cpp`
- Z-algorithm `z_algorithm.cpp`
- KMP
- Manacher


## [Other](./other/)
- Xor-Shirft `xorshift.cpp`
- 再帰下降構文解析 EBNF(Extended Backus–Naur Form) `EBNF.cpp`
- 二分探索木 Binary Search Tree `binary_search_tree.cpp`
- 赤黒木
