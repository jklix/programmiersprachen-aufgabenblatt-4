#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "List.hpp"

//Aufgabe 4.2

TEST_CASE("size", "[listSize]")
{
    List <int> l1;
    List <int> l2;

    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);

    REQUIRE(l1.size() == 0);
    REQUIRE(l2.size() == 3);

    l2.pop_back();
    REQUIRE (l2.size() == 2);

    l2.pop_front();
    REQUIRE (l2.size() == 1);
}

TEST_CASE("empty", "[list_empty]")
{
    List <int> l1;
    List <int> l2;

    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);

    REQUIRE(l1.empty() == true);
    REQUIRE(l2.empty() == false);
}


// Aufgabe 4.3

TEST_CASE("push_front", "[list_push_front]")
{
    List <int> l1;
    l1.push_front(5);
    l1.push_front(2);

    REQUIRE(2 == l1.front());
}

TEST_CASE("push_back", "[list_push_back]")
{
    List <int> l1;
    l1.push_back(2);
    l1.push_back(6);

    REQUIRE(6 == l1.last());
}

TEST_CASE("pop_front", "[list_pop_front]")
{
    List <int> l1;
    l1.push_back(2);
    l1.push_back(6);
    l1.push_back(8);

    l1.pop_front();

    REQUIRE(6 == l1.front());

    REQUIRE(l1.empty() == false);
    l1.pop_front();
    l1.pop_front();
    REQUIRE(l1.empty() == true);

}

TEST_CASE("pop_back", "[list_pop_back]")
{
    List <int> l1;
    l1.push_back(2);
    l1.push_back(6);
    l1.push_back(8);

    l1.pop_back();

    REQUIRE(6 == l1.last());
}

// Aufgabe 4.4

TEST_CASE("should be empty after clearing", "[modifiers]")
{
    List <int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    list.clear();
    REQUIRE(list.empty() == true);
}

//Aufgabe 4.6
TEST_CASE("should be an empty range after default construction", "[iterators]")
{
    List <int> list;
    auto b = list.begin();
    auto e = list.end();

    REQUIRE(b == e);
}

TEST_CASE("provide acces to the first element with begin", "[iterators]")
{
    List <int> list;
    list.push_front(42);

    REQUIRE(42 == *list.begin());
}

//Aufgabe 4.8
TEST_CASE("copy constructor", "[constructor]")
{
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    List<int> list2{list};
    REQUIRE(list == list2);
}

//Aufgabe 4.10
TEST_CASE("reverse_list", "[list]")
{
    List <int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    REQUIRE(l.front() == 1);
    l.reverse();
    REQUIRE(l.front() == 4);

    List<int> l2 = reverse(l);
    REQUIRE(l2.front() == 1);
}


int main (int argc, char *argv[])
{
    return Catch::Session().run(argc, argv);
}

