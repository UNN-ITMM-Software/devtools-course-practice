// Copyright 2021 Tkachev Alexey

#include <gtest/gtest.h>
#include <string>

#include "include/queue.h"

TEST(queue_test, no_exception_during_crearing) {
    ASSERT_NO_THROW(new Queue());
}

TEST(queue_test, get_first_exception) {
    Queue *testing_queue = new Queue();

    ASSERT_ANY_THROW(testing_queue->getFirstData());
}

TEST(queue_test, no_throw_destructor) {
    Queue *testing_queue = new Queue();

    ASSERT_NO_THROW(testing_queue->~Queue());
}

TEST(queue_test, throw_remove_first) {
    Queue *testing_queue = new Queue();

    ASSERT_ANY_THROW(testing_queue->removeFirst());
}

TEST(queue_test, queue_equals_itself) {
    Queue *testing_queue = new Queue();

    ASSERT_NO_THROW(*testing_queue = *testing_queue);
}

TEST(queue_test, empty_queues_equal) {
    Queue *testing_queue_1 = new Queue();
    Queue *testing_queue_2 = new Queue();

    *testing_queue_1 = *testing_queue_2;

    const std::string str_data_queue_1 = testing_queue_1->toStringData();
    const std::string str_data_queue_2 = testing_queue_2->toStringData();

    ASSERT_EQ(true, str_data_queue_1 == str_data_queue_2);
}

TEST(queue_test, not_empty_equals_empty) {
    Queue *testing_queue_1 = new Queue();
    Queue *testing_queue_2 = new Queue();
    const double value_1 = 5.2;
    const double value_2 = 3.2;

    testing_queue_1->append(value_1);
    testing_queue_1->append(value_2);

    const std::string str_data_queue_1 = testing_queue_1->toStringData();
    const std::string str_data_queue_2 = testing_queue_2->toStringData();

    ASSERT_EQ(false, str_data_queue_1 == str_data_queue_2);
}

TEST(queue_test, is_empty_true) {
    Queue * testing_queue = new Queue();

    ASSERT_EQ(true, testing_queue->isEmpty());
}

TEST(queue_test, is_empty_false) {
    Queue* testing_queue = new Queue();
    const double value = 25.5;

    testing_queue->append(value);

    ASSERT_EQ(false, testing_queue->isEmpty());
}

TEST(queue_test, get_append_expection) {
    Queue* testing_queue = new Queue();
    const double number_to_add = 2.5;

    ASSERT_NO_THROW(testing_queue->append(number_to_add));
}

TEST(queue_test, get_last_expection) {
    Queue* testing_queue = new Queue();

    ASSERT_ANY_THROW(testing_queue->getLastData());
}

TEST(queue_test, copy_constructor_equal) {
    Queue* testing_queue_1 = new Queue();

    for (size_t i = 0; i < 10; i++) {
        testing_queue_1->append(static_cast<double>(i));
    }

    Queue* testing_queue_2 = new Queue(*testing_queue_1);

    const std::string str_data_queue_1 = testing_queue_1->toStringData();
    const std::string str_data_queue_2 = testing_queue_2->toStringData();

    ASSERT_EQ(true, str_data_queue_1 == str_data_queue_2);
}

TEST(queue_test, comparing_two_big_queues_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    for (size_t i = 0; i < 10; i++) {
        testing_queue_1->append(static_cast<double>(i));
    }

    for (size_t i = 0; i < 10; i++) {
        testing_queue_2->append(static_cast<double>(i));
    }

    const std::string str_data_queue_1 = testing_queue_1->toStringData();
    const std::string str_data_queue_2 = testing_queue_2->toStringData();

    ASSERT_EQ(true, str_data_queue_1 == str_data_queue_2);
}

TEST(queue_test, comparing_two_big_queues_not_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    for (size_t i = 0; i < 100; i++) {
        testing_queue_1->append(static_cast<double>(i));
    }

    for (size_t i = 0; i < 100; i++) {
        testing_queue_2->append(static_cast<double>(i));
    }

    for (size_t i = 0; i < 10; i++) {
        testing_queue_1->removeFirst();
    }

    const std::string str_data_queue_1 = testing_queue_1->toStringData();
    const std::string str_data_queue_2 = testing_queue_2->toStringData();

    ASSERT_EQ(false, str_data_queue_1 == str_data_queue_2);
}

TEST(queue_test, comparing_get_first_two_queues) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    testing_queue_1->append(1.2);
    testing_queue_2->append(1.2);

    testing_queue_1->append(2.0);
    testing_queue_2->append(3.2);

    testing_queue_1->append(9.5);
    testing_queue_2->append(53.1);

    const double get_first_queue_1 = testing_queue_1->getFirstData();
    const double get_first_queue_2 = testing_queue_2->getFirstData();

    ASSERT_EQ(get_first_queue_1, get_first_queue_2);
}

TEST(queue_test, remove_first_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    testing_queue_1->append(2.5);
    testing_queue_1->append(3.5);
    testing_queue_1->append(4.5);
    testing_queue_1->append(5.5);

    testing_queue_1->removeFirst();
    testing_queue_1->removeFirst();

    testing_queue_2->append(4.5);
    testing_queue_2->append(5.5);

    const std::string str_data_queue_1 = testing_queue_1->toStringData();
    const std::string str_data_queue_2 = testing_queue_2->toStringData();

    ASSERT_EQ(true, str_data_queue_1 == str_data_queue_2);
}

TEST(queue_test, remove_get_last_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    testing_queue_1->append(2.0);
    testing_queue_1->append(4.4);

    testing_queue_2->append(4.0);
    testing_queue_2->append(4.4);

    const double last_1 = testing_queue_1->getLastData();
    const double last_2 = testing_queue_2->getLastData();

    ASSERT_EQ(last_1, last_2);
}

TEST(queue_test, get_size_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    double number_to_append;

    for (size_t i = 0; i < 100; i++) {
        number_to_append = i;
        testing_queue_1->append(static_cast<double>(number_to_append));
    }

    for (size_t i = 0; i < 100; i++) {
        number_to_append = i * 2 + 5;
        testing_queue_2->append(static_cast<double>(number_to_append));
    }

    const unsigned int size_1 = testing_queue_1->getSize();
    const unsigned int size_2 = testing_queue_2->getSize();

    ASSERT_EQ(true, size_1 == size_2);
}

TEST(queue_test, get_size_not_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    double number_to_append;

    for (size_t i = 0; i < 200; i++) {
        number_to_append = i;
        testing_queue_1->append(static_cast<double>(number_to_append));
    }

    for (size_t i = 0; i < 250; i++) {
        number_to_append = i;
        testing_queue_2->append(static_cast<double>(number_to_append));
    }

    const unsigned int size_1 = testing_queue_1->getSize();
    const unsigned int size_2 = testing_queue_2->getSize();

    ASSERT_EQ(false, size_1  == size_2);
}

TEST(queue_test, to_string_equal) {
    Queue* testing_queue_1 = new Queue();

    for (size_t i = 0; i < 300; i++) {
        testing_queue_1->append(static_cast<double>(i));
    }

    Queue* testing_queue_2(testing_queue_1);

    const std::string str_queue_1 = testing_queue_1->toStringData();
    const std::string str_queue_2 = testing_queue_2->toStringData();

    ASSERT_EQ(true, str_queue_1 == str_queue_2);
}

TEST(queue_test, not_empty_equals_not_empty_CRASH_TEST) {
    Queue *testing_queue_1 = new Queue();
    Queue *testing_queue_2 = new Queue();
    const double value_1 = 2.5;
    const double value_2 = 3.5;
    const double value_3 = 35.1;
    const double value_4 = 29.99;

    testing_queue_1->append(value_1);
    testing_queue_1->append(value_2);

    testing_queue_2->append(value_3);
    testing_queue_2->append(value_4);

    for (size_t i = 0; i < 100; i++) {
        *testing_queue_1 = *testing_queue_2;
        *testing_queue_1 = *testing_queue_2;
        *testing_queue_2 = *testing_queue_1;
        *testing_queue_2 = *testing_queue_1;
    }

    ASSERT_NO_THROW(*testing_queue_1 = *testing_queue_2;);
}
