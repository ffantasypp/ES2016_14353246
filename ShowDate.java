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
			time = "上午 ";
		}
		else{
			time = "下午 ";
		}
		
		String week="";
		int day = cal.get(Calendar.DAY_OF_WEEK);
		switch (day)
		{
			case 1:week = "星期一";
			case 2:week = "星期二";
			case 3:week = "星期三";
			case 4:week = "星期四";
			case 5:week = "星期五";
			case 6:week = "星期六";
			case 7:week = "星期日";
		}
		
		String result = "";
		//result = new String [8];
		result += year+"年";
		result += month+"月";
		result += date+"日";
		result += hour+"时";
		result += minute+"分";
		result += second+"秒";
		result += " "+time;
		result += " "+week;
		System.out.println(result);
		
		//System.out.println(year+"年"+month+"月"+date+"日"+hour+"时"+minute+"分"+second+"秒 "+time+week);
		return result;
    } 
}



