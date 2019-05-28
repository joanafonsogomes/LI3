
package liprojeto;

import java.io.Serializable;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;


public class Faturacao implements Serializable{
    
    Map<String,Venda> vendas; // a key é o produto
    
    
/**  
*CONSTRUTOR VAZIO
*/
public Faturacao(){
this.vendas= new HashMap<>();
}  

  
 /**
 *CONSTRUTOR PARAMETERIZADO
 */
    public Faturacao(HashMap<String,Venda> vend) {
    for(Venda v: vend.values()){
        this.vendas.put(v.getP(),v.clone());
    }
    }
    
    
  
 /**
 *CONSTRUTOR DE COPIA
 */
  public Faturacao(Faturacao outrofat){
        
        this.vendas =outrofat.getFaturacao();
       
    }  
  
  //GETTERS AND SETTERS

    public HashMap<String,Venda> getFaturacao() {
        HashMap<String,Venda> a = new HashMap();
        for(Venda v: this.vendas.values()){
        a.put(v.getP(),v.clone());
    
    }
        return a;
    }

    
    
    public void setFaturacao(HashMap<String,Venda> ve) {
        for(Venda v: ve.values()){
        this.vendas.put(v.getP(),v.clone());
    }
    }
    
    
    public void addFaturacao(Venda v){
      
        this.vendas.put(v.getP(),v.clone());
    
    }
    

  public Faturacao clone() {
        return new Faturacao(this);
    }
    
    /**
     *TO STRING
     */
    public String toString(){
        StringBuffer sb = new StringBuffer("Faturação:\n");
        for(Venda v: this.vendas.values()){
        sb.append("Venda: ").append(v).append("\n");
    }
       return sb.toString();
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
public ArrayList<Produto> nuncaCompr(int i) {
    i=0; int r=0;
    ArrayList<Produto> a=null;
  //  for(Produto pr: p){
  //  for(Venda v: vendas){
        if(p.equals(v)){
            r=1;
        }
    }*/
    
}

     
    

    
    
    
    
    

