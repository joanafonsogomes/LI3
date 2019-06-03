
package liprojeto;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.SortedSet;


public interface InterfGereVendasModel  {

    SortedSet<ParVendaDouble> clientes_valorgasto(String p, int y);

    InterfGereVendasModel createData();

    InterfGereVendasModel cria();

    //querie 8 --falta calculo do numero de produtos
    void códigos_clientes_numero_produtos(int x);

    //querie 10--falta colocar na view
    double fact_tot(String produto, int mes, int filial);

    CatClientes getCliee();

    CatProdutos getCp();

    Faturacao getF();

    Filial getFil();

    /**
     * Método que guarda em ficheiro de objectos o objecto que recebe a mensagem.
     */
    void guardaEstado() throws FileNotFoundException, IOException;

    //querie 7--falta colocar na view
    void lista_paracadafilial1();

    void lista_paracadafilial2();

    void lista_paracadafilial3();

    //querie 5 --falta colocar na view
    void listaord(String c);

    int numero_clientes_pormes(String x, int mes);

    //querie 4 -- falta arranjar os clientes diferentes-- a cena dos pares(triplos)
    int numero_de_vezes_produto_comprado_pormes(String x, int mes);

    void setCliee(CatClientes clie);

    void setCp(CatProdutos cp);

    void setF(Faturacao f);

    void setFil(Filial fil);

    double totalfaturado_pormes(String x, int mes);

   
}
