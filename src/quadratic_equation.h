#pragma once

#include <vector>
#include <cmath>

class QuadraticEquation {
public:
    QuadraticEquation(int a, int b, int c): a_(a), b_(b), c_(c) {}
    QuadraticEquation(const QuadraticEquation &) = delete;
    QuadraticEquation& operator=(const QuadraticEquation &) = delete;
    QuadraticEquation(QuadraticEquation &&) = delete;
    QuadraticEquation& operator=(QuadraticEquation &&) = delete;
    ~QuadraticEquation() = default;


    void calculate() {
        find_roots();
        find_extremum();
    }

    double a() const {
        return a_;
    }

    double b() const {
        return b_;
    }

    double c() const {
        return c_;
    }

    double x() const {
        return x_;
    }

    const std::vector<double> &roots() const {
        return roots_;
    }

private:
    void find_roots() {
        if(a_ == 0) {
            double x = -c_ / b_;
            roots_.push_back(x);
            return;
        }

        double discriminant = b_*b_ - 4*a_ * c_;
        if(discriminant > 0) {
            double x1 = (-b_ + std::sqrt(discriminant)) / (2*a_);
            double x2 = (-b_ - std::sqrt(discriminant)) / (2*a_);
            roots_.push_back(x1);
            roots_.push_back(x2);
        } else if(discriminant == 0) {
            double x = -b_ / (2*a_);
            roots_.push_back(x);
        }
    }

    void find_extremum() {
        //"a" is positive, so the parabola opens upward
        // if the parabola opens upward, you will be finding its minimum value
        if (a_ != 0) {
            x_ = -b_ / 2*a_;
        }
    }

    double a_;
    double b_;
    double c_;
    double x_{};
    std::vector<double> roots_;
};
