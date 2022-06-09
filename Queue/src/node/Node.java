package node;

public final class Node {

    private Node next;
    private String data;
    
    public Node(){
        this.setNext(null);
        this.setData(null);
    }
    
    public Node(String data){
        this.setNext(null);
        this.setData(data);
    }
    
    public Node(String data, Node node){
        this.setNext(node);
        this.setData(data);
    }

    public Node getNext() {
        return this.next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public String getData() {
        return this.data;
    }

    public void setData(String data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return "Node{" + "data=" + data + '}';
    }
    
    
}
