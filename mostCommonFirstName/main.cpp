#include <iostream>
#include "library/seqinfileenumerator.hpp"
#include "library/SummationSelector.hpp"



class MostCommonFirstName : public SummationSelector<std::string, int>
{
public:
    friend std::ostream &operator<<(std::ostream &os, const MostCommonFirstName &obj) {
        os << obj.result().first;
        return os;
    }

private:
    [[nodiscard]] bool cond(const std::string& e) const noexcept final { return e == getPrev(); }
    [[nodiscard]] bool sCond() const noexcept final { return result().second < getCounter(); }
    [[nodiscard]] std::pair<std::string,int> neutral(const std::string& e, const int& c)  const noexcept final { return e.empty() ? std::make_pair("", 0) :  std::make_pair(e, c); }
    void update(const std::string& e, const int& c)  noexcept final {
        result() = neutral(e, c);
    }
};



int main(int argc, char* argv[])
{
    std::string fname = (argc==1)? "../input.txt" : argv[1];

    MostCommonFirstName pr;
    SeqInFileEnumerator<std::string> enumerator(fname);
    pr.addEnumerator(&enumerator);
    pr.run();

    std::cout << pr;

    return 0;
}
