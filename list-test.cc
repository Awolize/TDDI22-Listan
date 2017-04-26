
#include "List.h"

#include "catch.hpp"


TEST_CASE( "Create list" )
{
    List_NS::List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List_NS::List<int> l2;
    l2 = lst;
    CHECK(l2.size() == lst.size());
    CHECK(l2.front() == lst.front());
    CHECK(l2.back() == lst.back());
}

TEST_CASE( "Test list" )
{
    List_NS::List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List_NS::List<int> l2;
    l2 = lst;
    CHECK(l2.size() == lst.size());
    CHECK(l2.front() == lst.front());
    CHECK(l2.back() == lst.back());
}
TEST_CASE( "Copy constructor" )
{
    List_NS::List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List_NS::List<int> l{ lst };
    CHECK(l.size() == lst.size());
    CHECK(l.front() == lst.front());
    CHECK(l.back() == lst.back());
}

TEST_CASE( "Doing something #1 constructor (move)" )
{
    List_NS::List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List_NS::List<int> l{std::move(lst)};
    CHECK(l.at(2) == 2);
    CHECK(l.size() == 6);
}

TEST_CASE( "Doing something #2 (move)" )
{
    List_NS::List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List_NS::List<int> l{};
    l = std::move(lst);
    CHECK(l.at(2) == 2);
    CHECK(l.size() == 6);
}

TEST_CASE( "Iterator Test" )
{
    List_NS::List<int> lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6); 
}

TEST_CASE( "PUSH_BACK_FRONT")
{
    List_NS::List <int>lst{1,4,2,6};
    lst.push_front(3);
    CHECK(lst.at(0) == 3);
    lst.push_back(22);
    CHECK(lst.at(5) == 22);
    List_NS::List <int>l2{3,2,1};
    l2.swap(lst);
    CHECK(l2.front() == 3);
    CHECK(l2.back() == 22);
    List_NS::List <int>l3 = List_NS::List<int>{2,4,5};
    CHECK(l3.front() == 2);
    CHECK(l3.back() == 5);
}

TEST_CASE("Iterator Reverse pre dec")
{
    List_NS::List <int>lst{1,3,2,5,2};
    auto rb {std::make_reverse_iterator(lst.end())};
    auto re {std::make_reverse_iterator(lst.begin())};
    
    int i{4};
    for( auto it {rb}; it != re; ++it )
    {
	CHECK(*it == lst.at(i));
	--i;
    }
}

TEST_CASE("Iterator pre inc")
{
    List_NS::List <int>lst{1,3,2,5,2};
    auto rb {lst.end()};
    auto re {lst.begin()};
    
    int i{0};
    for( auto it {re}; it != rb; ++it )
    {
	CHECK(*it == lst.at(i));
	++i;
    }
}

TEST_CASE("Iterator Reverse post inc")
{
    List_NS::List <int>lst{1,3,2,5,2};
    auto rb {lst.end()};
    auto re {lst.begin()};
    
    int i{0};
    for( auto it {re}; it != rb; ++it )
    {
	CHECK(*it == lst.at(i));
	i++;
    }
}

TEST_CASE("Iterator Reverse post dec")
{
    List_NS::List <int>lst{1,3,2,5,2};
    auto rb {std::make_reverse_iterator(lst.end())};
    auto re {std::make_reverse_iterator(lst.begin())};
    
    int i{4};
    for( auto it {rb}; it != re; ++it )
    {
	CHECK(*it == lst.at(i));
	i--;
    }
}

TEST_CASE("Iterator ==")
{
    List_NS::List <int>lst{1,3,2,5,2};
    auto rb {lst.end()};
    auto re {lst.begin()};
    
    auto it {re};
    auto it2 {re};

    CHECK(*it == *it2);
}

TEST_CASE("Iterator !=")
{
    List_NS::List <int>lst{1,3,2,5,2};
    auto rb {lst.end()};

    auto it {rb};
    auto it2 {rb};

    CHECK_FALSE(*it != *it2);
}

TEST_CASE("Iterator ->")
{
    List_NS::List<std::string> str {".", "?", "!"};
    auto it = str.begin();
    CHECK(*it == ".");
    CHECK(str.size() == 3);
    it++;
    CHECK(*it != ".");
}

TEST_CASE("Iterator const pre-increment")
{
    const List_NS::List<int> l{1,2,3};
    auto it{l.begin()};
    auto it2{it};
    CHECK(*it == 1);
    CHECK(*it2 == 1);
    CHECK(it != l.end());

    it2 = ++it;
    CHECK(*it == 2);
    CHECK(*it2 == 2);

    it2 = ++it;
    CHECK(*it == 3);
    CHECK(*it2 == 3);

    it2 = ++it;
    CHECK(it == l.end());
    CHECK(it == l.end());
    CHECK(it != l.begin());
}

TEST_CASE( "creat strings test first" )
{
  List_NS::List<std::string> lst{"hej", "wops"};
  REQUIRE(lst.at(0) == "hej");
  REQUIRE(lst.size() == 2);
}


class List
{
};


TEST_CASE("Namespace")
{
    List l;
    List_NS::List<int> l2;
}


