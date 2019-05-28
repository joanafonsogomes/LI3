
package liprojeto;

import java.io.Serializable;
import java.util.Arrays;


public class Cliente implements Serializable, Comparable<Cliente>{
    
    private String clie;
    
    /**
    *CONSTRUTOR VAZIO
    */
    public Cliente (){
    this.clie= new String();
    }
    
    /**
     *CONSTRUTOR PARAMETERIZADO
     */
    public Cliente (String clie){
        this.clie=clie;
    }
    
    
    /**
    *CONSTRUTOR DE COPIA
    */
    public Cliente(Cliente outroClie) {
            this.clie = outroClie.getClie();
    }
  
    
    
    //GETTERS E SETTERS

    public String getClie() {
        return clie;
    }

    
    
    public boolean setClie_valido(String clie) {
        boolean r=false;
        char um = clie.charAt(0);
        char dois = clie.charAt(1); 
        char tres = clie.charAt(2);
        char quatro = clie.charAt(3);
        char cinco = clie.charAt(4);
        
        if( ( (um >='A') && (um <='Z') && (dois >= '1') && (dois <='4') && (tres >= '0') && (tres <='9') && (quatro >= '0') && (quatro <= '9') && (cinco >= '0') && (cinco <= '9') ) ||
            ( (um >= 'A') && (um <= 'Z') && (dois == '5') && (tres == '0') && (quatro == '0') && (cinco == '0') ) ) {
                
                this.clie = clie;
                r = true;
            }
        
        return r;
    }
    
    
     public Cliente clone() {
        return new Cliente(this);
    }
     
    public int compareTo(Cliente c){
        return this.clie.compareTo(c.getClie());
    }
    
    /**
     *TO STRING
     */
    public String toString(){
        StringBuffer sb = new StringBuffer();
        sb.append(this.clie).append("");
       return sb.toString();
    }
    
    /**
     *HASHCODE
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
        Cliente that = (Cliente) obj;
        return (this.clie.equals(that.getClie()));
               
    }
    
    
}

