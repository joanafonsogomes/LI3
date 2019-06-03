package liprojeto;

import java.io.Serializable;
import java.util.Arrays;
import java.util.TreeSet;
import java.util.SortedSet;



public class CatClientes implements Serializable{
    SortedSet<String> clie;  //a key é cliente
    
/**  
*CONSTRUTOR VAZIO
*/
public CatClientes(){
this.clie= new TreeSet<>();
}  
     
    
 /**
 *CONSTRUTOR PARAMETERIZADO
 */
    public CatClientes(TreeSet<String> clie) {
    for(String c: clie){
        this.clie.add(c);
    }
    }
    
    
    
  
 /**
 *CONSTRUTOR DE COPIA
 */
  public CatClientes(CatClientes outroclie){
        
        this.clie =outroclie.getCatClie();
       
    }  
  
  //GETTERS AND SETTERS

    public SortedSet<String> getCatClie() {
        return this.clie;
      
 
    }

    
    
    public void setCatClie(TreeSet<String> clie) {
       for(String c: clie){
        this.clie.add(c);
    }
    }
    
    
    public void addclie(String clie){
        this.clie.add(clie);
    }
  
  
     public CatClientes clone() {
        return new CatClientes(this);
    }
    
    
    /**
     *TO STRING
     */
    public String toString(){
        StringBuffer sb = new StringBuffer("Catálogo de clientes:\n");
        for(String c: this.clie){
        sb.append("Cliente: ").append(c).append("\n");
    }
       return sb.toString();
    }
    
    /**
     *HashCODE
     */
    
    public int hashCode() {
    return Arrays.hashCode( new Object[] { clie} );
    }
    
    
    /**
     *EQUALS
     */
    
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (this.getClass() != obj.getClass()) {
            return false;
        }
        CatClientes that = (CatClientes) obj;
        return (this.clie.equals(that.getCatClie()));
               
    }
}

