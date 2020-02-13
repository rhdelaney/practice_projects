/*public class FibonacciCalculator{
	public int calculateFibonacci(int num){
		if (num==0 || num==1){
			return num;
		}
		return calculateFibonacci((num)-1)+calculateFibonacci((num)-2);
	}
}*/

public class main {
	public static void main(String[] args) {
		FibonacciCalculator calculator = new FibonacciCalculator();
		int fib5 = calculator.calculateFibonacci(5);
		System.out.println("Fib(5) is " + fib5);
	}
}
