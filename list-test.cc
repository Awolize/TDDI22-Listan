
#include "List.h"

#include "catch.hpp"


TEST_CASE( "Create list" )
{
    {
    List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List<int> l2;
    l2 = lst;
    CHECK(l2.size() == lst.size());
    CHECK(l2.front() == lst.front());
    CHECK(l2.back() == lst.back());
    }
}

TEST_CASE( "Test list" )
{
    List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List<int> l2;
    l2 = lst;
    CHECK(l2.size() == lst.size());
    CHECK(l2.front() == lst.front());
    CHECK(l2.back() == lst.back());
}

TEST_CASE( "Copy constructor" )
{
    List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List<int> l{ lst };
    CHECK(l.size() == lst.size());
    CHECK(l.front() == lst.front());
    CHECK(l.back() == lst.back());
}

TEST_CASE( "Doing something #1 constructor (move)" )
{
    List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List<int> l{std::move(lst)};
    CHECK(l.at(2) == 2);
    CHECK(l.size() == 6);
}

TEST_CASE( "Doing something #2 (move)" )
{
    List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List<int> l{};
    l = std::move(lst);
    CHECK(l.at(2) == 2);
    CHECK(l.size() == 6);
}

TEST_CASE( "Iterator Test" )
{
    List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6); 
}



