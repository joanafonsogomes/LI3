
package liprojeto;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;



public class GestVendas implements InterfGestVendas, Serializable{
    CatProdutos cp;
    CatClientes clie;
    Faturacao f;
    
    public GestVendas (){
        this.cp =new CatProdutos();
        this.clie = new CatClientes();
        this.f= new Faturacao();
    }
 
    public GestVendas (CatProdutos cp, CatClientes clie, Faturacao f){
        this.cp =cp;
        this.clie=clie;
        this.f=f;
    }
   
    

    public CatProdutos getCp() {
        return cp;
    }

    public void setCp(CatProdutos cp) {
        this.cp = cp;
    }

    public CatClientes getClie() {
        return clie;
    }

    public void setClie(CatClientes clie) {
        this.clie = clie;
    }

    public Faturacao getF() {
        return f;
    }

    public void setF(Faturacao f) {
        this.f = f;
    }
    
    
    
        
/**
     * Método que guarda em ficheiro de objectos o objecto que recebe a mensagem.
     */
    public void guardaEstado(String nome) throws FileNotFoundException, IOException {
      FileOutputStream fos = new FileOutputStream(nome);
      ObjectOutputStream oos = new ObjectOutputStream(fos);
      oos.writeObject(this);
      oos.flush ();
      oos.close();
    }
    
     /**
     * Método que carrega o ficheiro outrora guardado
     */
    public static GestVendas carregaEstado(String nome) throws FileNotFoundException, IOException, ClassNotFoundException {
        FileInputStream fis= new FileInputStream(nome);
        ObjectInputStream ois= new ObjectInputStream(fis);
        GestVendas h =(GestVendas) ois.readObject();
        ois.close();
        return h;
    }
    
    
  //querie1  
    
    
    
    
    
}
