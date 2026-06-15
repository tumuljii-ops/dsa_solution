#include <iostream>
#include <vector>
#include <list>

using namespace std;

class UnorderedSet {

private:

    int bucketCount;
    vector<list<int>> buckets;

    int hashFunction(int key) {
        return key % bucketCount;
    }

public:

    UnorderedSet() {
        bucketCount = 10;
        buckets.resize(bucketCount);
    }

    void insert(int key) {

        int idx = hashFunction(key);

        // avoid duplicates
        for(int x : buckets[idx]) {
            if(x == key)
                return;
        }

        buckets[idx].push_back(key);
    }

    bool find(int key) {

        int idx = hashFunction(key);

        for(int x : buckets[idx]) {
            if(x == key)
                return true;
        }

        return false;
    }

    void erase(int key) {

        int idx = hashFunction(key);

        auto &lst = buckets[idx];

        for(auto it = lst.begin(); it != lst.end(); it++) {

            if(*it == key) {
                lst.erase(it);
                return;
            }
        }
    }

    void display() {

        for(int i=0;i<bucketCount;i++) {

            cout << "Bucket " << i << " : ";

            for(int x : buckets[i]) {
                cout << x << " ";
            }

            cout << endl;
        }
    }
};

int main() {

    UnorderedSet st;

    st.insert(25);
    st.insert(35);
    st.insert(45);
    st.insert(12);

    st.display();

    cout << "\n";

    cout << st.find(35) << endl;
    cout << st.find(100) << endl;

    st.erase(35);

    cout << "\nAfter deleting 35:\n";

    st.display();
}