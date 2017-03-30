#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <memory>
#include <iterator>

class List
{

private:
    struct Node
    {
	Node() = default;
	Node(int v, Node* p, Node* n)
	    : value{v}, prev{p}, next{n} {}
	int value {};
	Node * prev {};
	std::unique_ptr<Node> next {};
    };
    std::unique_ptr<Node> head {};
    Node * tail {};
    int sz {};

public:
    List();
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
    int const & at(int idx) const;

    int size() const;
    bool empty() const;

    void swap(List & other) noexcept;

    class List_Iterator
    {
	typedef List_Iterator self_type;
	typedef std::bidirectional_iterator_tag iterator_direcory;
	typedef int value_type;
	typedef int difference_type;
	typedef Node * pointer;
	typedef int & reference;
    public:
	List_Iterator();
	List_Iterator(Node * ptr);
	reference operator*() const;
	List_Iterator & operator++();
	List_Iterator operator++(int); // { ptr = *this->next.get(); return ptr;} ;
	List_Iterator & operator--();
	List_Iterator operator--(int);
	List_Iterator & operator=(const List_Iterator&);
        bool operator==(const List_Iterator&) const;
        bool operator!=(const List_Iterator&) const;
    private:
	pointer curr{};
    };
};

#endif //LIST_H
//http://stackoverflow.com/questions/7758580/writing-your-own-stl-container/7759622#7759622
//http://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls
