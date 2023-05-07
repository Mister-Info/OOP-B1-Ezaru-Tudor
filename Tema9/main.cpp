#include <iostream>
#include <vector>
#include <map>

template<typename K, typename V>
struct Map {
    struct Element {
        K key;
        V value;
        int index;
    };
    int size;
    int capacity;
    Element* data;
    Map(){
        capacity = 1;
        data = new Element[capacity];
        size = 0;
        data->index = 0;
    }
    ~Map() {
        delete[] data;
    }
    void Set(const K& key, const V& value) {
        if (size == capacity) {
            capacity *= 2;
            Element* data2 = new Element[capacity];
            for (int i = 0; i < size; ++i) {
                data2[i] = data[i];
            }
            delete[] data;
            data = data2;
        }
        auto& data2 = data[size];
        data2.key = key;
        data2.value = value;
        data2.index = size; 
        size++;
    }
    bool Get(const K& key, V& value) {

        for (int i = 0; i < size; ++i) {
            if (data[i].key == key)
            {
                value = data[i].value;
                return true;
            }
        }
        return false;
    }
    int Count() {
        return size;
    }

    void Clear() {
        delete[] data;
        size = 0;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < size; ++i) {
            if (data[i].key == key) {
                for (int j = i; j < size-1; ++j) {
                    data[j] = data[j + 1];
                }
                return true;
            }
        }
        return false;
    }
    bool Includes(const Map<K, V>& map) {
        for (int i = 0; i < min(data.size,map.size); ++i) {
            if (map[i].key != data[i].key || map[i].value != data[i].value) {
                return false;
            }
        }
        return true;
    }

    V& operator[](const K key) {
        int i = 0;
        for (i; i < size; i++) {
            if (data[i].key == key) {
                return data[i].value;
            }
        }
        V v = {};
        Set(key, v);
        return data[i].value;
    }
    struct iterator {
        Element* ptr;

        iterator(Element* ptr) : ptr(ptr) {
        }

        bool operator!=(iterator i) {
            return ptr != i.ptr;
        }

        void operator++() {
            ++ptr;
        }

        Element operator*() {

            return *ptr;
        }
    };

    iterator begin() {
        return iterator(&data[0]);
    }

    iterator end() {
        return iterator(&data[size]);
    }
    
};

int main()

{

    Map<int, const char*> m;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;

}