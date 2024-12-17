#include <chrono>
#include <condition_variable>
#include <ctime>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <thread>

class Test {
 public:
  Test() {}

  void addingElement() {
    while (true) {
      mutex_.lock();

      queue_.push(randomInt());
      std::cout << "adding, left size: " << queue_.size() << std::endl;

      mutex_.unlock();
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
  }

  void deleteElement() {
    while (true) {
      mutex_.lock();

      queue_.pop();
      // std::cout << "deleting, left size: " << queue_.size() << std::endl;

      mutex_.unlock();
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }

  int randomInt() { return int((std::rand() / double(RAND_MAX) + 1.0) * 10); }

  template <typename T>
  std::string print(const std::queue<T>& vec) {
    std::string prints;
    for (const auto& v : vec) {
      prints += std::to_string(v) + ", ";
    }
    prints += "\n";
    return prints;
  }

  void start() {
    std::thread t1(&Test::addingElement, this);
    std::thread t2(&Test::deleteElement, this);
    t1.join();
    t2.join();
  }

 private:
  std::queue<int> queue_;
  std::mutex mutex_;
};

int main() {
  std::srand(std::time(nullptr));
  Test t;
  t.start();
  return 0;
}