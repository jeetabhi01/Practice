
import java.util.Scanner;
public class StockClient {
    public static void main(String[] args){
        Scanner console = new Scanner(System.in);
        System.out.println("Enter the symbol of the stock");
        Stock amazon = new Stock(console.next());
        amazon.purchase(23, 100.50);
        amazon.purchase(45, 39.78);
        System.out.println("Enter the current price per share : ");
        System.out.println("The profit is "+ amazon.getProfit(console.nextDouble()));
        console.close();
    }
}
