
package liprojeto;

import java.io.Serializable;
import java.util.Arrays;
import java.util.SortedSet;
import java.util.TreeSet;


public class CatProdutos implements Serializable{
    SortedSet<String> prods;
    
/**  
*CONSTRUTOR VAZIO
*/
public CatProdutos(){
this.prods= new TreeSet<>();
}  
     
    
 /**
 *CONSTRUTOR PARAMETERIZADO
 */
    public CatProdutos(TreeSet<String> prods) {
    for(String p: prods){
        this.prods.add(p);
    }
    }
    
    
  
 /**
 *CONSTRUTOR DE COPIA
 */
  public CatProdutos(CatProdutos outrocat){
        
        this.prods =outrocat.getCatprod();
       
    }  
  
  //GETTERS AND SETTERS

    public SortedSet<String> getCatprod() {
       return this.prods;
    }

    
    
    public void setCatprod(TreeSet<String> prods) {
        for(String p: prods){
        this.prods.add(p);
    }
    }
    
    
    public void addprod(String prod){
      
        this.prods.add(prod);
    
    }
    

     public CatProdutos clone() {
        return new CatProdutos(this);
    }
    
    /**
     *TO STRING
     */
    public String toString(){
        StringBuffer sb = new StringBuffer("Catálogo de produtos:\n");
        for(String p: this.prods){
        sb.append("Produto: ").append(p).append("\n");
    }
       return sb.toString();
    }
    
    /**
     *HashCODE
     */
    
    public int hashCode() {
    return Arrays.hashCode( new Object[] { prods} );
    }
    
    
}
