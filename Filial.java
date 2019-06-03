package liprojeto;
 

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Filial implements Serializable{
    
    Map<String,List<Venda>> compras_filial1; //a key é o cliente
    Map<String,List<Venda>> compras_filial2; //a key é o cliente
    Map<String,List<Venda>> compras_filial3; // a key é o cliente
    
     
    /**  
    *CONSTRUTOR VAZIO
    */
    public Filial(){
    this.compras_filial1= new HashMap<>();
    this.compras_filial2= new HashMap<>();
    this.compras_filial3= new HashMap<>();
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

    public Map<String,List<Venda>> getCompras_fil1() {
        return this.compras_filial1;
    }

    
  
    
    public Map<String,List<Venda>> getCompras_fil2() {
        return this.compras_filial2;
    
    
    }

  
    
    public Map<String,List<Venda>> getCompras_fil3() {
        return this.compras_filial3;
    }

    

    
 
     public Filial clone() {
        return new Filial(this);
    }
    
    /**
     *TO STRING
     */
    public String toString(){
        StringBuffer sb = new StringBuffer("");
        for(List<Venda> v: this.compras_filial1.values()){
        sb.append("Compras na filial 1: ").append(v).append("\n");
    }
        for(List<Venda> v: this.compras_filial2.values()){
        sb.append("Compras na filial 2: ").append(v).append("\n");
    } 
        
        for(List<Venda> v: this.compras_filial3.values()){
        sb.append("Compras na filial 3: ").append(v).append("\n");
    }
        
        
       return sb.toString();
    }
    
    
    public void addFilial1(Venda v){
        if(compras_filial1.containsKey(v.getC())){
          compras_filial1.get(v.getC()).add(v);
        }
        else {
        ArrayList<Venda> s= new ArrayList<>(); 
        s.add(v);
        this.compras_filial1.put(v.getC(), s);
        }
    }
      
    
     public void addFilial2(Venda v){
        if(compras_filial2.containsKey(v.getC())){
          compras_filial2.get(v.getC()).add(v);
        }
        else  {
        ArrayList<Venda> s= new ArrayList<>(); 
        s.add(v);
        this.compras_filial2.put(v.getC(), s);
        }
    }
     
      public void addFilial3(Venda v){
        if(compras_filial3.containsKey(v.getC())){
          compras_filial3.get(v.getC()).add(v);
        }
        else  { 
        ArrayList<Venda> s= new ArrayList<>(); 
        s.add(v);
        this.compras_filial3.put(v.getC(), s);
        }
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
