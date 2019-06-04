package liprojeto;
 

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.List;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;




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
        
       
    
        try {
            this.carregaEstado("gestVendas.dat");
         
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
               
               this.f.addFaturacao(ven.clone());
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
        
        
            
/**
     * Método que guarda em ficheiro de objectos o objecto que recebe a mensagem.
     */
    
    public void guardaEstado() throws FileNotFoundException, IOException {
      FileOutputStream fos = new FileOutputStream("gestVendas.dat");
      ObjectOutputStream oos = new ObjectOutputStream(fos);
      oos.writeObject(this);
      oos.flush ();
      oos.close();
    }
    
     /**
     * Método que carrega o ficheiro outrora guardado
     */
    public static InterfGereVendasModel carregaEstado(String nome) throws FileNotFoundException, IOException, ClassNotFoundException {
        FileInputStream fis= new FileInputStream(nome);
        ObjectInputStream ois= new ObjectInputStream(fis);
        InterfGereVendasModel h =(InterfGereVendasModel) ois.readObject();
        ois.close();
        return h;
    }
    

//querie 4 -- falta arranjar os clientes diferentes-- a cena dos pares(triplos)
    
    public int numero_de_vezes_produto_comprado_pormes(String x, int mes){
         int i=0;
         if(f.getFaturacao().containsKey(x)){
             List<Venda> v=f.getFaturacao().get(x);
             for(Venda ve: v){
             if(ve.getMes()==mes) i=i+ ve.getQuant();
         }}
         else ;
         return i;
     }

    
    public double totalfaturado_pormes(String x, int mes){
    double i=0;
         if(f.getFaturacao().containsKey(x)){
             List<Venda> v=f.getFaturacao().get(x);
             for(Venda ve: v){
             if(ve.getMes()==mes) i=i+ ve.getQuant()* ve.getPreco();
         }}
         else ;
         return i;
     }

    
    public int numero_clientes_pormes (String x, int mes) {
    int i=0;
    for( List<Venda> s:fil.getCompras_fil1().values()){
    for( Venda v :s){
        if(v.getP().equals(x) && v.getMes()==mes){
            i++; 
            
        } }}
    for( List<Venda> s:fil.getCompras_fil2().values()){
    for( Venda v :s){
        if(v.getP().equals(x) && v.getMes()==mes){
            i++; 
        } 
    }}
    for( List<Venda> s:fil.getCompras_fil3().values()){
    for( Venda v :s){
        if(v.getP().equals(x) && v.getMes()==mes){
            i++; 
        } 
    }}
    return i;
}
             
//querie 5 --terminada 
    
    public SortedSet<ParVendaDouble> listaord(String c){
    SortedSet<ParVendaDouble> ss= new TreeSet<>(new ParVendaDoubleComparator());
    if(fil.getCompras_fil1().containsKey(c)){
             List<Venda> v=fil.getCompras_fil1().get(c);
             for(Venda ve: v){
             ss.add(new ParVendaDouble(ve,ve.getQuant()));
         }}
    
    if(fil.getCompras_fil2().containsKey(c)){
             List<Venda> v=fil.getCompras_fil2().get(c);
             for(Venda ve: v){
             ss.add(new ParVendaDouble(ve,ve.getQuant()));
         }}
    
    if(fil.getCompras_fil3().containsKey(c)){
             List<Venda> v=fil.getCompras_fil3().get(c);
             for(Venda ve: v){
             ss.add(new ParVendaDouble(ve,ve.getQuant()));
         }}
    
    
    
     return ss;
}

  //querie 7--terminada
  
    
    public SortedSet<Venda>  lista_paracadafilial1(){
    SortedSet<Venda> ss= new TreeSet<>(new VendaComparator().reversed());
    for( List<Venda> s: fil.getCompras_fil1().values()){
    for( Venda v :s){
        ss.add(v); 
            
        } }
    
    int g=0;
    for(Venda i : ss){
    if((g<= 2)){
    System.out.println(i);
    g++;}
    else break;
    }  
    return ss;
}
    
    public SortedSet<Venda>  lista_paracadafilial2(){
    SortedSet<Venda> ss= new TreeSet<>(new VendaComparator().reversed());
    for( List<Venda> s: fil.getCompras_fil2().values()){
    for( Venda v :s){
        ss.add(v); 
            
        } }
    
    int g=0;
    for(Venda i : ss){
    if((g<= 2)){
    System.out.println(i);
    g++;}
    else break;
    }  
    return ss;
}


    
    public SortedSet<Venda>  lista_paracadafilial3(){
    SortedSet<Venda> ss= new TreeSet<>(new VendaComparator().reversed());
    for( List<Venda> s: fil.getCompras_fil3().values()){
    for( Venda v :s){
        ss.add(v); 
            
        } }
    
    int g=0;
    for(Venda i : ss){
    if((g<= 2)){
    System.out.println(i);
    g++;}
    else break;
    }  
   return ss;
}

//querie 8 --falta calculo do numero de produtos--estamos com problemas
    
    public void códigos_clientes_numero_produtos (int x){
    int i=0; TreeSet<String> prod_util=new TreeSet<>();
    SortedSet<ParStringInt> ss =new TreeSet<>(new ParStringIntComparator().reversed());
    //filial1
    for( List<Venda> s: fil.getCompras_fil1().values()){
    for( Venda v :s){
        if(prod_util.contains( v.getP()));
        else{
        ss.add(new ParStringInt(v.getC(),i+1));  
        prod_util.add(v.getP());
    }}
        
}
    //filial 2
    for( List<Venda> s: fil.getCompras_fil2().values()){
    for( Venda v :s){
        if(prod_util.contains( v.getP()));
        else{
        ss.add(new ParStringInt(v.getC(),i++));  
        prod_util.add(v.getP());
    }}
        
}
    //filial 3
    for( List<Venda> s: fil.getCompras_fil1().values()){
    for( Venda v :s){
        if(prod_util.contains( v.getP()));
        else{
        ss.add(new ParStringInt(v.getC(),i++));  
        prod_util.add(v.getP());
    }}
        
}
    
    int g=0;
    for(ParStringInt ll : ss){
    if((g< x)){
    System.out.println(ll.x);
    System.out.println(ll.y);
    g++;}
    else break;
    } 
    
    
} 

 //métodos para a querie 9--terminada
   
  
    
   public SortedSet<ParVendaDouble> clientes_valorgasto(String p, int y) {
  
    SortedSet<ParVendaDouble> ss= new TreeSet<>(new ParVendaDoubleComparator());
    
    for( List<Venda> s:fil.getCompras_fil1().values()){
    for( Venda v :s){
        if(v.getP().equals(p)){
            ss.add(new ParVendaDouble(v,v.getPreco()*v.getQuant()));
            
        } }}
    
    for( List<Venda> s:fil.getCompras_fil2().values()){
    for( Venda v :s){
        if(v.getP().equals(p)){
            ss.add(new ParVendaDouble(v,v.getPreco()*v.getQuant()));
            
        } }}
    
    for( List<Venda> s:fil.getCompras_fil3().values()){
    for( Venda v :s){
        if(v.getP().equals(p)){
            ss.add(new ParVendaDouble(v,v.getPreco()*v.getQuant()));
            
        } }}
    
    
    return ss;
}
    
    
   
   //métodos para a querie 10--terminada
    
   public double fact_tot(String produto, int mes, int filial){
      double fat=0.0;
      
      //filial1
      if(filial==1){
      for( List<Venda> s:fil.getCompras_fil1().values()){
      for( Venda v :s){
      if(v.getP().equals(produto) && v.getMes()==mes){
            fat=fat + v.getQuant() * v.getPreco();
            
        } }}
      
      }
      
      //filial2
      else if(filial==2){
      for( List<Venda> s:fil.getCompras_fil2().values()){
      for( Venda v :s){
      if(v.getP().equals(produto) && v.getMes()==mes){
            fat=fat + v.getQuant() * v.getPreco();
            
        } }}
      
      
   }
   
     //filial3
     else if(filial==3){
      for( List<Venda> s:fil.getCompras_fil3().values()){
      for( Venda v :s){
      if(v.getP().equals(produto) && v.getMes()==mes){
            fat=fat + v.getQuant() * v.getPreco();
            
        } }}
      
      
   } 
   return fat;}
    
     
}
