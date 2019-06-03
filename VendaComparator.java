
package liprojeto;

import java.io.Serializable;
import java.util.Comparator;


public class VendaComparator implements Comparator<Venda>, Serializable{
     public int compare(Venda a1, Venda a2){
        return Double.compare(a1.getPreco() * a1.getQuant(), a2.getPreco()* a2.getQuant());
    }
     
}

