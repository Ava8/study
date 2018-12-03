package ru.mirea.mamaeva.practice.practice8.Order;

import ru.mirea.mamaeva.practice.practice8.Item.Item;
import ru.mirea.mamaeva.practice.practice8.LinkedList.LinkedList;
import java.util.HashMap;

public class RestaurantOrder {
    LinkedList myList;

    public RestaurantOrder(){
        myList = new LinkedList();
    }
    public RestaurantOrder(Item[] items){
        for (Item item : items) {
            myList.add(item);
        }
    }

    public boolean add(Item item){
        myList.add(item);
        return true;
    }

    public boolean delete(String name){
        myList.setLastHead();
        for (int i = 0; i < myList.getLength() - 1; i++) {
            if (myList.getItem().getName().equals(name)) {
                myList.deleteItem();
                return true;
            }
            myList.previous();
        }
        return false;
    }

    public int deleteAll(String name){
        int countOfDeleted=0;
        myList.setLastHead();
        for (int i = 0; i < myList.getLength() - 1; i++) {
            if (myList.getItem().getName().equals(name)) {
                myList.deleteItem();
                countOfDeleted++;
            }
            myList.previous();
        }
        return countOfDeleted;
    }

    public int getCount(){
        return myList.getLength();
    }

    public Item[] getAll(){
        Item[] items = new Item[getCount()];
        myList.setFirstHead();
        for (int i = 0; i < getCount() - 1; i++) {
            items[i] = myList.getItem();
            myList.next();
        }
        return items;
    }

    public int getCost(){
        int res=0;
        myList.setFirstHead();
        for (int i = 0; i < getCount() - 1; i++) {
            res += myList.getItem().getCost();
            myList.next();
        }
        return res;
    }

    public int getCountOf(String name){
        int res=0;
        myList.setFirstHead();
        for (int i = 0; i < getCount() - 1; i++) {
            if (myList.getItem().getName().equals(name))
                res ++;
            myList.next();
        }
        return res;
    }

    public String[] getAllNames(){
        int j = 0;
        HashMap<Integer, String> map = new HashMap<>();
        for (int i = 0; i < myList.getLength() - 1; i++) {
            if(!map.containsValue(myList.getItem().getName())) {
                map.put(j, myList.getItem().getName());
                j++;
            }
            myList.next();
        }
        String[] res = new String[map.size()];
        for (int i = 0; i < map.size() - 1; i++) {
            res[i] = map.get(i);
        }
        return res;
    }

    public Item[] sortingByCost(){
        Item[] order = new Item[myList.getLength()];
        myList.setFirstHead();
        for (int i = 0; i < order.length; i++) {
            order[i] = myList.getItem();
            myList.next();
        }
        for (int i = 0; i < order.length; i++) {
            for (int j = 0; j < order.length - i - 1; j++) {
                if (order[j].getCost() < order[j+1].getCost()){
                    Item tmp = order[j];
                    order[j] = order[j+1];
                    order[j+1] = tmp;
                }
            }
        }
        return order;
    }
}
