
package liprojeto;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Serializable;

import java.util.Scanner;
import java.util.SortedSet;


//faltar arranjar clientes
public class GereVendasModel implements InterfGereVendasModel, Serializable{
    CatProdutos cp =new CatProdutos();
    CatClientes clie=new CatClientes();
    Faturacao f = new Faturacao();
    Filial fil =new Filial();
    
   

    public CatProdutos getCp() {
        return cp;
    }

    public void setCp(CatProdutos cp) {
        this.cp = cp;
    }

    public CatClientes getCliee() {
        return clie;
    }

    public void setCliee(CatClientes clie) {
        this.clie = clie;
    }

    public Faturacao getF() {
        return f;
    }

    public void setF(Faturacao f) {
        this.f = f;
    }
    
    public Filial getFil() {
        return fil;
    }

    public void setFil(Filial fil) {
        this.fil = fil;
    }
    
    
   
    
    public InterfGereVendasModel createData(){
        
           GestVendas gv=new GestVendas();
    
        try {
            gv.carregaEstado("gestVendas.dat");
            this.cp=gv.getCp();
            this.clie=gv.getClie();
            this.f=gv.getF();
         
        }
        catch (FileNotFoundException e) {
            System.out.println("Parece que é a primeira utilização...");  
            this.cria();
        }catch (IOException e) {
            System.out.println("Ops! Erro de leitura!");     
        }
        catch (ClassNotFoundException e) {
            System.out.println("Ops! Formato de ficheiro de dados errado!");
        }
    
    return this;
        
}
 
        
        public InterfGereVendasModel cria(){
   
        InputStream inputStream = GereVendasModel.class.getResourceAsStream("Produtos.txt");
        try(BufferedReader br = new BufferedReader(new InputStreamReader(inputStream))) {
        for(String ss; (ss = br.readLine()) != null; ) {
            Produto p = new Produto();
            if( p.setProd_valido(ss)==true){
            this.cp.addprod(ss);
            
        }
            else;
            
        } br.close();
        } catch (IOException e) {
            System.out.println("ERRO A LER FICHEIRO");
            
        };
        
      
        InputStream inputStream1 = GereVendasModel.class.getResourceAsStream("Clientes.txt");
        try(BufferedReader br1 = new BufferedReader(new InputStreamReader(inputStream1))) {
        for(String ss; (ss = br1.readLine()) != null; ) {
           Cliente c =new Cliente(ss);  
        if(c.setClie_valido(ss)==true)
            this.clie.addclie(ss);
        
        else;
        } br1.close(); 
        } catch (IOException e) {
            System.out.println("ERRO A LER FICHEIRO");
        }
        
 
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite o nome do ficheiro de vendas a que pretende aceder.");
        String input=sc.nextLine();
        InputStream inputStream2 = GereVendasModel.class.getResourceAsStream(input);
        try(BufferedReader br2 = new BufferedReader(new InputStreamReader(inputStream2))) {
        for(String ss; (ss = br2.readLine()) != null; ) {
           Venda ven =new Venda();
         
           if(ven.isVenda_valida(ss, cp, clie)){ 
             
               ven= ven.getVenda_valida(ss);
               
               this.f.addFaturacao(ven);
               if(ven.getFilial()==1){
                   this.fil.addFilial1(ven.clone());
               }
               else if(ven.getFilial()==2){
                   this.fil.addFilial2(ven.clone());
               }
               if(ven.getFilial()==3){
                   this.fil.addFilial3(ven.clone());
                   
               }
              
           }   
         else;      
           
        } br2.close();
        } catch (IOException e) {
            System.out.println("ERRO A LER FICHEIRO");
        }
         
        return this;
        
    }
}
