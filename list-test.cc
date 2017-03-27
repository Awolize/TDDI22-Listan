
#include "List.h"

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

TEST_CASE( "Test list" )
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

TEST_CASE( "Copy constructor" )
{
    List lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List l{ lst };
    CHECK(l.size() == lst.size());
    CHECK(l.front() == lst.front());
    CHECK(l.back() == lst.back());
}

TEST_CASE( "Doing something #1 constructor (move)" )
{
    List lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List l{std::move(lst)};
    CHECK(l.at(2) == 2);
    CHECK(l.size() == 6);
}

TEST_CASE( "Doing something #2 (move)" )
{
    List lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List l{};
    l = std::move(lst);
    CHECK(l.at(2) == 2);
    CHECK(l.size() == 6);
}




