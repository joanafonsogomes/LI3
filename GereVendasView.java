
package liprojeto;
 

import java.io.IOException;
import java.io.Serializable;


public class GereVendasView implements InterfGereVendasView, Serializable{
   
  
    private Menu Menu_Consult_Inter;
    private Menu Menu_Consult_Est; 
    private Menu Menu_inicial;
    
    GereVendasModel m = new GereVendasModel();
    GestVendas r = new GestVendas(m.getCp(),m.getCliee(),m.getF());
    
    
    //CONSTRUTOR: CRIA OS MENUS
    public GereVendasView() throws IOException{
        
       
        // Criar o menu 
        String[] opcoes_menuinicial={"Consultas Estatísticas.",
                                    "Consultas Interactivas.",
                                     };
        
        
        String[] opcoes_consultasestatisticas = {"Consulta dos dados do ficheiro de vendas.",
                           "Consulta do número total de compras por mês.",
                           "Consulta da faturação total por mês para cada filial.",
                           "Consulta da faturação total global.",
                           "Consulta do número de clientes que compraram em cada mês para cada filial.",
                           "Sair."
                           };
        
        String[] opcoes_consultasinteractivas = {"Consulta da lista ordenada alfabeticamente com os códigos dos "
                + "produtos nunca comprados e o seu respectivo total.",
                                 "Consulta do número total global de vendas realizadas e o número total de clientes distintos que as fizeram",
                                 "blablabla.",
                                 "blablabla.",
                                 "blaablabla.",
                                 "Sair."
                                 };
        
        
      
  
       this.Menu_Consult_Est= new liprojeto.Menu(opcoes_consultasestatisticas);
       this.Menu_Consult_Inter=new liprojeto.Menu(opcoes_consultasinteractivas);
       this.Menu_inicial=new liprojeto.Menu(opcoes_menuinicial);
    
       
       
       
       
    }
    
    

    
    public void run() {
        
    
        
    System.out.println("\n**********************");
    System.out.println("BEM VINDO À GESTVENDAS!");
    System.out.println("**********************\n");
    do {
            Menu_inicial.executa();
            switch (Menu_inicial.getOpcao()) {
                case 1: trataconsultas_est();
                case 2: trataconsultas_int();
                
            }
        } while (Menu_inicial.getOpcao()!=0); // A opção 0 é usada para sair do menu.
        try {
            this.r.guardaEstado("gestVendas.dat");
        }
        catch (IOException e) {
            System.out.println("Ops! Não consegui gravar os dados!");
        }
        System.out.println("Até breve!...");  
    }
    
    public void sair(){
       System.out.println("\n**********************");
       System.out.println("BEM VINDO À GESTVENDAS!");
       System.out.println("**********************\n");
       do {
            Menu_inicial.executa();
            switch (Menu_inicial.getOpcao()) {
                case 1: trataconsultas_est();
                case 2: trataconsultas_int();
                case 3: sair();
            }
        } while (Menu_inicial.getOpcao()!=0); // A opção 0 é usada para sair do menu.
        try {
            this.r.guardaEstado("gestVendas.dat");
        }
        catch (IOException e) {
            System.out.println("Ops! Não consegui gravar os dados!");
        }
        System.out.println("Até breve!..."); 
    }
    
    
    public void trataconsultas_est(){
        do {
            Menu_Consult_Est.executa();
            switch (Menu_inicial.getOpcao()) {
                case 1: ;
                case 2: ;
                case 3: ;
                case 4: ;
                case 5: ;
                case 6: sair();
            }
        } while (Menu_Consult_Est.getOpcao()!=0); // A opção 0 é usada para sair do menu.
        try {
            this.r.guardaEstado("gestVendas.dat");
        }
        catch (IOException e) {
            System.out.println("Ops! Não consegui gravar os dados!");
        }
        System.out.println("Até breve!..."); 
    }
    
                
    public void trataconsultas_int(){
        do {
            Menu_Consult_Inter.executa();
            switch (Menu_Consult_Inter.getOpcao()) {
                case 1: ;
                case 2: ;
                case 3: ;
                case 4: ;
                case 5: ;
                case 6: sair();
            }
        } while (Menu_Consult_Est.getOpcao()!=0); // A opção 0 é usada para sair do menu.
        try {
            this.r.guardaEstado("gestVendas.dat");
        }
        catch (IOException e) {
            System.out.println("Ops! Não consegui gravar os dados!");
        }
        System.out.println("Até breve!..."); 
    }
       
   
        
    }     
    

