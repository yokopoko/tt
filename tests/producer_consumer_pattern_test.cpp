#include <gtest/gtest.h>
#include "producer_consumer_pattern.h"


TEST(ProducerConsumerPattern, test_int) {
    ProducerConsumerPattern<int> pc;

    auto items_generator = [&pc]() {
        pc.producer_add_item(3);
        pc.producer_add_item(4);
        pc.producer_add_item(5);
        pc.producer_add_item(6);
    };

    std::vector<int> result;
    auto consumer_handler = [&result](int v) {
        result.push_back(v);
    };

    pc.run(items_generator, consumer_handler);

    ASSERT_EQ(result.size(), 4);
    ASSERT_EQ(result[0], 3);
    ASSERT_EQ(result[1], 4);
    ASSERT_EQ(result[2], 5);
    ASSERT_EQ(result[3], 6);
}

TEST(ProducerConsumerPattern, test_string) {
    ProducerConsumerPattern<std::string> pc;

    auto items_generator = [&pc]() {
        pc.producer_add_item("string1");
        pc.producer_add_item("string2");
        pc.producer_add_item("string3");
    };

    std::vector<std::string> result;
    auto consumer_handler = [&result](const std::string &str) {
        result.push_back(str);
    };

    pc.run(items_generator, consumer_handler);

    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], "string1");
    ASSERT_EQ(result[1], "string2");
    ASSERT_EQ(result[2], "string3");
}

TEST(ProducerConsumerPattern, test_empty) {
    ProducerConsumerPattern<std::string> pc;

    auto items_generator = [&pc]() {
    };

    std::vector<std::string> result;
    auto consumer_handler = [&result](const std::string &str) {
        result.push_back(str);
    };

    pc.run(items_generator, consumer_handler);

    ASSERT_EQ(result.size(), 0);
}
