#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;// 排他制御のために鍵をかける
std::condition_variable cv;
int current_thread = 1;

void print_thread_id(int id) {

    std::unique_lock<std::mutex> lock(mtx);

    // 条件が満たされるまで待機
    cv.wait(lock, [id] { return current_thread == id; });

    // 表示処理
    std::cout << "thread " << id << std::endl;

    // 次の番号へ
    current_thread++;
    cv.notify_all();
}

int main() {
    std::thread t1(print_thread_id, 1);
    std::thread t2(print_thread_id, 2);
    std::thread t3(print_thread_id, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}