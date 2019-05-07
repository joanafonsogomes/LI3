public class Buffers
{
    /*instance variables - replace the example below with your own*/
    
    public static void main(String[] args)throws Exception{
        File clientes = new File("/home/joana/Desktop/LI3_BLUEJ/Clientes.txt");
        BufferedReader br1 = new BufferedReader(new FileReader(clientes));
        
        File produtos = new File("/home/joana/Desktop/LI3_BLUEJ/Produtos.txt");
        BufferedReader br2 = new BufferedReader(new FileReader(produtos));
        
        File vendas1m = new File("/home/joana/Desktop/LI3_BLUEJ/Vendas_1M.txt");
        BufferedReader br3 = new BufferedReader(new FileReader(vendas1m));
        
        File vendas3m = new File("/home/joana/Desktop/LI3_BLUEJ/Vendas_3M.txt");
        BufferedReader br4 = new BufferedReader(new FileReader(vendas3m));
        
        File vendas5m = new File("/home/joana/Desktop/LI3_BLUEJ/Vendas_5M.txt");
        BufferedReader br5 = new BufferedReader(new FileReader(vendas5m));
        
        /*String st;
        while((st = br.readLine()) != null){
            System.out.println(st);
        }*/
    }

}