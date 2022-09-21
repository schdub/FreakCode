#include <algorithm>

// Напишите алгоритм remove_nth, который удаляет элемент из
// последовательности по номеру этого элемента.

template<class FwdIt>
FwdIt remove_nth(FwdIt p, FwdIt q, size_t n) {
    for (size_t current = 0; current < n && p != q; ++p, ++current);
    if (p == q) {
        return q;
    }
    for (FwdIt next = std::next(p, 1); next != q; ) {
        *p++ = *next++;
    }
    return p;
}
