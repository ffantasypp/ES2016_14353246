class A{
	synchronized void methodA(B b){
		b.last();
	}
	synchronized void last(){
		system.out.println("inside A.last()");
	}
}

class B{
	synchronized void methodB(A a){
		a.last();
	}
	synchronized void last(){
		system.out.println("inside B.last()");
	}
}

class Deadlock implements Runnable{
	A a = new A();
	B b = new B();
	
	Deadlock(){
		Thread t = new Thread(this);
		int count = 20000;
		
		t.start();
		while(count-->0)
			a.methodA(b);
	}
	
	public void run(){
		b.methodB(a);
	}
	public static void main(String.args[]){
		new Deadlock();
	}
}

#!/bin/bash
for ((c=1;c<=100;c++))
	do
		echo "$c times"
		java Deadlock
	done
	
