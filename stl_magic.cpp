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

// В этом задании вам нужно разработать итераторы для контейнера VectorList,
// который хранит данные в списке векторов. Для упрощения задачи от вас
// требуется реализовать только константные итераторы (прямой и обратный),
// а также реализовать методы begin, end, rbegin и rend. Для того, чтобы
// разобраться в устройстве контейнера, начните работу над задачей с реализации
// метода size. Заполнение контейнера будет происходить при помощи метода append,
// который уже реализован (реализация в комментариях дана для ознакомления). Метод
// append гарантирует, что в списке не будет пустых векторов.

#include <vector>
#include <list>

template <class T>
class VectorList {
    using VectT = std::vector<T>;
    using ListT = std::list<VectT>;

public:
    VectorList() = default;

    VectorList(VectorList &&) = default;
    VectorList(VectorList const &) = default;

    VectorList & operator=(VectorList &&) = default;
    VectorList & operator=(VectorList const &) = default;

    // метод, который будет использоваться для заполнения VectorList
    // гарантирует, что в списке не будет пустых массивов
    template<class It>
    void append(It p, It q) {
        if (p != q)
            data_.push_back(VectT(p,q));
    }

    bool empty() const { return size() == 0; }

    // определите метод size
    size_t size() const {
        size_t result = 0;
        for (const auto & v : data_) {
            result += v.size();
        }
        return result;
    }

    // определите const_iterator
    struct const_iterator {
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = const T;
        using pointer           = value_type*;  // or also value_type*
        using reference         = value_type&;  // or also value_type&

        using LI = typename ListT::const_iterator;
        using VI = typename VectT::const_iterator;

        const ListT * pdata_ = nullptr;
        LI itl_;
        VI itv_;

        const_iterator() = default;

        const_iterator(const const_iterator &) = default;

        const_iterator(const ListT* pdata)
            : pdata_(pdata)
        {
            itl_ = pdata->begin();
            itv_ = itl_->begin();
        }

        const_iterator(const ListT* pdata, LI li)
            : pdata_(pdata)
            , itl_(li)
        {}

        const_iterator(const ListT* pdata, LI li, VI vi)
            : pdata_(pdata)
            , itl_(li)
            , itv_(vi)
        {}

        const_iterator operator++(int) {
            const_iterator tmp = *this;
            int it_diff = (itl_->end() - itv_);
            if (it_diff > 1) {
                ++itv_;
            } else {
                ++itl_;
                if (itl_ != pdata_->end()) {
                    itv_ = itl_->begin();
                } else {
                    itv_ = VI{};
                }
            }
            return tmp;
        }
        const_iterator& operator++ () {
            this->operator++(1);
            return *this;
        }

        const_iterator operator--(int) {
            const_iterator tmp = *this;
            if (itl_ == pdata_->end()) {
                --itl_;
                itv_ = itl_->end();
                --itv_;
            } else {
                if (itv_ != itl_->begin()) {
                    --itv_;
                } else {
                    if (itl_ == pdata_->begin()) {
                    } else {
                        --itl_;
                        if (itl_->size() != 0) {
                            itv_ = itl_->begin();
                            itv_ = std::next(itv_, itl_->size()-1);
                        }
                    }
                }
            }
            return tmp;
        }
        const_iterator& operator--() {
            this->operator--(1);
            return *this;
        }

        bool operator!=(const const_iterator& other) const {
            return !( *this == other );
        }
        bool operator==(const const_iterator& other) const {
            if (pdata_ != other.pdata_) {
                return false;
            }
            if (itl_ != other.itl_) {
                return false;
            }
            if (itv_ != other.itv_) {
                return false;
            }
            return true;
        }

        const T& operator*() const {
            return *itv_;
        }
        const T* operator->() const {
            return itv_.operator->();
        }
    };

    // определите методы begin / end
    const_iterator begin() const {
        return const_iterator(&data_);
    }
    const_iterator end() const {
        return const_iterator(&data_, data_.end());
    }

    // определите const_reverse_iterator
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // определите методы rbegin / rend
    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }
    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

private:
    ListT data_;
};
