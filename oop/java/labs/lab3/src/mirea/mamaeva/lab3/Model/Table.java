package mirea.mamaeva.lab3.Model;


public class Table extends Furniture {

    public enum TableForm {
        circle, square
    }

    private TableForm form;
    private int square;

    public Table() {}
    public Table(String manufacturer, String material, String color, int price) {
        super(manufacturer, material, color, price);
    }
    public Table(String manufacturer, String material, String color, int price, TableForm form, int square) {
        super(manufacturer, material, color, price);
        this.form = form;
        this.square = square;
    }

    public int getSquare() {
        return square;
    }

    public TableForm getForm() {
        return form;
    }

}
