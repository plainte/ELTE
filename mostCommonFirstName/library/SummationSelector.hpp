#pragma once

#include "procedure.hpp"
#include <iostream>
#include <optional>

template < class Item, class Counter, class Value = Item>
class SummationSelector : public Procedure<Item>
{
public:
    SummationSelector()  = default;
    explicit SummationSelector(const std::pair<Value, Counter> &v) : _result(v) {}

    std::pair<Value, Counter>& result()  { return _result; }
    [[nodiscard]] const std::pair<Value, Counter>& result() const { return _result; }
    const std::string& getPrev() const { return _prev; }
    [[nodiscard]] int getCounter() const { return _counter; }

private:
    std::pair<Value, Counter> _result;
    Counter _counter = 0;
    std::string _prev;
    void resetCounter() { _counter = 1; }
    //initialization should be done in ctor.......
    void init() final { _result = neutral("", 0); }
    void body(const Item& e) final {
        if(cond(e)) {
            ++_counter;
            if (sCond()) {
                update(e, _counter);
            }
        } else {
            _prev = e;
            resetCounter();
        }
    }
    virtual std::pair<Value, Counter> neutral(const Item& e, const Counter& c) const = 0;
    virtual void update(const Item& e, const Counter& c) = 0;
    virtual bool cond(const Item& e) const { return true; }
    virtual bool sCond() const { return true; }
};
