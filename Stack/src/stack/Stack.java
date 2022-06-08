package stack;

import node.Node;

public class Stack {
    
    private Node top;
    private Node bottom;
    private int len;
    
    private static final int MAX = 10;
    
    public Stack(){
        this.setTop( null );
        this.setBottom( null );
        this.len = 0;
    }
    
    public boolean empty(){
        return len < 1;
    }
    
    public String pop(){
        
        if( this.empty() ){
            return "stack empty";
        }
        
        Node deletedNode = this.getTop();
        String data = deletedNode.getData(); // Save the data to return it
        
        if( deletedNode.getNext() != null ){ // If there a next node
            this.setTop( deletedNode.getNext() );
        }
        
        else{ // If there only one element
            this.setTop( null );
            this.setBottom( null );
        }
        
        this.len--;
        
        return data;
        
    }
    
    public void pushData( String data ){
        
        if( this.len + 1 > Stack.MAX ){
            System.out.println("Stack is full");
            return;
        }
        
        Node newNode = new Node(data); // Create a new node with data
        
        if( this.empty() ){ // If stack is empty, set the top and bottom references to new node
            this.setBottom( newNode );
            this.setTop( newNode );
        }
        
        else { // If stack is not empty
            newNode.setNext( this.getTop() ); // the reference (next) of the new node will be the top of stack
            this.setTop( newNode ); // the top reference of stack will be the new node
        }
        
        this.len++;
    }

    public void show(){
        if( !this.empty() ){
            Node actual = this.getTop();
            while ( actual != null ) {
                System.out.println( actual.getData() );
                actual = actual.getNext();
            }
        }
    }
    
    public void showInfo(){
        System.out.println("\n-- Stack --");
        System.out.println("Length: " + this.getLen());
        System.out.println("Top: " + this.top.getData());
        System.out.println("Bottom: " + this.bottom.getData() + "\n");
        if( !this.empty() ){
            Node actual = this.getTop();
            while ( actual != null ) {
                System.out.println( actual.getData() );
                actual = actual.getNext();
            }
        }
        System.out.println("---------------------\n");
    }

    public Node getTop() {
        return this.top;
    }

    public Node getBottom() {
        return this.bottom;
    }

    public int getLen() {
        return this.len;
    }

    private void setTop(Node top) {
        this.top = top;
    }

    private void setBottom(Node bottom) {
        this.bottom = bottom;
    }
    
}
