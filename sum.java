public class sum{
	final int LEVEL_NUM = 100;

	public void text() {
		int sum = 0;
		for(int i=0;i<LEVEL_NUM;i++){
			sum = sum + i + 1;
		}
		System.out.println(sum);
	}
}