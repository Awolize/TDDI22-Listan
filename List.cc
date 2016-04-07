#include "List.h"
#include <iterator>
#include <utility>
#include <stdexcept>

struct List::Node 
{
    Node(int v, Node* p = nullptr, Node* n = nullptr)
        : value{v}, prev{p}, next{n} {}  
    int value {};
    Node * prev {};
    Node * next {};
};
List::List(List const & other)
    : sz{other.sz}
{
    if ( other.size() == 0 )
        return;
    Node * tmp {other.head};
    head = new Node{other.head->value};
    tail = head;
    while ( tmp != nullptr )
    {
        tail->next = new Node{tmp->value, tail};
        tail = tail->next;
        tmp = tmp->next;
    }
}
List::List(List && tmp) noexcept
{
    swap(tmp);
}
List::List(std::initializer_list<int> lst)
    : head{new Node{*lst.begin()}}, tail{head}, sz{1}
{
    for ( auto it = std::next(lst.begin()); it != end(lst); ++it )
    {
        tail->next = new Node{*it, tail};
        tail = tail->next;
        ++sz;
    }
}

void List::push_front(int value)
{
    head->prev = new Node{value, nullptr, head};
    head = head->prev;
    ++sz;
}
void List::push_back(int value)
{
    tail->next = new Node{value, tail};
    tail = tail->next;
    ++sz;
}

int List::back() const
{
    return tail->value;
}
int & List::back()
{
    return tail->value;
}

int List::front() const
{
    return head->value;
}
int & List::front()
{
    return head->value;
}

int & List::at(int idx)
{
    return const_cast<int &>(static_cast<List const &>(*this).at(idx));
}
int const & List::at(int idx) const
{
    if (idx >= sz)
        throw std::out_of_range{"Index not found"};
    Node * tmp {head};
    while ( idx > 0 )
    {
        tmp = tmp->next;
        --idx;
    }
    return tmp->value;
}

int List::size() const
{
    return sz;
}

void List::swap(List & other) noexcept
{
    using std::swap;
    swap(head, other.head);
    swap(tail, other.tail);
    swap(sz, other.sz);
}

List & List::operator=(List const & rhs) &
{
    List{rhs}.swap(*this);
    return *this;
}

List & List::operator=(List && rhs) &
{
    swap(rhs);
    return *this;
}
