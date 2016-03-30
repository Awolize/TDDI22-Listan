
#include "List.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "Create list" )
{
    List lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List l2;
    l2 = lst;
    CHECK(l2.size() == lst.size());
    CHECK(l2.front() == lst.front());
    CHECK(l2.back() == lst.back());
}

