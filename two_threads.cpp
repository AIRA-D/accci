// Разработайте программу, демонстрирующую создание двух потоков в C++, 
//где один поток пишет данные в переменную, а другой читает из нее, 
//с использованием мьютексов для синхронизации доступа.


#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int sharedData = 0;

void writerThread() {
    for (int i = 0; i < 5; ++i) {
        mtx.lock();
        sharedData = i;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void readerThread() {
    for (int i = 0; i < 5; ++i) {
        mtx.lock();
        std::cout << "Data read by reader: " << sharedData << std::endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    std::thread writer(writerThread);
    std::thread reader(readerThread);

    writer.join();
    reader.join();

    return 0;
}
