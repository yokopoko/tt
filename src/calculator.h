#pragma once

#include "producer_consumer_pattern.h"
#include "quadratic_equation.h"
#include <iostream>
#include <string>
#include <memory>


class Calculator {
    struct Args {
        int a;
        int b;
        int c;
    };

    static bool parse_string(const char *str, int *out_value) {
            try {
                *out_value = std::stoi(str);
                return true;
            } catch(std::invalid_argument const& ex) {
                std::cerr << "std::invalid_argument::what(): " << ex.what() << std::endl;
            } catch(std::out_of_range const& ex) {
                std::cerr << "std::out_of_range::what(): " << ex.what() << std::endl;
            }
            return false;
    }

    static bool parse_args(int argc, const char *argv[], std::vector<Args> *args_out) {
        if ((argc % 3) != 0) {
            std::cerr << "Incorrect numbers of arguments: " << argc << std::endl;
            return false;
        }
        for (int i = 0; i < argc; ++i) {
            int a {};
            int b {};
            int c {};
            if (!parse_string(argv[i++], &a) || !parse_string(argv[i++], &b) || !parse_string(argv[i], &c)) {
                return false;
            }
            args_out->push_back({a, b, c});
        }
        return true;
    }

public:
    static int run(int argc, const char *argv[]) {
        std::vector<Args> input_args;
        if (!parse_args(argc, argv, &input_args)) {
            std::cerr << "cannot parse input arguments" << std::endl;
            return -1;
        }

        ProducerConsumerPattern<std::unique_ptr<QuadraticEquation>> pc;
        auto items_generator = [&pc, &input_args]() {
            for (auto arg : input_args) {
                auto qe = std::make_unique<QuadraticEquation>(arg.a, arg.b, arg.c);
                pc.producer_add_item(std::move(qe));
            }
        };

        std::vector<std::string> result;
        auto consumer_handler = [&result](std::unique_ptr<QuadraticEquation> qe) {
            qe->calculate();
            show_result(std::cout, *qe);
        };

        pc.run(items_generator, consumer_handler);
        return 0;
    }

private:
    static void show_x(std::ostream &stream, const QuadraticEquation &eq) {
        if (eq.a() > 0) {
            stream << "Xmin=" << eq.x();
        } else if (eq.a() == 0) {
            stream << "no extremum";
        } else {
            stream << "Xmax=" << eq.x();
        }
    }

    static void show_result(std::ostream &stream, const QuadraticEquation &eq) {
        auto roots = eq.roots();
        stream << "(" << eq.a() << " " << eq.b() << " " << eq.c() << ") => ";

        if (roots.empty()) {
            stream << "no roots ";
        } else if (roots.size() == 1) {
            stream << "(" << roots[0] << ") ";
        } else if (roots.size() == 2) {
            stream << "("<< roots[0] << ", " << roots[1] << ") ";
        }
        show_x(stream, eq);
        stream << std::endl;
    }
};
