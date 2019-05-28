
package liprojeto;

import java.io.Serializable;
import java.util.Arrays;


public class Produto implements Serializable, Comparable<Produto>{
    private String prod;
    
    
    
    /**
    *CONSTRUTOR VAZIO
    */
    public Produto (){
    this.prod= new String();
    }
    
    /**
     *CONSTRUTOR PARAMETERIZADO
     */
    public Produto (String prod){
        this.prod=prod;
    }
    
    
     public Produto(Produto outroProduto) {
            this.prod = outroProduto.getProd();
    }
     
   //GETTERS E SETTERS

    public String getProd() {
        return prod;
    }

    public boolean setProd_valido(String prod) {
        boolean r=false;
        char one= prod.charAt(0);
        char two = prod.charAt(1);
        char three = prod.charAt(2);
        char four = prod.charAt(3);
        char five = prod.charAt(4);
        char six = prod.charAt(5);
        
        if((one >='A') && (one <='Z') && (two >='A') && (two <='Z') 
                && (three>='1') && (three<='9') && (four>='0') && (four <= '9') 
                && (five>='0') && (five <= '9') 
                && (six>='0') && (six <= '9') ){
        
                this.prod = prod;
                r=true;
        }
        
        return r;
    }
    
    public Produto clone() {
        return new Produto(this);
    }
     
    public int compareTo(Produto p){
        return this.prod.compareTo(p.getProd());
    }
    
    
     /**
     *TO STRING
     */
    public String toString(){
        StringBuffer sb = new StringBuffer();
        sb.append(this.prod).append("");  
       return sb.toString();
    }
    
    /**
     *HASHCODE
     */
    @Override
    public int hashCode() {
    return Arrays.hashCode( new Object[] { prod} );
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
        Produto that = (Produto) obj;
        return (this.prod.equals(that.getProd()));
               
    }
    
}
