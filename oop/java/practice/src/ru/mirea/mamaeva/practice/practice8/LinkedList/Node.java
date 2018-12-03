package ru.mirea.mamaeva.practice.practice8.LinkedList;

import ru.mirea.mamaeva.practice.practice8.Item.Item;

class Node {
    private Item value;
    private Node next;
    private Node previous;

    Node(Item value, Node previous){
        this.value=value;
        this.previous=previous;
    }

    Node(Item value){
        this.value=value;
    }

    Item getValue() {
        return value;
    }

    Node getNext() {
        return next;
    }

    Node getPrevious() {
        return previous;
    }

    void linc(Node next){
        this.next=next;
    }

    public void setPrevious(Node previous) {
        this.previous = previous;
    }
}