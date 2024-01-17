#include <bits/stdc++.h>

int getNumber(const std::vector<int> & a) {
    assert(a.size() >= 3);
    auto is_odd  = [](const int v) { return (v % 2) != 0; };
    auto is_even = [](const int v) { return (v % 2) == 0; };
    auto it = (((a[0] & 1) | (a[1] & 1) | (a[2] & 1))
      ? find_if(a.begin(), a.end(), is_even)
      : find_if(a.begin(), a.end(), is_odd));
    assert(it != a.end());
    return *it;
}

int main() {
    std::vector<int> array {-2, 6, 4054, 6, 11, 0, 36};
    std::vector<int> array2 {202, 1, 1937, 107, -119, 13, 31};
    assert(getNumber(array) == 11);
    assert(getNumber(array2) == 202);
    return 0;
}
