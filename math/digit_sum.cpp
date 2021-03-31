
template <typename T> T digit_sum(T n) {
    T res = 0;
    while (n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}
