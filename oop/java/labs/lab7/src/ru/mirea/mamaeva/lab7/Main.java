package ru.mirea.mamaeva.lab7;

import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class Main {
    public static void main(String[] args) {
        List<String> linkedList = new LinkedList<String>();
        // добавление элементов в список
        linkedList.add("java");
        linkedList.add("c++");
        linkedList.add("python");
        // добавление элемента в начало списка
        ((LinkedList<String>) linkedList).addFirst("swift");
        // добавление элемента в конец списка
        ((LinkedList<String>) linkedList).addLast("ruby");
        // добавление в середину списка
        linkedList.add(2,"pascal");
        // удаление элемента по значению
        linkedList.remove("pascal");

        // для собственноручного перебора элементов воспользуемся встроенным интератором
        ListIterator<String> itr = linkedList.listIterator();
        while (itr.hasNext())
            System.out.println(itr.next());

        // получение первого элемента
        System.out.println("head: " +((LinkedList<String>) linkedList).getFirst());
        // получение последнего элемета
        System.out.println("tail: " +((LinkedList<String>) linkedList).getLast());

        // очистка списка
        linkedList.clear();
        System.out.println("linked list after cleaning: " +linkedList.toString());

    }
}

// LinkedList — реализует интерфейс List.
// Является представителем двунаправленного списка, где каждый элемент структуры содержит указатели на предыдущий и следующий элементы.
// Итератор поддерживает обход в обе стороны.
// Реализует методы получения, удаления и вставки в начало, середину и конец списка.
// Позволяет добавлять любые элементы в том числе и null.