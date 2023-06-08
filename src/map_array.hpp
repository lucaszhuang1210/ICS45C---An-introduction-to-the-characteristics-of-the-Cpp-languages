#ifndef MAP_ARRAY_HPP
#define MAP_ARRAY_HPP

#include <algorithm>
#include <iterator>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>

template <typename Key, typename Value>
class MapArray {
public:     
    using value_type = std::pair<Key, Value>;

    //***********************Iterator***********************
    class ArrayIterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = MapArray::value_type;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

        explicit ArrayIterator(pointer ptr = nullptr)
        :ptr(ptr)
        {}

        ArrayIterator& operator++() { ++ptr; return *this; }
        ArrayIterator& operator--() { --ptr; return *this; }
        ArrayIterator operator++(int) { ArrayIterator temp = *this; ++ptr; return temp; }
        ArrayIterator operator--(int) { ArrayIterator temp = *this; --ptr; return temp; }
        ArrayIterator& operator +=(difference_type d) { ptr += d; return *this; }
        ArrayIterator& operator -=(difference_type d) { ptr -= d; return *this; }
        friend ArrayIterator operator+(ArrayIterator it, difference_type d) { 
            return ArrayIterator(it.ptr+d); }
        friend ArrayIterator operator+(difference_type d, ArrayIterator it) { 
            return ArrayIterator(it.ptr+d); }
        friend ArrayIterator operator-(ArrayIterator it, difference_type d) { 
            return ArrayIterator(it.ptr-d); }
        friend difference_type operator-(ArrayIterator lhs, ArrayIterator rhs) { 
            return lhs.ptr-rhs.ptr; }

        auto operator<=>(const ArrayIterator& other) const = default;
        std::pair<Key, Value>& operator*() const { return *ptr; }
        std::pair<Key, Value>* operator->() const { return ptr; }
        std::pair<Key, Value>& operator[] (difference_type d) const { return *(ptr+d); }
    private:
        std::pair<Key, Value>* ptr;
    };
    //******************************************************
    using iterator = ArrayIterator;
    ArrayIterator begin() { return ArrayIterator(data.data()); }
    ArrayIterator end() { return ArrayIterator(data.data() + data.size()); }
    Value& operator[] (const Key& key) 
    {
        auto position_iter = std::lower_bound(data.begin(), data.end(), 
                                            std::make_pair(key, Value()),
                                            [](const value_type& a, const value_type& b)
                                            {   return a.first < b.first;   } );
        if (position_iter == data.end() || position_iter->first != key){
            position_iter = data.insert(position_iter, std::make_pair(key, Value()));
        }
        return position_iter->second;
    }
private:
    std::vector<std::pair<Key, Value>> data;
    static_assert(std::random_access_iterator<iterator>);
};

#endif
