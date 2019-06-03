
package liprojeto;

import java.io.Serializable;


public class ParVendaDouble implements Serializable{
   Venda x;
   double y;

public ParVendaDouble(){
      this.x = new Venda();
      this.y=0.0;
}

public ParVendaDouble(Venda x, double y){
    this.x=x;
    this.y=y;
}

public ParVendaDouble(ParVendaDouble outrogv){
       this.x = outrogv.getX();
       this.y=outrogv.getY();
     
    }

    public Venda getX() {
        return x;
    }

    public void setX(Venda x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }



}