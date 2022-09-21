#include <algorithm>
#include <vector>

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

// Напишите шаблонную функцию count_permutations, которая принимает
// некоторую последовательность и вычисляет количество перестановок
// этой последовательности (равные последовательности считаются одной
// перестановкой), в которых нет подряд идущих одинаковых элементов.

template<class Iterator>
size_t count_permutations(Iterator p, Iterator q) {
    using T = typename std::iterator_traits<Iterator>::value_type;
    std::vector<T> vec(p, q);
    std::sort(vec.begin(), vec.end());
    size_t cnt = 0;
    do {
        auto it = std::adjacent_find(vec.begin(), vec.end());
        if (it == vec.end()) {
            cnt += 1;
        }
    } while (std::next_permutation(vec.begin(), vec.end()));
    return cnt;
}
