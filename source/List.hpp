#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>
#include <list>
#include <iostream>

//List.hpp

template <typename T>
class List;

template <typename T>
struct ListNode
{
    T value = T();
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

template <typename T>
class ListIterator
{
    public:


    private:
    ListNode <T>* node;
};


template <typename T>
class ListConstIterator
{
    public:


    private:
    ListNode <T>* node;
};


template <typename T>
class List
{
    public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = T const*;
    using reference = T&;
    using const_reference = T const&;
    using iterator = ListIterator <T>;
    using const_iterator = ListConstIterator <T>;



    //Aufgabe 4.2
    
    //Default Konstruktor
    
    List():
    size_{0},
    first_{nullptr},
    last_{nullptr}
    {}
    
    bool empty() const
    {
        if(size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    std::size_t size() const
    {
        return size_;
    }

    // Aufgabe 4.3

    T& front() const
    {
        if (empty())
        {
            std::cout << "Die Liste ist leer";
        }
        else
        {
            return first_ -> value;
        }
    }

    T& last() const
    {
        if (empty())
        {
            std::cout << "Die Liste ist leer";
        }
        else
        {
            return last_ -> value;
        }
    }


    void push_front(T const& value)
    {
        ListNode <T>* node = new ListNode <T> {value, nullptr, nullptr};

        if(!empty())
        {
            first_ -> prev = node;
            node -> next = first_;
        }
        else
        {
            last_ = node;
        }

        first_ = node;
        ++size_;
    }

    void push_back(T const& value)
    {
        ListNode <T>* node = new ListNode <T> {value, nullptr, nullptr};

        if(!empty())
        {
            last_ -> next = node;
            node -> prev = last_;
        }
        else
        {
            first_ = node;
        }

        last_ = node;
        ++size_;
    }

    void pop_front()
    {
        if(size() == 1)
        {
            first_ = last_ = nullptr;
            --size_;
        }
        else if(size() > 1)
        {
            first_ = (*first_).next;
            --size_;
        }
        else
        {
            std::cout << "Liste ist bereits leer";
        }
    }

    void pop_back()
    {
        if(size() == 1)
        {
            first_ = last_ = nullptr;
            --size_;
        }
        else if(size() > 1)
        {
            last_ = (*last_).prev;
            --size_;
        }
        else
        {
            std::cout << "Liste ist bereits leer";
        }
    }

    // Aufgabe 4.4

    void clear()
    {
        if(empty() == true)
        {
            std::cout <<"Die Liste ist bereits leer." << "\n";
        }
        while(size_ != 0)
        {
            pop_back();
        }
    }











    private:
    std::size_t size_;
    ListNode <T>* first_;
    ListNode <T>* last_;
};











#endif //define BUW_LIST_HPP