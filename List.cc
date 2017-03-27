#include "List.h"
#include <iterator>
#include <utility>
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

reference List::List_Iterator::operator*() const
{
    auto it = *this.List::front();
    return it;
}

List_Iterator List::List_Iterator::operator++() 
{
    
}

List_Iterator List::List_Iterator::operator--() 
{
    
}

List::List()
    : head{ make_unique<Node>() }, tail{head.get()}, sz{}
{}

List::List(List const & other)
    : List{}
{
    Node * tmp = other.head.get();
    while ( tmp != other.tail )
    {
        push_back(tmp->value);
	tmp = tmp->next.get();  
    }
}
List::List(List && tmp) noexcept
    :List{}
{
    swap(tmp);
}
List::List(std::initializer_list<int> lst)
    : List{}
{
    for ( auto val : lst )
    {
        push_back(val);
    }
}

void List::push_front(int value)
{
    head.release();
    head = make_unique<Node>(value, nullptr, head.get());
    if ( sz == 0 )
    {
        tail->prev = head.get();
    }
   
    ++sz;
}
void List::push_back(int value)
{
    if ( empty() )
    {
        push_front(value);
    }
    else
    {
	tail->prev->next.release();
        tail->prev->next = make_unique<Node>(value, tail->prev, tail);
        tail->prev = tail->prev->next.get();
        ++sz;
    }
}

bool List::empty() const
{
    return head.get() == tail;
}

int List::back() const
{
    return tail->prev->value;
}
int & List::back()
{
    return tail->prev->value;
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
    Node * tmp {head.get()};
    while ( idx > 0 )
    {
        tmp = tmp->next.get();
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
