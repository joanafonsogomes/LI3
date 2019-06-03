package liprojeto;
 

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Faturacao implements Serializable{
    
    Map<String,List<Venda>> vendas; // a key é o produto
    
    
/**  
*CONSTRUTOR VAZIO
*/
public Faturacao(){
this.vendas= new HashMap<>();
}  

    
    
  
 /**
 *CONSTRUTOR DE COPIA
 */
  public Faturacao(Faturacao outrofat){
        
        this.vendas =outrofat.getFaturacao();
       
    }  
  
  //GETTERS AND SETTERS

    public Map<String,List<Venda>> getFaturacao() {
        return this.vendas;
    }

   
    
    
    public void addFaturacao(Venda v){
        if(vendas.containsKey(v.getP())){
          vendas.get(v.getP()).add(v);
        }
        else  {
        ArrayList<Venda> s= new ArrayList<>(); 
        s.add(v);
        this.vendas.put(v.getP(),s);
        }
    }
    

  public Faturacao clone() {
        return new Faturacao(this);
    }
    
   
    
    /**
     *HASHCODE
     */
    
    public int hashCode() {
    return Arrays.hashCode( new Object[] { vendas} );
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
        Faturacao that = (Faturacao) obj;
        return (this.vendas.equals(that.getFaturacao()));
               
    }

/**
     *TO STRING
     */
    public String toString(){
        StringBuffer sb = new StringBuffer("");
        for(List<Venda> v: this.vendas.values()){
        sb.append("Faturacao: ").append(v).append("\n");
    }    
       return sb.toString();
    }

   
    
}

     
    

    
    
    
    
    

