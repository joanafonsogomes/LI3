package liprojeto;
 


import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Serializable;
import java.util.SortedSet;


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
       public void listaord(String clie){
        m.listaord(clie);
       }
        
        //querie7
       public void lista_paracadafilial1(){
        m.lista_paracadafilial1();
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
