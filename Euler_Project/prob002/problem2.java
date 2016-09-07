public class problem2 {
	static final int MAX = 4000000;

	static int fib1 = 1;
	static int fib2 = 1;
	static int fib3 = fib2 + fib1;

	static void fib() {
		fib1 = fib3 + fib2;
		fib2 = fib1 + fib3;
		fib3 = fib2 + fib1;
	}

	public static void main(String[] args) {
		int sum = 0;

		while(fib3 <= MAX) {
			sum += fib3;
			fib();
		}
		System.out.println(sum);
	}
}
