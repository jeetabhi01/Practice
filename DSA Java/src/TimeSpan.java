public class TimeSpan {
    private int hrs, mins;

    public TimeSpan(){
        this.hrs = 0;
        this.mins = 0;
    }

    public TimeSpan(int hrs, int mins){
        this.hrs = 0;
        this.mins = 0;
        add(hrs,mins);
    }

    public void add(int hrs , int mins){
        if(hrs < 0 || mins < 0){
            throw new IllegalArgumentException();
        }
        this.mins += mins;
        this.hrs  += hrs + mins / 60;
        this.mins %= 60;
    }

    public String toString(){
        return (""+ hrs + "hr " + mins );
    }
}
