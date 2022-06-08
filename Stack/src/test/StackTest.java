package test;

import stack.Stack;

public class StackTest {
    public static void main(String[] args) {
        
        Stack sandwich = new Stack();
        
        String ingredients[] = { "Bread", "Mayo", "Deli meat", "Lettuce", "Mayo", "Bread" };
        for( String ingredient : ingredients ){
            sandwich.pushData( ingredient );
        }
        
        sandwich.showInfo();
        
        for ( int i = 0; i < 2; i++ ) {
            System.out.println("Removing " + sandwich.pop() + "...");
        }
        
        sandwich.showInfo();
        
        // the method pushData do not insert "Cheese" because the stack is full
        String extras[] = { "Tomatoe", "Mustard", "Egg salad", "Hummus", "Mayo", "Bread", "Cheese" };
        for ( String extra : extras ) {
            sandwich.pushData( extra );
        }
        
        sandwich.showInfo();
    }
    
}
