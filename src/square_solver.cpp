#include "calculator.h"

int main(int argc, const char *argv[])
{
    return Calculator::run(--argc, ++argv);
}
