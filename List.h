#include <initializer_list>

class List
{
public:
    List() = default;
    List(List const &);
    List(List &&) noexcept;
    List(std::initializer_list<int>);

    List & operator=(List const &)&;
    List & operator=(List &&)&;

    void push_front(int);
    void push_back(int);

    int back() const;
    int & back();

    int front() const;
    int & front();

    int & at(int idx);
    int at(int idx) const;

    int size() const;

    void swap(List & other) noexcept;
private:
    struct Node;
    Node * head {};
    Node * tail {};
    int sz {};
};
