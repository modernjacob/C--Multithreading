#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
// global mutex
mutex mtx;

// count down function
void count_down() {
    lock_guard<mutex> lock(mtx);
    for (int i = 100; i >= 0; i--) {
        cout << i << ' ';
    }
    cout << endl << endl;
}

// count up function
void count_up() {
    lock_guard<mutex> lock(mtx);
    for (int i = 0; i <= 100; i++) {
        cout << i << ' ';
    }
}

int main() {

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();

    //thread one runs count_down
    cout << "Thread one: ";
    thread thread_one(count_down);
    thread_one.join();

    //thread two runs count_up
    cout << "Thread two: ";
    thread thread_two(count_up);
    thread_two.join();

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout << "Elapsed time in nanoseconds: " << elapsed.count() << " ns" << endl;

    return 0;
}