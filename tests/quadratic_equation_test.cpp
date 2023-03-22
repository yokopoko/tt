#include <gtest/gtest.h>

#include "quadratic_equation.h"

TEST(QuadraticEquationTest, test_1) {
    QuadraticEquation e(3, -4, 94);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 0);
    ASSERT_EQ(e.x(), 2.0/3);
}

TEST(QuadraticEquationTest, test_2) {
    QuadraticEquation e(1, -6, 8);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 2);
    ASSERT_EQ(e.roots()[0], 4);
    ASSERT_EQ(e.roots()[1], 2);
    ASSERT_EQ(e.x(), 3);
}

TEST(QuadraticEquationTest, test_3) {
    QuadraticEquation e(-6, 0, 54);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 2);
    ASSERT_EQ(e.roots()[0], -3);
    ASSERT_EQ(e.roots()[1], 3);
    ASSERT_EQ(e.x(), 0);
}

TEST(QuadraticEquationTest, test_4) {
    QuadraticEquation e(-4, 28, -49);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 1);
    ASSERT_EQ(e.roots()[0], 3.5);
    ASSERT_EQ(e.x(), 3.5);
}

TEST(QuadraticEquationTest, test_5) {
    QuadraticEquation e(8, 0, 5);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 0);
    ASSERT_EQ(e.x(), 0);
}

TEST(QuadraticEquationTest, test_6) {
    QuadraticEquation e(-6, 0, 0);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 1);
    ASSERT_EQ(e.roots()[0], 0);
    ASSERT_EQ(e.x(), 0);
}

TEST(QuadraticEquationTest, test_7) {
    QuadraticEquation e(2, -5, 2);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 2);
    ASSERT_EQ(e.roots()[0], 2);
    ASSERT_EQ(e.roots()[1], 0.5);
    ASSERT_EQ(e.x(), 1.25);
}

TEST(QuadraticEquationTest, test_8) {
    QuadraticEquation e(5, -18, 9);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 2);
    ASSERT_EQ(e.roots()[0], 3);
    ASSERT_EQ(e.roots()[1], 0.6);
    ASSERT_EQ(e.x(), 1.8);
}

TEST(QuadraticEquationTest, test_9) {
    QuadraticEquation e(1, -4, 4);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 1);
    ASSERT_EQ(e.roots()[0], 2);
    ASSERT_EQ(e.x(), 2);
}

TEST(QuadraticEquationTest, test_10) {
    QuadraticEquation e(1, 1, 1);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 0);
    ASSERT_EQ(e.x(), -0.5);
}

TEST(QuadraticEquationTest, test_11) {
    QuadraticEquation e(3, -8, 0);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 2);
    ASSERT_EQ(e.roots()[0], 8.0/3);
    ASSERT_EQ(e.roots()[1], 0);
    ASSERT_EQ(e.x(), 4.0/3);
}

TEST(QuadraticEquationTest, test_12) {
    QuadraticEquation e(5, 0, -125);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 2);
    ASSERT_EQ(e.roots()[0], 5);
    ASSERT_EQ(e.roots()[1], -5);
    ASSERT_EQ(e.x(), 0);
}

TEST(QuadraticEquationTest, test_13) {
    QuadraticEquation e(3, 0, 11);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 0);
    ASSERT_EQ(e.x(), 0);
}

TEST(QuadraticEquationTest, test_14) {
    QuadraticEquation e(0, 4, 8);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 1);
    ASSERT_EQ(e.roots()[0], -2);
}

TEST(QuadraticEquationTest, test_15) {
    QuadraticEquation e(0, 1, 1);
    e.calculate();
    ASSERT_EQ(e.roots().size(), 1);
    ASSERT_EQ(e.roots()[0], -1);
}
