
import java.util.Objects;

public class Venda {
   
 //atributos
    private String produto;
    private float preco;
    private int quant;
    private char promonorm;
    private String cliente;
    private int mes;
    private int filial;

 //getters
    public String getProduto() {
        return produto;
    }

    public float getPreco() {
        return preco;
    }

    public int getQuant() {
        return quant;
    }

    public char getPromonorm() {
        return promonorm;
    }

    public String getCliente() {
        return cliente;
    }

    public int getMes() {
        return mes;
    }

    public int getFilial() {
        return filial;
    }

    //toString
    public String toString() {
        return "Venda{" + "produto=" + produto + ", preco=" + preco + ", quant=" + quant + ", promonorm=" + promonorm + ", cliente=" + cliente + ", mes=" + mes + ", filial=" + filial + '}';
    }

   //equals
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Venda other = (Venda) obj;
        if (Float.floatToIntBits(this.preco) != Float.floatToIntBits(other.preco)) {
            return false;
        }
        if (this.quant != other.quant) {
            return false;
        }
        if (this.promonorm != other.promonorm) {
            return false;
        }
        if (this.mes != other.mes) {
            return false;
        }
        if (this.filial != other.filial) {
            return false;
        }
        if (!Objects.equals(this.produto, other.produto)) {
            return false;
        }
        if (!Objects.equals(this.cliente, other.cliente)) {
            return false;
        }
        return true;
    }
    
   
}

