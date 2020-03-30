//
// Created by molna on 2020. 03. 05..
//

#include "Set.h"
#include <utility>
#include <algorithm>

namespace mySpace {

  auto empty(const iList& list)
  {
    return list.size() == 0;
  }

  auto Set::isContain(int e)
  {
    auto it = std::find(v.cbegin(), v.cend(), e);
    auto index = std::distance(v.cbegin(), it);
    return std::make_pair(it, index);
  }

  Set::Set(const iList& list) noexcept
  {
    if (empty(list)) {
      clear();
    } else {
      auto m = *list.begin();
      for (const auto& e : list) {
        if (e > m) {
          m = e;
        }
        v.push_back(e);
      }
      max = m;
    }
  }

  bool Set::isEmpty() const
  {
    return v.empty();
  }

  bool Set::pushBack(int e)
  {
    if (isContain(e).first != v.end()) {
      return false;
    } else if (isEmpty() || e > max) {
      max = e;
    }
    v.push_back(e);
    return true;
  }

  bool Set::erase(int e)
  {
    if (isEmpty()) {
      return false;
    }
    auto c = isContain(e);
    if (c.first != v.end()) {
      auto wasMax = (v[c.second] == max);
      v.erase(c.first);
      v.shrink_to_fit();
      if (isEmpty()) {
        max.reset();
        return true;
      }
      if (wasMax) {
        setMax();
      }
      return true;
    }
    return false;
  }

  std::optional<int> Set::maxElement()
  {
    if (max.has_value()) {
      return max.value();
    }
    return {};
  }

  void Set::setMax()
  {
    auto m = v[0];
    for (const auto& e : v) {
      if (e > m) {
        m = e;
      }
    }
    max = m;
  }

  std::ostream &operator<<(std::ostream &os, const Set &set)
  {
    os << "Set elements: ";
    if (!set.isEmpty()) {
      for (const auto &e : set.v) {
        os << e << " ";
      }
    } else {
      os << "Set is empty";
    }
    os << " -- max element is : ";
    if (set.max.has_value()) {
      os << set.max.value() << "\n";
    } else {
      os << "none" << "\n";
    }
    return os;
  }

  std::vector<int> &Set::getVector()
  {
    return v;
  }

}
