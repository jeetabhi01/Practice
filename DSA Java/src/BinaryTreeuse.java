import java.util.Scanner;
public class BinaryTreeuse{

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
       BinaryTree<Integer> root =  Takeinput(s);
        Printtree(root);
        s.close();
        return;
    }
    
    public static BinaryTree<Integer> Takeinput(Scanner s){
        System.out.println("Enter the data in the node, enter '-1' to determine null node. ");
       
        int data = s.nextInt();
        if (data== -1)
        return null;
        BinaryTree<Integer> root = new BinaryTree<Integer>(data);
        root.left = Takeinput(s);
        root.right= Takeinput(s);

        return root;
    }
    public static void Printtree(BinaryTree<Integer> root){
        if(root == null)
        return;
        String tobeprinted = root.data + ": ";
        if(root.left!=null)
        tobeprinted +=  "L"+root.left.data + ", ";
        if(root.right!=null)
        tobeprinted+= + root.right.data;
        System.out.println(tobeprinted);
        Printtree(root.left);
        Printtree(root.right);

    }
}