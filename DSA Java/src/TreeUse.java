// import jdk.nashorn.api.tree.Tree;
import java.util.Scanner;

public class TreeUse {
    

   
    public static void main(String[] args){
       Scanner s = new Scanner(System.in);
       TreeNode<Integer> root = TreeNodeTakeinput(s);
       Printtree(root);
        System.out.println("The execution is complete \n");
    }
    // static TreeNode<Integer> takeinput(){
 
  public static TreeNode<Integer> TreeNodeTakeinput(Scanner s){
      int n ;
      System.out.println("Enter the data ");
      n = s.nextInt();
      TreeNode<Integer> root = new TreeNode<Integer>(n);
      int numchild;
      System.out.println("Enter the number of children of " + n);
      numchild = s.nextInt();
      for(int i = 0 ; i < numchild; i++){
        TreeNode<Integer> child = TreeNodeTakeinput(s);
        root.children.add(child);
      }
    return root;

  }   

  public static void  Printtree(TreeNode<Integer> root){
      String s = root.data + ": ";
        for(int i = 0 ; i < root.children.size(); i++){
            s += root.children.get(i).data + ", ";
            
  }
   System.out.println(s);
   for(int i = 0 ; i < root.children.size(); i++){
        Printtree(root.children.get(i));
   }
}
}