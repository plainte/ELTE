//
// Created by molna on 2020. 03. 06..
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Set.h"
#include <array>

TEST_CASE("Testing input form files", "[InputTesting]")
{
  using Set = mySpace::Set;
  Set s{};
  SECTION("testing first input file") {
    std::ifstream in;
    auto e = 0;
    in.open("../../input1.txt");
    if (!in) {
      std::cout << "Unable to open file input1.txt\n";
      exit(1);
    }
    auto size = 0;
    std::optional<int> max = 0;
    auto counter = 0;
    std::array<int, 5> pb{};
    std::array<int, 4> er{};
    while (in >> e) {
      if (counter < 5) {
        pb[counter] = e;
      } else {
        er[counter - 5] = e;
      }
      ++counter;
    }
    for (auto i = 0; i < pb.size(); ++i) {
      auto &val = pb[i];
      if (i < 4) {
        if (i == 0) {
          max = val;
        } else if (val > max) {
          max = val;
        }
        CHECK(s.pushBack(val));
        ++size;
        CHECK(s.getVector().size() == size);
        CHECK(s.maxElement() == max);
      } else {
        CHECK_FALSE(s.pushBack(val));
        CHECK(s.getVector().size() == size);
      }
    }
    for (auto i = 0; i < er.size(); ++i) {
      auto &val = er[i];
      if (i < 2) {
        CHECK(s.erase(val));
        --size;
        CHECK(s.getVector().size() == size);
        max = s.maxElement();
      } else {
        CHECK_FALSE(s.erase(val));
      }
      CHECK(s.maxElement() == max);
    }
    in.close();
  }
  SECTION("testing second input file") {
    std::ifstream in;
    auto e = 0;
    in.open("../../input2.txt");
    if (!in) {
      std::cout << "Unable to open file input2.txt\n";
      exit(1);
    }
    auto size = 0;
    std::optional<int> max = 0;
    auto counter = 0;
    std::array<int, 10> pb{};
    std::array<int, 7> er{};
    while (in >> e) {
      if (counter < 10) {
        pb[counter] = e;
      } else {
        er[counter - 10] = e;
      }
      ++counter;
    }
    for (auto i = 0; i < pb.size(); ++i) {
      auto &val = pb[i];
      if (i < 7) {
        if (i == 0) {
          max = val;
        } else if (val > max) {
          max = val;
        }
        CHECK(s.pushBack(val));
        ++size;
        CHECK(s.getVector().size() == size);
        CHECK(s.maxElement() == max);
      } else {
        CHECK_FALSE(s.pushBack(val));
        CHECK(s.getVector().size() == size);
      }
    }
    for (auto i = 0; i < er.size(); ++i) {
      auto &val = er[i];
      if (i < 3) {
        CHECK(s.erase(val));
        --size;
        CHECK(s.getVector().size() == size);
        max = s.maxElement();
      } else {
        CHECK_FALSE(s.erase(val));
      }
      CHECK(s.maxElement() == max);
    }
    in.close();
  }
}

TEST_CASE("Test all functionality of Set", "[SetFunctionalityTests]")
{
  using Set = mySpace::Set;
  Set s{};
  SECTION( "By default set is empty, has no max value")
  {
    CHECK(s.isEmpty());
    CHECK(s.getVector().capacity() == 0);
  }
  SECTION( "Add new elements to it, check maxElement")
  {
    s.pushBack(5);
    CHECK(s.maxElement() == 5);
    CHECK(s.getVector().size() == 1);

    s.pushBack(6);
    CHECK(s.maxElement() == 6);
    CHECK(s.getVector().size() == 2);

    s.pushBack(-2);
    CHECK(s.maxElement() == 6);
    CHECK(s.getVector().size() == 3);
  }
  SECTION( "New element should not be added, already contains")
  {
    CHECK(s.pushBack(5));
    CHECK(s.maxElement() == 5);
    CHECK(s.getVector().size() == 1);

    CHECK_FALSE(s.pushBack(5));
    CHECK(s.getVector().size() == 1);

    CHECK(s.pushBack(2));
    CHECK(s.maxElement() == 5);
    CHECK(s.getVector().size() == 2);

    CHECK(s.pushBack(7));
    CHECK(s.maxElement() == 7);
    CHECK(s.getVector().size() == 3);

    CHECK_FALSE(s.pushBack(2));
    CHECK(s.getVector().size() == 3);
  }
  SECTION( "Erase should only take place if element exist in vector")
  {
    s.pushBack(5);
    s.pushBack(9);
    s.pushBack(-3);
    CHECK_FALSE(s.erase(7));
    CHECK(s.getVector().size() == 3);

    CHECK_FALSE(s.erase(11));
    CHECK(s.getVector().size() == 3);

    CHECK(s.erase(5));
    CHECK(s.getVector().size() == 2);
    CHECK(s.maxElement() == 9);

    CHECK(s.erase(9));
    CHECK(s.getVector().size() == 1);
    CHECK(s.maxElement() == -3);
    CHECK_FALSE(s.isEmpty());

    CHECK(s.erase(-3));
    CHECK(s.getVector().capacity() == 0);
    CHECK(s.isEmpty());
    CHECK_FALSE(s.maxElement().has_value());
  }
}

