package liprojeto;

import java.io.Serializable;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Menu implements Serializable{
    
private List<String> opcoes;
private int op;
    

/**
*CONSTRUTOR VAZIO
*/
 public Menu(String [] opcoes) {
        this.opcoes = Arrays.asList(opcoes);
        this.op = -1;
    }

 public int getOpcao() {
        return this.op;
    }
 


/**
* Método para apresentar o menu e ler opção.
*/
    public void executa() {
        do {
            showMenu();
            this.op = lerOpcao();
        } while (this.op == -1);
    }
  
    /** Apresentar o menu */
    private void showMenu() {
        System.out.println("\n      MENU:");
        System.out.println("**********************");
        System.out.println("**********************\n");
        System.out.println("Escolha a funcionalidade a que pretende aceder:"); 
        for (int i=0; i<this.opcoes.size(); i++) {
            System.out.print(i+1);
            System.out.print(" - ");
            System.out.println(this.opcoes.get(i));
        }
        System.out.println("Para fechar e guardar a aplicacao digite 0.");
    }
    
    /** Ler uma opção válida */
    private int lerOpcao() {
        int op; 
        Scanner is = new Scanner(System.in);
        
        System.out.print("Opção: ");
        try {
            op = is.nextInt();
        }
        catch (InputMismatchException e) { //caso não tenhamos escrito um inteiro
            op = -1;
        }
        if (op<0 || op>this.opcoes.size()) {
            System.out.println("Opção Inválida!!!");
            op = -1;
        }
        return op;
    }





}