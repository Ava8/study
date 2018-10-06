package mirea.mamaeva.lab3;

import mirea.mamaeva.lab3.Model.Furniture;
import mirea.mamaeva.lab3.Model.Sofa;
import mirea.mamaeva.lab3.Model.Table;

import java.util.Arrays;
import java.util.List;


public class FurnitureFactoryTest {
    public static void main(String[]args){
      List<Sofa> s = Arrays.asList(
              new Sofa("ikea","cotton","white",1200,3, Sofa.SofaType.usual),
              new Sofa("marko","leather","black",3400,4, Sofa.SofaType.folding),
              new Sofa("luxury furniture","velvet","red",2600,2, Sofa.SofaType.usual)
      );

      List<Table> t = Arrays.asList(
              new Table("for life","oak","light-blue",3000, Table.TableForm.square, 470),
              new Table("luxury furniture", "cherry-tree","natural",6800, Table.TableForm.circle, 500)
      );

      FurnitureFactory MyFactory = new FurnitureFactory(s, t);
      MyFactory.getSofaFullInformation(2);
      MyFactory.getTableFullInformation(1);
      MyFactory.FurnitureCount();
    }
}
