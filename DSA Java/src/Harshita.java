import java.util.*;


public class Harshita {
    public static void main(String[] args){
        Scanner console = new Scanner(System.in);
        int T = 1;
        T = console.nextInt();
         console.nextLine();
            for(int i = 1 ; i <= T ; i++){
            String s = console.nextLine();
            for(int j = s.length()-1 ; j >= 0 ; j--){
                System.out.print(s.charAt(j));
            }
        System.out.println();
        }
        console.close();
   }
}