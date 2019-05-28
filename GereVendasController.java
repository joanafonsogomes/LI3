
package liprojeto;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Serializable;


public class GereVendasController implements InterfGereVendasController, Serializable{
       GestVendas r;
    
    public void setModel (InterfGereVendasModel m){
       
    }
    
    
    
    
    public void setView(InterfGereVendasView v){
        v.run();
        
    }
    
    public void startController(){
    }
    
}
