#include <chrono>
#include <iostream>
#include <mutex>

bool constexpr MultiThreaded = true;
bool constexpr SingleThreaded = false;
bool constexpr Threadness = MultiThreaded;

template <bool Threadness> struct Call {
  template <typename callable_t, typename lockable_t>
  static auto inline call(lockable_t &lk, callable_t const &f) -> decltype(f());
};

template <>
template <typename callable_t, typename lockable_t>
auto inline Call<MultiThreaded>::call(lockable_t &lk, callable_t const &f) {
  std::lock_guard<lockable_t> lock(lk);
  return f();
}

template <>
template <typename callable_t, typename lockable_t>
auto inline Call<SingleThreaded>::call(lockable_t &lk, callable_t const &f) {
  return f();
}

int f() { return 0; }

int main() {
  std::mutex lock;

  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < (1 << 30); ++i) {
    f();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                  .count();
  std::cout << "simple:     " << diff << " ms" << std::endl;


  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < (1 << 30); ++i) {
#if Threadness
      std::lock_guard<std::mutex> lk(lock);
      f();
#else
      f();
#endif
  }
  end = std::chrono::high_resolution_clock::now();
  diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
             .count();
  std::cout << "#if:        " << diff << " ms" << std::endl;


  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < (1 << 30); ++i) {
    if (Threadness) {
      std::lock_guard<std::mutex> lk(lock);
      f();
    } else {
      f();
    }
  }
  end = std::chrono::high_resolution_clock::now();
  diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
             .count();
  std::cout << "ifs:        " << diff << " ms" << std::endl;


  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < (1 << 30); ++i) {
    Call<Threadness>::call(lock, f);
  }
  end = std::chrono::high_resolution_clock::now();
  diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
             .count();
  std::cout << "template:   " << diff << " ms" << std::endl;


  return 0;
}
