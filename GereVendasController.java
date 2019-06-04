package liprojeto;
 


import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Serializable;
import java.util.SortedSet;
import java.util.TreeSet;


public class GereVendasController implements InterfGereVendasController, Serializable{
      InterfGereVendasModel m;
      InterfGereVendasView v;
    
    public void setModel (InterfGereVendasModel m){
        this.m = m;
    }
    
    
    public void setView(InterfGereVendasView v){
        this.v =v;
        
    }
    
    public void startController(){
        v.run(this);
    } 
    
    public void guardaEstadoo() throws FileNotFoundException, IOException{
            m.guardaEstado();
        }
        
        //querie 4
        public int numero_de_vezes_produto_comprado_pormes(String prod, int x){
           return m.numero_clientes_pormes(prod, x);
        }
        
        
       public double totalfaturado_pormes(String prod, int x){
           return m.totalfaturado_pormes(prod, x);
       }
       
       public int numero_clientes_pormes(String prod, int x){
        return numero_clientes_pormes(prod, x);
       }
       
       
       
        //querie5
       public SortedSet<ParVendaDouble> querie5(String clie){
           SortedSet<ParVendaDouble> ss=  m.listaord(clie);
           return ss;
       }
        
        //querie7
       public SortedSet<Venda> querie7(int x){
        SortedSet<Venda> ss = new TreeSet<>();
        if(x== 1) ss= m.lista_paracadafilial1();
        else if(x== 2) ss= m.lista_paracadafilial2();
        else if(x== 3) ss= m.lista_paracadafilial3();
        return ss;
       }
        
        //querie 8
        public void códigos_clientes_numero_produtos(int x){
           m.códigos_clientes_numero_produtos(x); 
        }
        
        //querie 9
        public SortedSet<ParVendaDouble> querie9(String p, int x){
            return m.clientes_valorgasto(p, x);
        }
        
        
        //querie 10
        public double querie10(String produto, int mes, int filial){
           return m.fact_tot(produto, mes, filial);
        }
    
}
