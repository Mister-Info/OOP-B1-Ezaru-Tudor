#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<exception>
#include<string>
#define _CRT_SECURE_NO_WARNINGS

template<typename T>
class MyVector {

	int capacity;
	int Size;
	T* v;

public:
	MyVector() : capacity(1), Size(0), v(new T[capacity]) {}

	~MyVector() {
		delete[] v;
	}

	static int compare(T x, T y) {
		if (x < y)
			return -1;
		if (y < x)
			return 1;
		return 0;
	}
	void sort() {
		for (int i = 0; i < Size - 1; ++i) {
			for (int j = i + 1; j < Size; ++j) {
				if (v[i]>v[j]) {
					std::swap(v[i], v[j]);
				}
			}
		}
	}

	void add(T value) {
		if (Size == capacity) {
			capacity *= 2;
			T* v2 = new T[capacity];
			for (int i = 0; i < Size; i++) {
				v2[i] = v[i];
			}
			delete[] v;
			v = v2;
		}
		v[Size++] = value;
	}

    int size() {
        return Size;
    }


	void remove(int index) {
		if (index<0 || index>Size) {
			printf("Eroare la remove");
			return;
		}
		for (int i = index; i < Size - 1; i++) {
			v[i] = v[i + 1];
		}
		Size--;
	}


    T& operator [](int index) {
        return v[index];
    }
    
    bool operator==(const MyVector<T>& x) {
        if (Size != x.Size)
            return false;

        for (int i = 0; i < Size; i++) {
            if (v[i] != x.v[i])
                return false;
        }
        return true;
    }


    void print() {

		for (int i = 0; i < Size; ++i) {
			std::cout << v[i] << ' ';
		}
		printf("\n");
	}

};

class Tester {
    // Takes a function; if this function returns false, or throws an exception, the test fails

private:
    struct TestResult {
        const char* name;
        bool passed;
    };

    std::vector<TestResult> results;
public:
    void Add(bool (*test)(), const char* name) {
        TestResult result{ name,false };
        try {
            result.passed = test();
        }
        catch (const std::exception&) {
            result.passed = false;
        }
        results.push_back(result);
    }
    void Run() {
        int passed = 0;
        int total = results.size();

        for (const auto& result : results) {
            if (result.passed) {
                std::cout << result.name << " (OK)" << std::endl;
                passed++;
            }
            else {
                std::cout << result.name << " (FAILED)" << std::endl;
            }
        }
        std::cout << std::endl;
        std::cout << "Tests passed: " << passed << "/" << total << " (" << (passed * 100 / total) << "%)" << std::endl;
    }
};

int main() {
    Tester t;

    t.Add([]() {
        MyVector<int> x;
    x.add(5);
    return x[0] == 5;
        }, "Insert test");

    t.Add(
        []() {
            MyVector<int> x;
    x.add(5);
    x.add(10);
    x.remove(0);

    return x[0] == 10;
        },
        "Remove test");

    t.Add(
        []() {
            MyVector<int> x;

    for (int i = 0; i < 5; ++i) {
        x.add(i);
    }

    return x.size() == 5;
        },
        "Size test");

    t.Add(
        []() {
            MyVector<int> x;
    MyVector<int> y;

    for (int i = 0; i < 5; ++i) {
        x.add(i);
        y.add(i);
    }
    return x == y;
        },
        "Equal test");

    t.Add(
        []() {
            MyVector<int> x;
    x.add(4);
    x.add(2);
    x.add(3);
    x.add(0);
    x.add(1);

    x.sort();

    for (int i = 0; i < 5; ++i) {
        if (x[i] != i) {
            return false;
        }
    }

    return true;
        },
        "Sort test");

    t.Add([]() -> bool { throw std::runtime_error("Fail"); }, "Fail on purpose");

    t.Run();
    
    return 0;
}