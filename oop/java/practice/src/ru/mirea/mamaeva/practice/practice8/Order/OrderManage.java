package ru.mirea.mamaeva.practice.practice8.Order;

import ru.mirea.mamaeva.practice.practice8.Item.Item;

import java.util.HashMap;
import java.util.Map;

public class OrderManage {
    HashMap<String, Order> orders = new HashMap<>();

    public void addOrder(String address, Order order) throws OrderAlreadyAddedExeption, IllegalTableNumber {
        if (orders.containsKey(address))throw new OrderAlreadyAddedExeption();
        else orders.put(address, order);
    }

    public void getOrder(String address) throws IllegalTableNumber{
        orders.get(address);
    }

    public void remove(String address){
        orders.remove(address);
    }

    public void addItemToOrder(String address, Item item) throws IllegalTableNumber{
        Order tmp = orders.get(address);
        tmp.add(item);
        orders.put(address, tmp);
    }

    public Order[] getAllOrders(){
        Order[] res = new Order[orders.size()];
        int i = 0;
        for (Map.Entry entry : orders.entrySet()){
            res[i] = (Order)entry.getValue();
            i++;
        }
        return res;
    }
}
