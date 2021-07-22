import java.util.HashMap;
import java.util.ArrayList;
public class Graph {
    public class Vertex{
        public HashMap<String,Integer> ngbrs = new HashMap<> ();
    }
    private HashMap<String,Vertex> vertices = new HashMap<>();
    public void addVertex(String vtx, int cost){
        Vertex v = new Vertex();
        v.ngbrs.put(vtx,cost);
    }
    public int getSize(){
        return vertices.size();
    }

    public void addEdge(String v1, String v2,int cost){
        Vertex vtx1 = vertices.get(v1);
        Vertex vtx2 = vertices.get(v2);
        if(vtx1==null || vtx2 == null || vtx1.ngbrs.containsKey(v2)){
            return;
        }
        
        vtx1.ngbrs.put(v2,cost);
        vtx2.ngbrs.put(v1,cost);
    }

    public ArrayList<String> getKeySet(){
        ArrayList<String> keys = new ArrayList <String> (vertices.keySet());
        return keys;
    }


    
}
