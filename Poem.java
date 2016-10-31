import java.util.Arrays;

public class Poem{
    public static void main(String args[]) throws Exception {
        String ci="蝶恋花欧阳修庭院深深深几许杨柳堆烟帘幕无重数玉勒雕鞍游冶处楼高不见章台路雨横风狂三月暮门掩黄昏无计留春住泪眼问花花不语乱红飞过秋千去";
        String ends= "花；修；几许；烟；数；处；路；暮；黄昏；住；语；去";
        String punc[]={"", "", "，", "，", "。", "，","。","，","，","。","，","。"};       
  
		String[] end = ends.split("；");
		/*
		int i=0;
		for (i=0;i<e.length;i++){
			System.out.println(e[i]);
		}
		*/
		String ArrayList = "";
		int e = 0;
		int begin = 0;
		for (int j=0;j<ci.length();j++){
			int check = 0;
			check = ci.indexOf(end[e]);
			if (check == 1){
				ArrayList += ci.substring(begin,j-begin+1);
				ArrayList += punc[e];
				e++;
				begin = j+1;
			}
		}
		System.out.println(ArrayList);
    }

}



