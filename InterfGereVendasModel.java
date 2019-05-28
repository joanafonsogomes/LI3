
package liprojeto;

import java.util.ArrayList;


public interface InterfGereVendasModel {
     InterfGereVendasModel createData();
     CatProdutos getCp();
     void setCp(CatProdutos cp);
    CatClientes getCliee();
     void setCliee(CatClientes clie);
     Faturacao getF();
     void setF(Faturacao f);
     
}
