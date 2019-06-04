package liprojeto;
 
 

import java.io.IOException;
import java.io.Serializable;
import java.util.SortedSet;



public class GereVendasView implements InterfGereVendasView, Serializable{
    
  
    private Menu Menu_Consult_Inter;
    private Menu Menu_Consult_Est; 
    private Menu Menu_inicial;
    
    
    
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
                                 "6",
                                 "7",
                                 "8",
                                 "9",
                                 "10",                                
                                 "Sair."
                                 };
        
        
      
  
       this.Menu_Consult_Est= new Menu(opcoes_consultasestatisticas);
       this.Menu_Consult_Inter=new Menu(opcoes_consultasinteractivas);
       this.Menu_inicial=new Menu(opcoes_menuinicial);
    
       
       
    }
    
   

    
    public void run (GereVendasController r) {
    
    
        
    System.out.println("\n**********************");
    System.out.println("BEM VINDO À GESTVENDAS!");
    System.out.println("**********************\n");
    do {
            Menu_inicial.executa();
            switch (Menu_inicial.getOpcao()) {
                case 1: trataconsultas_est(r);
                case 2: trataconsultas_int(r);
                
            }
        } while (Menu_inicial.getOpcao()!=0); // A opção 0 é usada para sair do menu.
        try {
            r.guardaEstadoo();
        }
        catch (IOException e) {
            e.printStackTrace();
            System.out.println("Ops! Não consegui gravar os dados!");
        } finally {
        System.out.println("Até breve!..."); 
        System.exit(0);}
        
    }
    
 
    
    public void sair(GereVendasController r){
       System.out.println("\n**********************");
       System.out.println("BEM VINDO À GESTVENDAS!");
       System.out.println("**********************\n");
       do {
            Menu_inicial.executa();
            switch (Menu_inicial.getOpcao()) {
                case 1: trataconsultas_est(r);
                case 2: trataconsultas_int(r);
                case 3: sair(r);
            }
        } while (Menu_inicial.getOpcao()!=0); // A opção 0 é usada para sair do menu.
        try {
            r.guardaEstadoo();
        }
        catch (IOException e) {
            System.out.println("Ops! Não consegui gravar os dados!");
        }finally{
        System.out.println("Até breve!..."); 
        System.exit(0);}
    }
    
    
    public void trataconsultas_est(GereVendasController r){
        do {
            Menu_Consult_Est.executa();
            switch (Menu_Consult_Est.getOpcao()) {
                case 1: trataconsulta1();
                case 2: ;
                case 3: ;
                case 4: ;
                case 5: ;
                case 6: sair(r);
            }
        } while (Menu_Consult_Est.getOpcao()!=0); // A opção 0 é usada para sair do menu.
        try {
            r.guardaEstadoo();
        }
        catch (IOException e) {
            System.out.println("Ops! Não consegui gravar os dados!");
        } finally{
        System.out.println("Até breve!..."); 
        System.exit(0);}
    }
    
                
    public void trataconsultas_int(GereVendasController r){
        do {
            Menu_Consult_Inter.executa();
            switch (Menu_Consult_Inter.getOpcao()) {
                case 1: ;
                case 2: ;
                case 3: ;
                case 4: trataquerie4(r);
                case 5: trataquerie5(r);
                case 6: ;
                case 7: trataquerie7(r);
                case 8: trataquerie8(r);
                case 9: trataquerie9(r);
                case 10:trataquerie10(r);
                case 11: sair(r);
            }
        } while (Menu_Consult_Inter.getOpcao()!=0); // A opção 0 é usada para sair do menu.
        try {
            r.guardaEstadoo();
        }
        catch (IOException e) {
            System.out.println("Ops! Não consegui gravar os dados!");
        }  finally{
        System.out.println("Até breve!..."); 
        System.exit(0);
        }
    }
     
   //CONSULTAS INTERATIVAS
    
    
    //querie4
   public void trataquerie4(GereVendasController r){
       int rr,rt; Crono cro =new Crono(); Input i = new Input();
       double rs;
       System.out.println("Insira o código do produto");
       String prod=i.lerString();
       System.out.println("Insira o mês desejado");
       int x=i.lerInt();
       cro.start();
       rr=r.numero_de_vezes_produto_comprado_pormes(prod, x);
       rs=r.totalfaturado_pormes(prod, x);
       rt=r.numero_clientes_pormes(prod, x);
       System.out.print("Tempo de execução: ");
       cro.stop();
       String s=cro.print();
       System.out.println(s);
       System.out.println(s);
       System.out.println("\n************************************************************************************************");
       System.out.println("O produto " + prod + " no mês " + x + " foi comprado "+ rr + " vezes");
       System.out.println("O número de clientes diferentes que o comprou neste mês foi "+rt);
       System.out.println("O seu total faturado neste mês é " + rs +" euros");
       System.out.println("\n************************************************************************************************");
       String a;
       System.out.println("Carregue em qualquer tecla para voltar ao menu!"); 
       a=i.lerString();
       trataconsultas_int(r);
   }
   
   
   //querie5
   public void trataquerie5 (GereVendasController r){
       Crono cro =new Crono(); Input i = new Input();
       System.out.println("Insira o código do cliente:");
       String clie=i.lerString();
       System.out.println("\n************************************************************************************************");
       cro.start();
       SortedSet<ParVendaDouble> ss=r.querie5(clie);
       System.out.print("Tempo de execução: ");
       cro.stop();
       String s=cro.print();
       System.out.println(s);
       System.out.println("Lista dos produtos que foram mais comprados pelo cliente " + clie +" e a sua quantidada respetiva:");
       for(ParVendaDouble ll : ss){
       System.out.print(ll.x.getP() + " ");
       System.out.println(ll.y);
       }
       System.out.println("\n************************************************************************************************");
       String a;
       System.out.println("Carregue em qualquer tecla para voltar ao menu!"); 
       a=i.lerString();
       trataconsultas_int(r);
   }
   
   
   //querie7
   
   public void trataquerie7 (GereVendasController r){
       Input i = new Input();
       Crono cro =new Crono();
       System.out.println("Insira o número da filial a que pretende aceder");
       int x=i.lerInt();
       System.out.println("\n************************************************************************************************");
       cro.start();
       SortedSet<Venda> ss =r.querie7(x);
       System.out.print("Tempo de execução: ");
       cro.stop();
       String s=cro.print();
       System.out.println(s);
       int g=0;
       for(Venda ii : ss){
       if((g<= 2)){
       System.out.println(ii.getC());
       g++;}
       else break;
       }
       System.out.println("\n************************************************************************************************");
       String a;
       System.out.println("Carregue em qualquer tecla para voltar ao menu!"); 
       a=i.lerString();
       trataconsultas_int(r);
   
   }
   //querie8
   public void trataquerie8 (GereVendasController r){
       Input i = new Input();
       Crono cro =new Crono();
       System.out.println("Insira o número de clientes pretendido:");
       int x=i.lerInt();
       System.out.println("\n************************************************************************************************");
       cro.start();
       r.códigos_clientes_numero_produtos(x);
       System.out.print("Tempo de execução: ");
       cro.stop();
       String s=cro.print();
       System.out.println(s);
       String a;
       System.out.println("Carregue em qualquer tecla para voltar ao menu!"); 
       a=i.lerString();
       trataconsultas_int(r);
   }
   
   //querie 9
   
   public void trataquerie9 (GereVendasController r){
       Crono cro =new Crono(); Input i = new Input();
       System.out.println("Insira o código do produto:");
       String p=i.lerString();
       System.out.println("Insira o número de clientes pretendido:");
       int x=i.lerInt();
       System.out.println("\n************************************************************************************************");
       cro.start(); 
       SortedSet<ParVendaDouble> ss= r.querie9(p, x);
       System.out.print("Tempo de execução: ");
       cro.stop();
       String s=cro.print();
       System.out.println(s);
       int g=0;
       System.out.println("Conjunto dos " + x+ " clientes que mais compraram o produto e o respetivo valor gasto:");
       for(ParVendaDouble ll : ss){
       if((g< x)){
       System.out.print(ll.getX().getC() + " ");
       System.out.println(ll.y + " euros");
       g++;}
       else break;
       }
       System.out.println("\n************************************************************************************************");
       String a;
       System.out.println("Carregue em qualquer tecla para voltar ao menu!"); 
       a=i.lerString();
       trataconsultas_int(r);
   }
   
   
   //querie 10
   
   public void trataquerie10(GereVendasController r){
     Crono cro =new Crono(); Input i = new Input(); double [][] dd =new double[13][4];
       System.out.println("Insira o código do produto:");
       String p=i.lerString();
       System.out.println("\n************************************************************************************************");
       cro.start();
        for(int l=1;l<=12;l++){
        for(int f=1;f<=3;f++){
        dd[l][f]=r.querie10(p,l,f);
        } 
       }
       System.out.print("Tempo de execução: ");
       cro.stop();
       String s=cro.print();
       System.out.println(s);
       System.out.println("Faturação total do produto " + p +":");
       //System.out.printf("%-100.2s","Filial1","Filial2","Filial3");
       System.out.println();
       for(int l=1;l<=12;l++){
        for(int f=1;f<=3;f++){
        System.out.printf("%-30.2f",dd[l][f]);
        } 
        System.out.println();
       }
       System.out.println("\n************************************************************************************************");
       String a;
       System.out.println("Carregue em qualquer tecla para voltar ao menu!"); 
       a=i.lerString();
       trataconsultas_int(r);
}
   
  
   
   
   //CONSULTAS ESTATISTICAS
   
   public void trataconsulta1(){
       
   }
        
    }     
    

