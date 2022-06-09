package queue;

import node.Node;

public class Queue {
    private Node head;
    private Node tail;
    private int len;
    private static final int MAX = 10;
    
    public Queue(){
        this.len = 0;
        this.setHead( null );
        this.setTail( null );
    }
    
    public boolean isEmpty(){
        return this.len < 1;
    }
    
    public boolean isFull(){
        return this.getLen() + 1 > Queue.MAX;
    }
    
    public void enqueueData( String data ){
        
        if ( this.isFull() ){
            System.out.println("Can't enqueue " + data + ", the queue is full.");
            return;
        }
        
        Node node = new Node( data );
        
        if( this.isEmpty() ){
            this.setHead( node );
            this.setTail( node );
        }
        else{
            this.tail.setNext( node );
            this.setTail( node );
        }
        
        this.len++;
    }
    
    public String dequeue(){
        
        if ( this.isEmpty() ){
            System.out.println("Queue empty");
            return null;
        }
        
        Node deletedNode = this.getHead();
        String data = deletedNode.getData(); // Save the data to return it
        
        this.len--;
        
        if( deletedNode.getNext() != null ){
            this.setHead( deletedNode.getNext() );
        }
        else{ // If there an one element
            this.setHead(null);
            this.setTail(null);
            this.len = 0;
        }
        
        return data;
        
    }
    
    public void showInfo(){
        
        if ( this.isEmpty() ) return;
        
        System.out.println("-- Queue --");
        System.out.println( "Head: " + this.getHead().getData() );
        System.out.println( "Tail: " + this.getTail().getData() );
        System.out.println( "Length: " + this.getLen() );
        System.out.print("[ ");
        
        Node actual = this.getHead();
        while( actual != null ){
            System.out.printf( actual.getData() + " " );
            actual = actual.getNext();
        }
        System.out.println("]\n");
        
    }
    
    public void show(){
        Node actual = this.getHead();
        while( actual != null ){
            System.out.printf( actual.getData() + " " );
            actual = actual.getNext();
        }
        System.out.println("]\n");
    }

    public Node getHead() {
        return this.head;
    }

    private void setHead(Node head) {
        this.head = head;
    }

    public Node getTail() {
        return this.tail;
    }

    private void setTail(Node tail) {
        this.tail = tail;
    }

    public int getLen() {
        return len;
    }
    
}
