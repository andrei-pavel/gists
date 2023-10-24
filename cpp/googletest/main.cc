#include <boost/shared_ptr.hpp>
#include <gtest/gtest.h>

void foo() {
    boost::shared_ptr<int> bar;
    ASSERT_TRUE(bar);
}

int main() {
    return 0;
}
