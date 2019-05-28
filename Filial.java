
package liprojeto;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Filial {
    
    Map<String,Venda> compras_filial1; //a key é o cliente
    Map<String,Venda> compras_filial2; //a key é o cliente
    Map<String,Venda> compras_filial3; // a key é o cliente
    
    
    /**  
    *CONSTRUTOR VAZIO
    */
    public Filial(){
    this.compras_filial1= new HashMap<>();
    this.compras_filial2= new HashMap<>();
    this.compras_filial3= new HashMap<>();
}  
    
     /**
    *CONSTRUTOR PARAMETERIZADO
    */
    public Filial(Map<String, Venda> compras_filial1, Map<String, Venda> compras_filial2, Map<String, Venda> compras_filial3) {
        for(Venda v: compras_filial1.values()){
        this.compras_filial1.put(v.getC(),v.clone());
    }
        
        for(Venda v: compras_filial2.values()){
        this.compras_filial2.put(v.getC(),v.clone());
    }
        
        for(Venda v: compras_filial3.values()){
        this.compras_filial3.put(v.getC(),v.clone());
    }
        
    }
    
    
    /**
    *CONSTRUTOR DE COPIA
    */
    public Filial(Filial outrofil){
        
    this.compras_filial1= outrofil.getCompras_fil1();
    this.compras_filial2= outrofil.getCompras_fil2();
    this.compras_filial3= outrofil.getCompras_fil3();
       
    }  
 
    
     //GETTERS AND SETTERS

    public HashMap<String,Venda> getCompras_fil1() {
        HashMap<String,Venda> a = new HashMap();
        for(Venda v: this.compras_filial1.values()){
        a.put(v.getC(),v.clone());
    
    }
        return a;
    }

    
    
    public void setCompras_fil1(HashMap<String,Venda> ve) {
        for(Venda v: ve.values()){
        this.compras_filial1.put(v.getC(),v.clone());
    }
    }
    
    
    public HashMap<String,Venda> getCompras_fil2() {
        HashMap<String,Venda> a = new HashMap();
        for(Venda v: this.compras_filial2.values()){
        a.put(v.getC(),v.clone());
    
    }
        return a;
    }

    
    
    public void setCompras_fil2(HashMap<String,Venda> ve) {
        for(Venda v: ve.values()){
        this.compras_filial2.put(v.getC(),v.clone());
    }
    }
    
    public HashMap<String,Venda> getCompras_fil3() {
        HashMap<String,Venda> a = new HashMap();
        for(Venda v: this.compras_filial3.values()){
        a.put(v.getC(),v.clone());
    
    }
        return a;
    }

    
    
    public void setCompras_fil3(HashMap<String,Venda> ve) {
        for(Venda v: ve.values()){
        this.compras_filial3.put(v.getC(),v.clone());
    }
    }
    
 
     public Filial clone() {
        return new Filial(this);
    }
    
    /**
     *TO STRING
     */
    public String toString(){
        StringBuffer sb = new StringBuffer("");
        for(Venda v: this.compras_filial1.values()){
        sb.append("Compras na filial 1: ").append(v).append("\n");
    }
        for(Venda v: this.compras_filial2.values()){
        sb.append("Compras na filial 2: ").append(v).append("\n");
    } 
        
        for(Venda v: this.compras_filial3.values()){
        sb.append("Compras na filial 3: ").append(v).append("\n");
    }
        
        
       return sb.toString();
    }
    
    
    public void addFilial1(Venda v){
      
        this.compras_filial1.put(v.getC(),v.clone());
    
    }
    
     public void addFilial2(Venda v){
      
        this.compras_filial2.put(v.getC(),v.clone());
    
    }
     
      public void addFilial3(Venda v){
      
        this.compras_filial3.put(v.getC(),v.clone());
    
    }
      
    /**
     *HASHCODE
     */
    
    public int hashCode() {
    return Arrays.hashCode( new Object[] { compras_filial1, compras_filial2, compras_filial3} );
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
        Filial that = (Filial) obj;
        return (this.compras_filial1.equals(that.getCompras_fil1())
                && this.compras_filial2.equals(that.getCompras_fil2())
                && this.compras_filial3.equals(that.getCompras_fil3()));
               
    }
    
    
    
}
