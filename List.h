#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <memory>
#include <iterator>
class List
{
public:
    // typedef typename List::reference reference;
    class List_Iterator
    {
	using value_type = int;
	using iterator_direcory = std::forward_iterator_tag;
    public:
	reference operator*() const;
	List_Iterator & operator++() /*{ ptr = *this->next.get(); return ptr;} */;
	List_Iterator & operator--();
	Node* ptr{};
    };

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
};



#endif //LIST_H
//http://stackoverflow.com/questions/7758580/writing-your-own-stl-container/7759622#7759622
//http://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls
