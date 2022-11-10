# xorshift
リンク : [../other/xorshift.cpp](../other/xorshift.cpp)    
最終更新 : 2021-10-26 13:35:29.468786

```cpp

unsigned int xorshift() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

```