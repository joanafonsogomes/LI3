
package liprojeto;

import java.io.Serializable;
import java.util.Arrays;
import java.util.Set;



public class Venda implements Serializable{
    String p;
    double preco;
    int quant;
    char promnorm;
    String c;
    int mes;
    int filial;
    
    
    /**
    *CONSTRUTOR VAZIO
    */
    public Venda (){
    this.p= new String();
    this.preco= 0.0;
    this.quant=0;
    this.promnorm =' ';
    this.c = new String();
    this.mes= 0;
    this.filial=0;
    
    }
    
    /**
     *CONSTRUTOR PARAMETERIZADO
     */
    public Venda (String p, double preco, int quant, char promnorm, String c, int mes, int filial){
        this.p=p;
        this.preco=preco;
        this.quant=quant;
        this.promnorm=promnorm;
        this.c=c;
        this.mes=mes;
        this.filial=filial;
    }
    
     public Venda(Venda outraVenda) {
            this.p = outraVenda.getP();
            this.preco=outraVenda.getPreco();
            this.quant=outraVenda.getQuant();
            this.promnorm=outraVenda.getPromnorm();
            this.c=outraVenda.getC();
            this.mes=outraVenda.getMes();
            this.filial=outraVenda.getFilial();
    }
     
   //GETTERS E SETTERS

    public String getP() {
        return this.p;
    }
    
    public void setP(String p) {
        this.p = p;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public int getQuant() {
        return quant;
    }

    public void setQuant(int quant) {
        this.quant = quant;
    }

    public char getPromnorm() {
        return promnorm;
    }

    public void setPromnorm(char promnorm) {
        this.promnorm = promnorm;
    }

    public String getC() {
        return c;
    }

    public void setC(String c) {
        this.c = c;
    }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getFilial() {
        return filial;
    }

    public void setFilial(int filial) {
        this.filial = filial;
    }
    
    
    
    
    public boolean isVenda_valida(String v, CatProdutos cp, CatClientes cl) {
        boolean r=false;
        int i=0;
        String[] l= v.split("\\s+");
        //verifica venda valida
        if(  ((l[3].charAt(0)!= 'N') && (l[3].charAt(0)!= 'P')) || (Integer.parseInt(l[6])>3) || (Integer.parseInt(l[6])<1) || (Integer.parseInt(l[2])>200) || (Integer.parseInt(l[2])<0) ||  (Integer.parseInt(l[5])>12) || (Integer.parseInt(l[5])<1) || (Double.parseDouble(l[1])<0.00) || (Double.parseDouble(l[1])>999.99) ){
            i=1;
        }
        
        //verifica produtos validos
        
        if((i== 0 && cp.getCatprod().contains(l[0]))==true);
        else  i=1;
        
        //verifica clientes validos 
        
        if((i==0 && cl.getCatClie().contains(l[4]))==true);
        else i=1;
       
        
        if(i==0) {
       
        r=true;
        
        }
        return r;
}
    
    public Venda getVenda_valida(String v){
        String[] l= v.split("\\s+");
        this.p=l[0];
        this.preco=Double.parseDouble(l[1]);
        this.quant=Integer.parseInt(l[2]);
        this.promnorm=l[3].charAt(0);
        this.c=l[4];
        this.mes=Integer.parseInt(l[5]);
        this.filial=Integer.parseInt(l[6]);
        return this;
    }
    
    public Venda clone() {
        return new Venda(this);
    }
    
    
     /**
     *TO STRING
     */
    public String toString(){
        StringBuffer sb = new StringBuffer();
        sb.append(this.p).append(" ");  
        sb.append(this.preco).append(" ");  
        sb.append(this.quant).append(" "); 
        sb.append(this.promnorm).append(" ");  
        sb.append(this.c).append(" ");  
        sb.append(this.mes).append(" ");  
        sb.append(this.filial).append(" ");  
       return sb.toString();
    }
    
     /**
     *HASHCODE
     */
    
    public int hashCode() {
    return Arrays.hashCode( new Object[] { p,preco,quant,promnorm,c,mes,filial} );
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
        Venda that = (Venda) obj;
        return (this.p.equals(that.getP())
                && this.preco==that.getPreco()
                && this.quant==that.getQuant()
                && this.promnorm==that.getPromnorm()
                && this.c.equals(that.getC())
                && this.mes==that.getMes()
                && this.filial==that.getFilial());
                
               
    }
}
