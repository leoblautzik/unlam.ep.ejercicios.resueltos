
// //factorial(n)=1*2*3*4*......*n
// 		1 si x=0
// fact(n)=
// 		n*fact(n-1)

public class Factorial{

	private long[] fact;

	public Factorial(){
		this.fact = new long[35];
		this.fact[0]=1;
		for(int i=1; i<fact.length;i++)
			fact[i]=i*fact[i-1];
	}

	public static long factorial(int n){
		if(n==0)return 1;
		return n*factorial(n-1);

	}

	public long factorialDinamico(int n){
		return this.fact[n];
	}


	public static void main(String[] args) {
		Factorial f =new Factorial();
		 

		System.out.println(factorial(20));
		System.out.println(f.factorialDinamico(20));
	}
}


v={0,1,2,3,4,5,6,7,8,9} 
cual es el primero que falta?