public class Fib{
    public static void main(String args[]){
       //System.out.println("Hello!"); 
		int n=2;
		//long fib[]={0,1};
		long fib[];
		fib = new long[] {0,1};
		while (n<=100 || fib[n-1]<(Long.MAX_VALUE/2)){
			fib[n] = fib[n-1]+fib[n-2];
			n++;
		}
		System.out.println(n);
		
		//double result[n-1]={0,1};
		double result[];
		result = new double[] {0,1};
		for (int i=2;i<n-1;i++){
			double tmp = fib[i+1]/fib[i];
			result[i] = tmp;
		}
		
		for(double show:result){
			System.out.println(show);
			System.out.println('\n');
		}
    }
}



