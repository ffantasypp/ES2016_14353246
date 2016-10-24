import java.util.Calendar;
import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class ShowDate{
    public static void main(String args[]) throws Exception {
       //System.out.println("Hello!"); 
		Calendar cal = Calendar.getInstance();
		cal.setTime(new Date());
		System.out.println("现在的时间是：");
		String str1 = getCnDate(cal);
		
		System.out.println("2016-9-1 22:40:30经过135天4000秒后的时间：");
		DateFormat df = new SimpleDateFormat("yyyy-mm-dd HH:mm:ss");
		Date d = df.parse("20160901 224030");
		//System.out.println(d);
		Calendar c = Calendar.getInstance();
		c.setTime(d);
		c.add(c.DATE,135);
		c.add(c.SECOND,4000);
		String str2 = getCnDate(c);
		
    }

    static String getCnDate(Calendar cal){
		//cal = Calendar.getInstance();
		//cal.setTime(new Date());
		
		int year = cal.get(Calendar.YEAR);
		int month = cal.get(Calendar.MONTH)+1;
		int date = cal.get(Calendar.DATE);
		int hour = cal.get(Calendar.HOUR_OF_DAY);
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
			case 2:week = "星期一";break;
			case 3:week = "星期二";break;
			case 4:week = "星期三";break;
			case 5:week = "星期四";break;
			case 6:week = "星期五";break;
			case 7:week = "星期六";break;
			case 1:week = "星期日";break;
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
		
		return result;
    } 
}



