package ru.mirea.mamaeva.practice.practice8.LinkedList;

import ru.mirea.mamaeva.practice.practice8.Item.Item;

public class LinkedList {
    private Node first;
    private Node last;
    private Node head;
    private int length;

    public LinkedList(Item firstValue){
        first = head = last = new Node(firstValue);
        length = 1;
    }

    public LinkedList(){
        length = 0;
    }

    public void add(Item value){
        if (length == 0){
            first = head = last = new Node(value);
            length++;
        } else {
            last = new Node(value, last);
            last.linc(first);
            last.getPrevious().linc(last);
            first.setPrevious(last);
            length++;
        }
    }


    public void next(){
        head = head.getNext();
    }

    public void previous(){
        head = head.getPrevious();
    }

    public void deleteItem(){
        if (length==1) {
            length=0;
            first = head = last = null;
        } else {
            head.getNext().setPrevious(head.getPrevious());
            head.getPrevious().linc(head.getNext());
            head = head.getPrevious();
            length--;
        }
    }

    public Item getItem(){
        return head.getValue();
    }

    public int getLength(){
        return length;
    }

    public void setLastHead() {
        head = last;
    }

    public void setFirstHead() {
        head = first;
    }
}
