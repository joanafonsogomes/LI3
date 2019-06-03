
package liprojeto;

import java.io.Serializable;


public class ParStringInt implements Serializable{
    String x; int y;


public ParStringInt(){
      this.x = new String();
      this.y=0;
}

public ParStringInt(String x, int y){
    this.x=x;
    this.y=y;
}

public ParStringInt(ParStringInt outrogv){
       this.x = outrogv.getX();
       this.y=outrogv.getY();
     
    }

    public String getX() {
        return x;
    }

    public void setX(String x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }



}