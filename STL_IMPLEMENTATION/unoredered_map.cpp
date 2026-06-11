#include <iostream>
#include <vector>
#include <list>

using namespace std;

class UnorderedMap {

private:
    int bucketCount;
    vector<list<pair<int,int>>> buckets;

    int hashFunction(int key) {
        return key % bucketCount;
    }

public:

    UnorderedMap() {
        bucketCount = 10;
        buckets.resize(bucketCount);
    }

    void put(int key, int value) {

        int idx = hashFunction(key);

        // Update if key already exists
        for(auto &p : buckets[idx]) {
            if(p.first == key) {
                p.second = value;
                return;
            }
        }

        buckets[idx].push_back({key, value});
    }

    int get(int key) {

        int idx = hashFunction(key);

        for(auto &p : buckets[idx]) {
            if(p.first == key)
                return p.second;
        }

        return -1;
    }

    void remove(int key) {

        int idx = hashFunction(key);

        auto &lst = buckets[idx];

        for(auto it = lst.begin(); it != lst.end(); it++) {

            if(it->first == key) {
                lst.erase(it);
                return;
            }
        }
    }

    void display() {

        cout << "Hash Table:\n";

        for(int i = 0; i < bucketCount; i++) {

            cout << "Bucket " << i << " : ";

            for(auto &p : buckets[i]) {
                cout << "(" << p.first << "," << p.second << ") ";
            }

            cout << "\n";
        }
    }
};

int main() {

    UnorderedMap mp;

    mp.put(25, 100);
    mp.put(35, 200);
    mp.put(45, 300);
    mp.put(12, 400);
    mp.put(22, 500);

    mp.display();

    cout << "\n";

    cout << "Value of key 25 = "
         << mp.get(25) << endl;

    cout << "Value of key 12 = "
         << mp.get(12) << endl;

    cout << "Value of key 99 = "
         << mp.get(99) << endl;

    cout << "\nRemoving key 35...\n";

    mp.remove(35);

    mp.display();

    return 0;
}