import java.util.Scanner;

public class Test{

	public static int getLastIndex(int [] arr, int key){
		int index = -1;
		for(int i = 0 ; i < arr.length; i++){
			if(key == arr[i]){
				index = i;
			}
		}
		return index;
	}

	public static void main(String[] args){
		Scanner console = new Scanner(System.in);

		System.out.println("Enter the number of elements: ");
		int n = console.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter the elements in the array");
		for(int i =0 ; i < arr.length; i++)
		{
			arr[i] = console.nextInt();
		}

		System.out.println(getLastIndex(arr, 14));

		console.close();
	}	
}
