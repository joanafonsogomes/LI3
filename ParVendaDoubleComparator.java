
package liprojeto;

import java.io.Serializable;
import java.util.Comparator;


public class ParVendaDoubleComparator implements Comparator<ParVendaDouble> ,Serializable{
    

  public int compare(ParVendaDouble a1, ParVendaDouble a2){
        return compareByquant(a1.getX(),a2.getX());
    }
     


public int compareByquant (Venda a, Venda b){
        int r=0;
        if(a.getQuant()>b.getQuant()) r=-1;
        else if(a.getQuant()<b.getQuant()) r=1;
        else if(a.getC().compareTo(b.getC())==0){
            r= compareBycod (a,b);
        }
        else r = compByClie(a,b);
        return r;
    }
    
    public int compareBycod(Venda a, Venda b){
        int r=0;
        r= a.getP().compareTo(b.getP());
      
        return r;
    }
    
    public int compByClie(Venda a, Venda b){
        int r=0;
        r= a.getC().compareTo(b.getC());
      
        return r;
    }
    
}