#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>

#include <iostream>
#include <string>

struct Tag1;
struct Tag2;
struct Tag3;

using container_t = boost::multi_index_container<
    std::string,
    boost::multi_index::indexed_by<
        boost::multi_index::sequenced<
            boost::multi_index::tag<Tag1>
        >,
        boost::multi_index::hashed_unique<
            boost::multi_index::tag<Tag2>,
            boost::multi_index::identity<std::string>
        >,
        boost::multi_index::ordered_unique<
            boost::multi_index::tag<Tag3>,
            boost::multi_index::identity<std::string>
        >
    >
>;

int main() {
    container_t c;
    c.push_back("foo");
    c.push_back("bar");
    for (auto i : c) {
        std::cout << i << std::endl;
    }
    for (auto i : c.get<2>()) {
        std::cout << i << std::endl;
    }
}
