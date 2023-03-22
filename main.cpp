#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Equation {
    public:
        Equation(int a, int b, int c): a_(a), b_(b), c_(c) {}

        Equation(const Equation& ex): a_(ex.a_), b_(ex.b_), c_(ex.c_), x_min_(ex.x_min_) {
            for (double x: ex.roots_) {
                roots_.push_back(x);
            }
        }

        void findRoots() {
            if(a_ == 0) {
                double x = -c_ / b_;
                roots_.push_back(x);
                return;
            }

            double discriminant = b_ * b_ - 4 * a_ * c_;
            if(discriminant > 0) {
                double x1 = (-b_ + sqrt(discriminant)) / (2*a_);
                double x2 = (-b_ - sqrt(discriminant)) / (2*a_);
                roots_.push_back(x1);
                roots_.push_back(x2);
                //eq.roots = "(" + std::to_string(x1) + ", " + std::to_string(x2) + ")";
            } else if(discriminant == 0) {
                double x =  -b_ / (2 * a_);
                roots_.push_back(x);
                //roots = "(" + std::to_string(x) + ")";
            }
        }

        void findExtremum() {
            //"a" is positive, so the parabola opens upward
            // if the parabola opens upward, you will be finding its minimum value
            if(a_ > 0) {
                x_min_ = -b_/2*a_;
            }
        }

        friend std::ostream &operator<<(std::ostream &output, const Equation &eq) {
            if(eq.roots_.size() > 1) {
                output << "(" << eq.a_ << " " << eq.b_ << " " << eq.c_ << ") => (" << eq.roots_[0] << "," << eq.roots_[1] << ") Xmin=" << eq.x_min_;
            } else if (eq.roots_.empty()){
                output << "no roots => (" << eq.roots_[0] << ") Xmin=" << eq.x_min_;
            } else {
                output << "(" << eq.a_ << " " << eq.b_ << " " << eq.c_ << ") => (" << eq.roots_[0] << ") Xmin=" << eq.x_min_;
            }

            return output;
        }

    private:
        int a_;
        int b_;
        int c_;

        std::vector<double> roots_;
        double x_min_;
};

int getNum(std::string str) {
    int res = 0, base = 10;
    int i = 0;
    bool isNegative = false;
    if(str[0] == '-') {
        isNegative = true;
        i++;
    }
    while(i < str.size()) {
        //std::cout << str[i];
        if(str[i] >= '0' && str[i] <= '9'){
            res = res * base + (str[i] - '0');
        } else {
            std::cout << "invalid input" << std::endl;
            exit(0);
        }
        i++;
    }
    return isNegative? -res : res;
}

int main() {
    std::string nums, str;
    std::cout << "Enter numbers:" << std::endl;
    //getline(std::cin, nums);
    // std::cout << nums<< std::endl;
    //std::stringstream ss(nums);
    // std::vector<int> v;
    //  std::vector<std::string> outputs;
    // while (std::getline(std::cin, str, ' ')) {
    //     // Add to the list of output strings
    //     outputs.push_back(str);
    // }
    // for (const auto& i : outputs)
    //     std::cout << i << std::endl;
    // while (std::getline(std::cin, nums, ' ')) {
    //     std::cout << "input" << std::endl;
    //     std::cout << str << std::endl;
    //     int k = getNum(str);
    //     std::cout << k << std::endl;
    //     std::cout << "add" << std::endl;
    //     v.push_back(k);
    // }
    Equation e(1, -2, -3);
    e.findRoots();
    e.findExtremum();
    std::cout << e<< std::endl;

    return 0;
}
