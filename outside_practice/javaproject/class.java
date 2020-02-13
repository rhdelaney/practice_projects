package model;

public FibonacciCalculator{
	public int calculateFibonacci(int num){
		if (num==0 || num==1){
			return num;
		}
		return calculateFibonacci((num)-1)+calculateFibonacci((num)-2);
	}
}