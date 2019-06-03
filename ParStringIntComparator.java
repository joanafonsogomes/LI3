
package liprojeto;

import java.io.Serializable;
import java.util.Comparator;


public class ParStringIntComparator implements Comparator<ParStringInt>, Serializable{
   
     public int compare(ParStringInt a1, ParStringInt a2){
        return Double.compare(a1.getY(), a2.getY());
    }
     
}
