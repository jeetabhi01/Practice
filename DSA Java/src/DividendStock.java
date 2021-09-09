public class DividendStock extends Stock{
    private double dividends;
    public DividendStock(String symbol){
        super(symbol);
        this.dividends = 0.0;
    }
    //records a dividend of the given amount per share
    public void payDividend(double amountPerShare){
        dividends += amountPerShare * getTotalShares();
    }
//Including the profits made from the dividends;
    public double getProfit(double currentPrice){
        return super.getProfit(currentPrice) + dividends;
    }
}