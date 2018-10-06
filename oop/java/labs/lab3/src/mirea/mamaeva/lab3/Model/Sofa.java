package mirea.mamaeva.lab3.Model;



public class Sofa extends Furniture {

    public enum SofaType {
        folding, usual
    }

    private int humanCapacity;
    private SofaType type;


    public Sofa() {}
    public Sofa(String manufacturer, String material, String color, int price) {
        super(manufacturer, material, color, price);
    }
    public Sofa(String manufacturer, String material, String color, int price, int humanCapacity, SofaType type) {
        super(manufacturer, material, color, price);
        this.humanCapacity = humanCapacity;
        this.type = type;
    }

    public int getHumanCapacity() {
        return humanCapacity;
    }
    public SofaType getType() {
        return type;
    }

}
