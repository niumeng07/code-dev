public class MyLinkedList {
    public Node head;

    class Node{
        private int val;
        private Node next;
        Node(int v,Node n){
            val = v;
            next = n;
        }
        Node(int v){
            val = v;
        }
        Node() {}
    }

    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = null;
    }
    public void ClearList() {
        head = null;
    }

    public void PrintList() {
        Node iter = head;
        while(iter != null) {
            System.out.print(iter.val + "\t");
            iter = iter.next;
        }
        System.out.println("");
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        Node iter = head;
        int i = 0;
        if(index < 0 || iter == null) return -1;
        while(true) {
            if(i < index && iter.next != null) {
                i++;
                iter = iter.next;
            }
            return iter.val;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        if(head == null) {
            head = new Node(val);
        } else {
            Node n = new Node(val);
            n.next = head;
            head = n;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        if(head == null) head = new Node(val);
        else {
            Node iter = head;
            while(iter.next != null) iter = iter.next;
            iter.next = new Node(val);
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        int i = 1;
        Node iter = head;
        if(index == 0) {
            this.addAtHead(val);
            return;
        }
        while(true) {
            if(i < index && iter.next !=null){
                i++;
                iter = iter.next;
            } else {
                if(iter == null) {
                    addAtTail(val);
                } else {
                    Node n = new Node(val, iter.next);
                    iter.next = n;
                    break;
                }
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if(head == null) return;
        if(index == 0) {
            head = head.next;
            return;
        }

        Node iter = head;
        int i = 0;
        while (true) {
            if(i+1 == index) {
                if(iter.next.next!=null)
                    iter.next = iter.next.next;
                else
                    iter.next = null;
                return;
            } else {
                i++;
                if(iter.next!=null) iter = iter.next;
                else return;
            }
        }
    }

    public static void main(String[] args) {
        MyLinkedList l = new MyLinkedList();
        l.addAtHead(1);
        l.deleteAtIndex(0);
        l.PrintList();
    }
}
