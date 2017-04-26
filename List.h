#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <memory>
#include <iterator>

namespace List_NS
{
    template<typename T>
    class List
    {
    private:
	struct Node
	{
	    Node() = default;
	    Node(T v, Node* p, Node* n)
		: value{v}, prev{p}, next{n} {}
	    T value {};
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
        List(std::initializer_list<T>);

	List & operator=(List const &)&;
	List & operator=(List &&)&;

	void push_front(T);
	void push_back(T);

	T back() const;
	T & back();

	T front() const;
	T & front();

	T & at(int idx);
	T const & at(int idx) const;

	int size() const;
	bool empty() const;

	void swap(List & other) noexcept;

	class List_Iterator
	{
	public:
	    friend class List;
	    using iterator_category = std::bidirectional_iterator_tag;
	    using value_type = T;
	    using difference_type = T;
	    using reference = T &;
	    using pointer = T *;
	    reference operator*() const;
	    List_Iterator & operator++();
	    List_Iterator operator++(int);
	    List_Iterator & operator--();
	    List_Iterator operator--(int);
	    bool operator==(const List_Iterator&) const;
	    bool operator!=(const List_Iterator&) const;
	    pointer operator->() const;

	private:
	    List_Iterator();
	    List_Iterator(Node * ptr); 
	    Node * curr{};
	};
	List_Iterator begin() const;
	List_Iterator end() const;
    };
}
#include "List.tcc"

#endif //LIST_H
