import java.util.*; 
import java.text.*; 

public class ShowDate{
    public static void main(String args[]) throws Exception {
       //System.out.println("Hello!"); 
    }

    static String getCnDate(Calendar cal){
		cal = Calendar.getInstance();
		cal.setTime(new Date());
		
		int year = cal.get(Calendar.YEAR);
		int month = cal.get(Calendar.MONTH);
		int date = cal.get(Calendar.DATE);
		int hour = cal.get(Calendar.HOUR);
		int minute = cal.get(Calendar.MINUTE);
		int second = cal.get(Calendar.SECOND);
		
		String time="";
		if(hour<12){
			time = "���� ";
		}
		else{
			time = "���� ";
		}
		
		String week="";
		int day = cal.get(Calendar.DAY_OF_WEEK);
		switch (day)
		{
			case 1:week = "����һ";
			case 2:week = "���ڶ�";
			case 3:week = "������";
			case 4:week = "������";
			case 5:week = "������";
			case 6:week = "������";
			case 7:week = "������";
		}
		
		String result = "";
		//result = new String [8];
		result += year+"��";
		result += month+"��";
		result += date+"��";
		result += hour+"ʱ";
		result += minute+"��";
		result += second+"��";
		result += " "+time;
		result += " "+week;
		System.out.println(result);
		
		//System.out.println(year+"��"+month+"��"+date+"��"+hour+"ʱ"+minute+"��"+second+"�� "+time+week);
		return result;
    } 
}



