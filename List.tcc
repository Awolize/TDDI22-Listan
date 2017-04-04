#include "List.h"
#include <iterator>
#include <utility>
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;
using namespace List_NS;

template <class T>
List<T>::List()
    : head{ make_unique<Node>() }, tail{head.get()}, sz{}
{}

template <class T>
List<T>::List(List const & other)
    : List{}
{
    Node * tmp = other.head.get();
    while ( tmp != other.tail )
    {
        push_back(tmp->value);
	tmp = tmp->next.get();  
    }
}

template <class T>
List<T>::List(List && tmp) noexcept
    :List{}
{
    swap(tmp);
}

template <class T>
List<T>::List(std::initializer_list<T> lst)
    : List{}
{
    for ( auto val : lst )
    {
        push_back(val);
    }
}

template <class T>
void List<T>::push_front(T value)
{
    head.release();
    head = make_unique<Node>(value, nullptr, head.get());
    if ( sz == 0 )
    {
        tail->prev = head.get();
    }
   
    ++sz;
}

template <class T>
void List<T>::push_back(T value)
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

template <class T>
bool List<T>::empty() const
{
    return head.get() == tail;
}

template <class T>
int List<T>::back() const
{
    return tail->prev->value;
}

template <class T>
int & List<T>::back()
{
    return tail->prev->value;
}

template <class T>
int List<T>::front() const
{
    return head->value;
}

template <class T>
int & List<T>::front()
{
    return head->value;
}

template <class T>
int & List<T>::at(int idx)
{
    return const_cast<int &>(static_cast<List const &>(*this).at(idx));
}

template <class T>
int const & List<T>::at(int idx) const
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

template <class T>
int List<T>::size() const
{
    return sz;
}

template <class T>
void List<T>::swap(List & other) noexcept
{
    using std::swap;
    swap(head, other.head);
    swap(tail, other.tail);
    swap(sz, other.sz);
}

template <class T>
List<T> & List<T>::operator=(List const & rhs) &
{
    List{rhs}.swap(*this);
    return *this;
}

template <class T>
List<T> & List<T>::operator=(List && rhs) &
{
    swap(rhs);
    return *this;
}
//--------------------------------
//     class List_Iterator
//--------------------------------

template <class T>
List<T>::List_Iterator::List_Iterator(Node * ptr)
    : curr(ptr) {}

// Operators
template <class T>
typename List<T>::List_Iterator::reference List<T>::List_Iterator::operator*() const
{
    return curr->value;
}

template <class T>
typename List<T>::List_Iterator & List<T>::List_Iterator::operator++() 
{
    if(curr->next != nullptr)
    {
	curr = curr->next.get();
	return *this; 
    }
}

template <class T>
typename List<T>::List_Iterator List<T>::List_Iterator::operator++(int) 
{
    List_Iterator temp(*this);
    if(curr->next != nullptr)
    {
	curr = curr->next.get();
	return temp; 
    }
}

template <class T>
typename List<T>::List_Iterator & List<T>::List_Iterator::operator--() 
{
    if(curr->prev != nullptr)
    {
	curr = curr->prev;
	return *this; 
    }
}

template <class T>
typename List<T>::List_Iterator List<T>::List_Iterator::operator--(int) 
{
    List_Iterator temp(*this);
    if(curr->prev != nullptr)
    {
	curr = curr->prev;
	return temp; 
    }
}

template <class T>
bool List<T>::List_Iterator::operator==(const List_Iterator & rhs) const
{
    return curr == rhs.curr; 
}

template <class T>
bool List<T>::List_Iterator::operator!=(const List_Iterator & rhs) const
{
    return curr != rhs.curr; 
}

template <class T>
typename List<T>::List_Iterator::reference List<T>::List_Iterator::operator->() const
{
    return curr;
}

template <class T>
typename List<T>::List_Iterator List<T>::begin()
{ 
    return List_Iterator(head.get()); 
}

template <class T>
typename List<T>::List_Iterator List<T>::end()
{
    return List_Iterator(tail); 
}
