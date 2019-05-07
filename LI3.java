
package li3;

/**
 *
 * @author susanamarques
 */
public class LI3 {
 
    
    public static void main(String[] args) {
         InterGestVendasModel model = new GestVendasModel();
         model.createData();
         
         if(model==Null) {
             System.out.println("Erro Inicialização"); 
             System.exit(0);
         }
             InterGestVendasView view = new GestVendasView();
              InterGestVendasController control = new GestVendasController();
              control.setModel(model);
              control.setView(view);
              control.startController();
              System.exit(0);
    }
    
}
