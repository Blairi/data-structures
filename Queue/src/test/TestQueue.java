package test;

import queue.Queue;

public class TestQueue {
    public static void main(String[] args) {
        Queue queue = new Queue();
        
        queue.enqueueData("1");
        queue.enqueueData("2");
        queue.enqueueData("3");
        queue.enqueueData("4");
        queue.enqueueData("5");
        
        queue.showInfo();
        
        queue.enqueueData("6");
        queue.enqueueData("7");
        queue.enqueueData("8");
        queue.enqueueData("9");
        queue.enqueueData("10");
        queue.enqueueData("11");
        
        queue.showInfo();
        
        for (int i = 0; i < 3; i++) {
            System.out.println("Dequeuing " + queue.dequeue() + "...");
        }
        
        queue.showInfo();
    }
}
