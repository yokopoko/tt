#pragma once

#include <mutex>
#include <queue>
#include <atomic>
#include <condition_variable>
#include <thread>


template <typename Item>
class ProducerConsumerPattern {
public:
    void producer_add_item(Item &&item) {
        {
            std::unique_lock<std::mutex> lock(m_);
            queue_.push(std::move(item));
        }
        cv_.notify_one();
    }

    template <typename ItemsGenerator, typename ItemHandler>
    void run(ItemsGenerator items_generator, ItemHandler handler) {
        std::thread consumer_thread(
            &ProducerConsumerPattern<Item>::consumer_thread_fn<ItemHandler>,
            this,
            handler
        );
        std::thread producer_thread(
            &ProducerConsumerPattern<Item>::producer_thread_fn<ItemsGenerator>,
            this,
            items_generator
        );

        producer_thread.join();
        consumer_thread.join();
    }

private:
    template <typename ItemsGenerator>
    void producer_thread_fn(ItemsGenerator items_generator) {
        items_generator();
        finished_ = true;
        cv_.notify_one();
    }

    template <typename ItemHandler>
    void consumer_thread_fn(ItemHandler handler) {
        do {
            std::unique_lock<std::mutex> lock(m_);
            while (!finished_ && queue_.empty()) {
                // predicate an while loop - protection from spurious wakeups
                cv_.wait(lock, [&]() {
                    return !queue_.empty() || finished_;
                });
            }

            // consume all elements from queue
            while(!queue_.empty()) {
                handler(std::move(queue_.front()));
                queue_.pop();
            }
        } while(!finished_);
    }

    std::queue<Item> queue_;
    std::mutex m_;
    std::condition_variable cv_;
    std::atomic_bool finished_ {false};
};
