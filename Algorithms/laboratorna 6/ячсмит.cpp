#include <iostream>
#include <ctime>
#include <assert.h>
#include <queue>

using namespace std;

template < size_t __SIZE >
class List {
  private:
    int storage[__SIZE];
    int head;
  public:
    List() : head(-1) { }
    void Push(int value) {
        assert(Size() != __SIZE);
        storage[++head] = value;
    }
    int Top() const {
        assert(!Empty());
        return storage[head];
    }
    int Pop() {
        assert(!Empty());
        return storage[head--];
    }
    int Size() const {
        return head + 1;
    }
    bool Empty() const {
        return !Size();
    }

    void max_array() {
        int max = INT_MIN;
        int position = 0;
        for (int i = 0; i < 10; ++i) {
            cout <<  storage[i] << ' ';
            if ( storage[i] > max) {
                max =  storage[i];
                position = i;
            }
        }
        cout << "max element: " << max << " it's position: " << position << endl;
    }

    void min_array() {
        int min = INT_MAX;
        int position = 0;
        for (int i = 0; i < 10; ++i) {
            if ( storage[i] < min) {
                min =  storage[i];
                position = i;
            }
        }
        cout << "min element: " << min << " it's position: " << position << endl;
    }
    ~List() = default;

};
