#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex outputMutex;

void countNumbers(string threadName, int start, int end) {

    for (int i = start; i <= end; i++) {

        lock_guard<mutex> lock(outputMutex);

        cout << threadName
             << " -> "
             << i
             << endl;
    }
}

int main() {

    cout << "Starting multithreaded application..." << endl;

    thread thread1(countNumbers, "Thread 1", 1, 5);
    thread thread2(countNumbers, "Thread 2", 6, 10);

    thread1.join();
    thread2.join();

    cout << "All threads finished." << endl;

    return 0;
}