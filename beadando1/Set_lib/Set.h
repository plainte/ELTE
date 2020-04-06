//
// Created by molna on 2020. 03. 05..
//

#ifndef BEADANDO1_SET_H
#define BEADANDO1_SET_H

#include <vector>
#include <optional>
#include <iostream>
#include <memory>

namespace mySpace {

  using iList = std::initializer_list<int>;

  class Set {
  public:
    Set(const iList& list) noexcept;

    [[nodiscard]] bool isEmpty() const;
    bool pushBack(int e);
    bool erase(int e);
    void clear() { v.clear(); v.shrink_to_fit(); max.reset(); }
    std::optional<int> maxElement();

    friend std::ostream &operator<<(std::ostream &os, const Set &set);

    std::vector<int>& getVector();

  private:
    auto isContain(int e);
    void setMax();
    std::vector<int> v;
    std::optional<int> max;
  };

  using SetPtr = std::unique_ptr<Set>;


}


#endif //BEADANDO1_SET_H
