#ifndef PP_THREADPOOL_H_
#define PP_THREADPOOL_H_

#include <array>
#include <thread>
#include <shared_mutex>
#include <barrier>
#include <condition_variable>

class ThreadPool
{
public:
    ThreadPool();

private:
    std::array<std::thread, 16> m_Threads;
    std::shared_mutex m_Mtx;
    std::condition_variable_any m_Cv;
    bool s_WorkFinished = false;
};

#endif // PP_THREADPOOL_H_