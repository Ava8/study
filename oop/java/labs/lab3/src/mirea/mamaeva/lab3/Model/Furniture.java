package mirea.mamaeva.lab3.Model;

public abstract class Furniture {
    private String manufacturer;
    private String material;
    private String color;
    private  int price;

    public Furniture(String manufacturer, String material, String color, int price) {
        this.manufacturer = manufacturer;
        this.material = material;
        this.color = color;
        this.price = price;
    }
    public Furniture() {}

    public String getManufacturer() {
        return  manufacturer;
    }
    public  String getMaterial() {
        return  material;
    }
    public String getColor() {
        return color;
    }
    public int getPrice() {
        return  price;
    }
}
