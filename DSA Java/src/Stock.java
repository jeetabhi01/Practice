public class Stock{
	private String symbol;
	private int total_shares;
	private double total_cost;

	public Stock(String thesym){
		if(thesym == null){
			throw new NullPointerException();
		}
		this.symbol = thesym;
		this.total_shares =0;
		this.total_cost = 0.0;
	}

	public double getProfit(double pricePerShare){
		if(pricePerShare < 0){
			throw new IllegalArgumentException("price per share cannot be negative");
		}
		return total_shares * pricePerShare - total_cost ;
	}


	public void purchase(int shares, double pricePerShare){
		total_cost += pricePerShare * shares;
		total_shares += shares;
	}

	public String toString(){
		return symbol + "\n" + "Number of shares: " + total_shares;
	}
	
}