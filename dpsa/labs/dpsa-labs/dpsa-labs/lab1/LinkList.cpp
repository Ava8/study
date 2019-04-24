//
//  LinkList.cpp
//  labs
//
//  Created by MacBook Air on 21.02.2019.
//  Copyright © 2019 MacBook Air. All rights reserved.
//

#include <stdexcept>
#include <iostream>

struct ListObject
{
    std::string name;
    std::size_t code;
};

std::ostream &operator<<(std::ostream &os, const struct ListObject &obj)
{
    os << "ListObject{name: '" << obj.name << "', code: " << obj.code << "}";
    return os;
}

class LinkedList
{
private:
    struct Node
    {
        ListObject value;
        Node *next;
        Node *previous;
        
        Node(ListObject value)
        {
            next = nullptr;
            previous = nullptr;
            this->value = value;
        }
    };
    
    LinkedList::Node *first, *last;
    
public:
    LinkedList() : first{nullptr}, last{nullptr} {}
    
    void add(ListObject value)
    {
        LinkedList::Node *n = new LinkedList::Node(value);
        if (first == nullptr)
        {
            std::cout << "creating head " << n->value << std::endl;
            first = n;
            last = first;
        }
        else
        {
            // проверка на дубликаты
            LinkedList::Node *current;
            for (current = first; current; current = current->next)
            {
                if (current->value.name == n->value.name)
                {
                    std::cout << "ignoring " << n->value << std::endl;
                    return;
                }
            }
            // если не дубликат, то добавление
            for (current = first; current; current = current->next)
            {
                //сравнение
                // если переданный элемент меньше текущего
                if (current->value.code > n->value.code)
                {
                    if (current->previous)
                    {
                        if (current->previous->value.code < n->value.code)
                        {
                            current->previous->next = n;
                            n->previous = current->previous;
                            current->previous = n;
                            n->next = current;
                            return;
                        }
                    }
                    else
                    {
                        first = n;
                        n->next = current;
                        current->previous = n;
                        return;
                    }
                }
                // если преданный элемент больше текущего
                else if (current->value.code < n->value.code)
                {
                    if (current->next)
                    {
                        if (current->next->value.code > n->value.code)
                        {
                            current->next->previous = n;
                            n->next = current->next;
                            current->next = n;
                            n->previous = current;
                            return;
                        }
                    }
                    else
                    {
                        last = n;
                        current->next = n;
                        n->previous = current;
                        return;
                    }
                }
            }
        }
    }
    
    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list)
    {
        os << "LinkedList{";
        for (LinkedList::Node *n = list.first; n; n = n->next)
        {
            os << n->value << (n->next ? ", " : "}");
        }
        return os;
    }
};

//int main()
//{
//    LinkedList list{};
//    for (int i = 0; i < 5; i++)
//    {
//        ListObject obj = ListObject{};
//        // 5, 5, 4, 4, 3, 3, 2, 2, 1, 1
//        obj.code = 5 - i;
//        obj.name = "object #" + std::to_string(obj.code);
//        list.add(obj);
//        list.add(obj);
//    }
//    ListObject obj = ListObject{};
//    obj.code = 7;
//    obj.name = "object #7";
//    list.add(obj);
//    obj.code = 6;
//    obj.name = "object #6";
//    list.add(obj);
//    
//    std::cout << list << std::endl;
//    
//    return 0;
//}
