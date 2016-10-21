int create_student_table();//
int create_sc_table();//
int create_course_table();//
int insert_rows_into_student_table();//
int insert_rows_into_sc_table();//
int insert_rows_into_course_table();//
int current_of_delete_for_student();//
int current_of_delete_for_course();//
int current_of_delete_for_sc();//
int using_cursor_to_total_s_sc();//
int using_cursor_to_total_c_sc();//
int current_of_update_for_student();//
int current_of_update_for_course();//
int current_of_update_for_sc();//
int using_cursor_to_list_s_sc_c();//
int using_cursor_to_list_table_names();//
int using_cursor_to_list_course();//
int using_cursor_to_list_sc();//
int using_cursor_to_list_student();//
int check_username_password();
void pause();

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mysql.h"
MYSQL mysql;
MYSQL_RES *result;
MYSQL_ROW row;
int num_fields;
int main(int argc, char** argv)
{
	int num = 0;
	char fu[2];
	mysql_init(&mysql);
	if (mysql_real_connect(&mysql, "localhost", "root", "root", "testdb", 3306, 0, 0))
	{
		if (check_username_password() == 0)
		{
			for (;;){
				printf("Sample Embedded SQL for C application\n");
				printf("Please select one function to execute:\n\n");
				printf("  0--exit.\n");
				printf("  1--创建学生表     6--添加成绩记录   b--删除课程记录     h--学生课程成绩表 \n");
				printf("  2--创建课程表     7--修改学生记录   c--删除成绩记录     j--学生成绩统计表  \n");
				printf("  3--创建成绩表     8--修改课程记录   e--显示学生记录     k--课程成绩统计表   \n");
				printf("  4--添加学生记录   9--修改成绩记录   f--显示课程记录     m--数据库表名 \n");
				printf("  5--添加课程记录   a--删除学生记录   g--显示成绩记录      \n");
				printf("\n");
				fu[0] = '0';
				scanf("%s", &fu);
				if (fu[0] == '0') exit(0);
				if (fu[0] == '1') create_student_table();
				if (fu[0] == '2') create_course_table();
				if (fu[0] == '3') create_sc_table();
				if (fu[0] == '4') insert_rows_into_student_table();
				if (fu[0] == '5') insert_rows_into_course_table();
				if (fu[0] == '6') insert_rows_into_sc_table();
				if (fu[0] == '7') current_of_update_for_student();
				if (fu[0] == '8') current_of_update_for_course();
				if (fu[0] == '9') current_of_update_for_sc();
				if (fu[0] == 'a') current_of_delete_for_student();
				if (fu[0] == 'b') current_of_delete_for_course();
				if (fu[0] == 'c') current_of_delete_for_sc();
				if (fu[0] == 'e') using_cursor_to_list_student();
				if (fu[0] == 'f') using_cursor_to_list_course();
				if (fu[0] == 'g') using_cursor_to_list_sc();
				if (fu[0] == 'h') using_cursor_to_list_s_sc_c();
				if (fu[0] == 'j') using_cursor_to_total_s_sc();
				if (fu[0] == 'k') using_cursor_to_total_c_sc();
				if (fu[0] == 'm') using_cursor_to_list_table_names();
				pause();
			}
		}
		else
		{
			printf("Your name or password is error,you can not be logined in the system!");
		}

	}
	else
	{
		printf("数据库不存在！");
	}
	mysql_close(&mysql);
	return 0;
}
int insert_rows_into_student_table()
{
	char csage[] = "18";
	char issex[] = "男";
	char isno[] = "95002";
	char isname[] = "xxxxxx";
	char isdept[] = "CS";
	char strquery[100] = "insert into student(sno,sname,sage,ssex,sdept) values('";
	char yn[2];
	while (1){
		printf("Please input sno(eg:95001):");
		scanf("%s", isno);
		strcat(strquery, isno);
		strcat(strquery, "','");
		printf("Please input name(eg:XXXX):");
		scanf("%s", isname);
		strcat(strquery, isname);
		strcat(strquery, "','");
		printf("Please input age(eg:18):");
		scanf("%s", csage);
		strcat(strquery, csage);
		strcat(strquery, "','");
		printf("Please input sex(eg:男):");
		scanf("%s", issex);
		strcat(strquery, issex);
		strcat(strquery, "','");
		printf("Please input dept(eg:CS、IS、MA...):");
		scanf("%s", isdept);
		strcat(strquery, isdept);
		strcat(strquery, "');");

		if (mysql_query(&mysql, strquery) == 0)
		{
			printf("execute successfully!\n\n");
		}
		else
		{
			printf("ERROR: execute \n");
		}
		printf("Insert again?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			continue;
		}
		else break;
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}

	return (0);
}

int insert_rows_into_course_table()
{
	char icno[2];
	char icname[20];
	char icpno[2];
	char iccredit[2];
	char strquery[100] = "insert into course(cno,cname,cpno,ccredit) values('";
	char yn[2];
	while (1){
		printf("Please input cno(eg:1):");
		scanf("%s", icno);
		strcat(strquery, icno);
		strcat(strquery, "','");
		printf("Please input cname(eg:XXXX):");
		scanf("%s", icname);
		strcat(strquery, icname);
		strcat(strquery, "','");
		printf("Please input cpno(eg:1):");
		scanf("%s", icpno);
		strcat(strquery, icpno);
		strcat(strquery, "','");
		printf("Please input iccredit(eg:2):");
		scanf("%s", iccredit);
		strcat(strquery, iccredit);
		strcat(strquery, "');");

		if (mysql_query(&mysql, strquery) == 0)
		{
			printf("execute successfully!\n\n");
		}
		else
		{
			printf("ERROR: execute \n");
		}
		printf("Insert again?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			continue;
		}
		else break;
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}

	return (0);
}

int insert_rows_into_sc_table()
{
	char igrade[] = "80";
	char icno[] = "1 ";
	char isno[] = "95001";
	char strquery[100] = "insert into sc(sno,cno,grade) values('";
	char yn[2];
	while (1){
		printf("Please input sno(eg:95001,...):");
		scanf("%s", isno);
		strcat(strquery, isno);
		strcat(strquery, "','");
		printf("Please input cno(eg:1,2,3,...):");
		scanf("%s", icno);
		strcat(strquery, icno);
		strcat(strquery, "','");
		printf("Please input grade(eg:60):");
		scanf("%s", &igrade);
		strcat(strquery, igrade);
		strcat(strquery, "');");

		if (mysql_query(&mysql, strquery) == 0)
		{
			printf("execute successfully!%d\n\n");
		}
		else
		{
			printf("ERROR: execute %d\n");
		}
		printf("Insert again?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			continue;
		}
		else break;
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}

	return (0);
}


int current_of_update_for_student()
{
	char yn[2];
	char deptname[3];
	char hsno[6];
	char hsname[7];
	char hssex[6];
	char hsdept[3];
	char hsage[3];
	int i;
	char  isage[3] = "38";
	char  issex[6] = "男";
	char  isname[7] = "xxxxxx";
	char  isdept[3] = "CS";
	char strquery[100] = "select sno,sname,ssex,sage,sdept from student";

	printf("Please input deptname to be updated(CS、IS、MA...,**--All):\n");
	scanf("%s", deptname);
	if (strcmp(deptname, "*") != 0 || strcmp(deptname, "**") != 0)
	{
		strcat(strquery, " where sdept like '");
		strcat(strquery, deptname);
		strcat(strquery, "%'");
	}
	mysql_query(&mysql, strquery);

	result = mysql_store_result(&mysql);

	printf("%s\n", "sno  sname  ssex  sage  sdept");

	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(hsno, row[i]); break; }
			case 1:{strcpy(hsname, row[i]); break; }
			case 2:{strcpy(hssex, row[i]); break; }
			case 3:{strcpy(hsage, row[i]); break; }
			case 4:{strcpy(hsdept, row[i]); break; }
			}
		}
		printf("%s", hsno);
		printf(" %s", hsname);
		printf("  %s", hssex);
		printf("   %s", hsage);
		printf("  %s\n", hsdept);
		printf("UPDATE ?(y/n/0,y--yes,n--no,0--exit)");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			char strupdate[100] = "update student set sname='";
			printf("Please input new name(eg:XXXX):");
			scanf("%s", isname);
			strcat(strupdate, isname);
			strcat(strupdate, "',sage='");
			printf("Please input age(eg:18):");
			scanf("%s", isage);
			strcat(strupdate, isage);
			strcat(strupdate, "',ssex='");
			printf("Please input sex(eg:男):");
			scanf("%s", issex);
			strcat(strupdate, issex);
			strcat(strupdate, "',sdept='");
			printf("Please input dept(eg:CS、IS、MA...):");
			scanf("%s", isdept);
			strcat(strupdate, isdept);
			strcat(strupdate, "' where sno='");
			strcat(strupdate, hsno);

			strcat(strupdate, "'");
			if (mysql_query(&mysql, strupdate) == 0)
			{
				printf("update table student successfully!\n\n");
			}
			else
			{
				printf("ERROR: update table student \n\n");
			}
			printf("%s\n",strupdate);
		}
		if (yn[0] == '0') break;
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}

int current_of_update_for_sc()
{
	char yn[2];
	char  ssno[6];
	char  hsno[6];
	char  hcno[2];
	char  hgrade[3];
	char  igrade[3] = "88";
	char strquery[100] = "select sno,cno,grade from sc";
	int i;

	printf("Please input sno to be updated(95001...,*****--All):\n");
	scanf("%s", ssno);
	if (strcmp(ssno, "*****") != 0)
	{
		strcat(strquery, " where ssno like '");
		strcat(strquery, ssno);
		strcat(strquery, "%'");
	}
	mysql_query(&mysql, strquery);

	result = mysql_store_result(&mysql);

	printf("%s\n", "sno  cno   grade");

	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(hsno, row[i]); break; }
			case 1:{strcpy(hcno, row[i]); break; }
			case 2:{strcpy(hgrade, row[i]); break; }
			}
		}
		printf("%s", hsno);
		printf(" %s", hcno);
		printf("  %s\n", hgrade);

		printf("UPDATE ?(y/n/0,y--yes,n--no,0--exit)");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			char strupdate[100] = "update sc set grade='";
			printf("Please input new grade(eg:88):");
			scanf("%s", igrade);
			strcat(strupdate, igrade);
			strcat(strupdate, "' where sno='");
			strcat(strupdate, hsno);

			strcat(strupdate, "' and cno='");
			strcat(strupdate, hcno);

			strcat(strupdate, "'");
			if (mysql_query(&mysql, strupdate))
			{
				printf("update table sc successfully!\n\n");
			}
			else
			{
				printf("ERROR: update table sc \n\n");
			}
		}
		if (yn[0] == '0') break;
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}
int current_of_delete_for_sc()
{
	char yn[2];
	char  ssno[6];
	char  hsno[6];
	char  hcno[2];
	char  hgrade[3];
	char strquery[100] = "select sno,cno,grade from sc";
	int i;

	printf("Please input sno to be deleted(95001...,*****--All):\n");
	scanf("%s", ssno);
	if (strcmp(ssno, "*****") != 0)
	{
		strcat(strquery, " where ssno like '");
		strcat(strquery, ssno);
		strcat(strquery, "%'");
	}
	mysql_query(&mysql, strquery);

	result = mysql_store_result(&mysql);

	printf("%s\n", "sno  cno   grade");

	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(hsno, row[i]); break; }
			case 1:{strcpy(hcno, row[i]); break; }
			case 2:{strcpy(hgrade, row[i]); break; }
			}
		}
		printf("%s", hsno);
		printf(" %s", hcno);
		printf("  %s\n", hgrade);

		printf("DELETE ?(y/n/0,y--yes,n--no,0--exit)");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			char strdelete[100] = "delete from sc where sno='";
			strcat(strdelete, hsno);
			strcat(strdelete, "' and cno='");
			strcat(strdelete, hcno);

			strcat(strdelete, "'");
			if (mysql_query(&mysql, strdelete))
			{
				printf("delete table sc successfully!\n\n");
			}
			else
			{
				printf("ERROR: delete table sc \n\n");
			}

		}
		if (yn[0] == '0') break;
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}

int current_of_update_for_course()
{
	char yn[2];
	char ccno[3];
	char hcno[3];
	char hcname[11];
	char hcpno[3];
	char hccredit[3];

	char icname[11];
	char icpno[3];
	char iccredit[3];
	int i;

	char strquery[100] = "select cno,cname,cpno,ccredit from course ";

	printf("Please input cno to be updated(1、2...,**--All):\n");
	scanf("%s", ccno);
	if (strcmp(ccno, "**") != 0)
	{
		strcat(strquery, " where cno like '");
		strcat(strquery, ccno);
		strcat(strquery, "%'");
	}

	mysql_query(&mysql, strquery);

	result = mysql_store_result(&mysql);

	printf("%s\n", "cno  cname       cpno  ccredit");

	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(hcno, row[i]); break; }
			case 1:{strcpy(hcname, row[i]); break; }
			case 2:{strcpy(hcpno, row[i]); break; }
			case 3:{strcpy(hccredit, row[i]); break; }
			}
		}
		printf("%s", hcno);
		printf(" %s", hcname);
		printf("  %s", hcpno);
		printf("   %s\n", hccredit);

		printf("UPDATE ?(y/n/0,y--yes,n--no,0--exit)");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			char strupdate[100] = "update course set cname='";
			printf("Please input new name(eg:XXXX):");
			scanf("%s", icname);
			strcat(strupdate, icname);
			strcat(strupdate, "',cpno='");
			printf("Please input cpno(eg:2):");
			scanf("%s", icpno);
			strcat(strupdate, icpno);
			strcat(strupdate, "',ccredit='");
			printf("Please input ccredit(eg:3):");
			scanf("%s", iccredit);
			strcat(strupdate, iccredit);

			strcat(strupdate, "' where cno='");
			strcat(strupdate, hcno);

			strcat(strupdate, "'");
			if (mysql_query(&mysql, strupdate))
			{
				printf("update table course successfully!\n\n");
			}
			else
			{
				printf("ERROR: update table course \n\n");
			}
		}
		if (yn[0] == '0') break;
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}

int current_of_delete_for_course()
{
	char yn[2];
	char ccno[3];
	char hcno[3];
	char hcname[11];
	char hcpno[3];
	char hccredit[3];
	int i;

	char strquery[100] = "select cno,cname,cpno,ccredit from course ";

	printf("Please input cno to be deleted(1、2...,**--All):\n");
	scanf("%s", ccno);
	if (strcmp(ccno, "**") != 0)
	{
		strcat(strquery, " where cno like '");
		strcat(strquery, ccno);
		strcat(strquery, "%'");
	}

	mysql_query(&mysql, strquery);

	result = mysql_store_result(&mysql);

	printf("%s\n", "cno  cname      cpno  ccredit");

	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(hcno, row[i]); break; }
			case 1:{strcpy(hcname, row[i]); break; }
			case 2:{strcpy(hcpno, row[i]); break; }
			case 3:{strcpy(hccredit, row[i]); break; }
			}
		}
		printf("%s", hcno);
		printf(" %s", hcname);
		printf("  %s", hcpno);
		printf("   %s\n", hccredit);

		printf("DELETE ?(y/n/0,y--yes,n--no,0--exit)");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			char strdelete[100] = "delete from course where cno='";
			strcat(strdelete, hcno);
			strcat(strdelete, "'");
			if (mysql_query(&mysql, strdelete))
			{
				printf("delete table course successfully!\n\n");
			}
			else
			{
				printf("ERROR: delete table course \n\n");
			}
			printf(strdelete);

		}
		if (yn[0] == '0') break;
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}

int current_of_delete_for_student()
{
	char yn[2];
	char deptname[3];
	char hsno[6];
	char hsname[7];
	char hssex[3];
	char hsage[3];
	char hsdept[3];

	int i;
	char strquery[100] = "select sno,sname,ssex,sage,sdept from student";

	printf("Please input deptname(CS、IS、MA...,**--All):\n");
	scanf("%s", deptname);
	if (strcmp(deptname, "*") != 0 || strcmp(deptname, "**") != 0)
	{
		strcat(strquery, " where sdept like '");
		strcat(strquery, deptname);
		strcat(strquery, "%'");
	}

	mysql_query(&mysql, strquery);

	result = mysql_store_result(&mysql);

	printf("%s\n", "sno  sname  ssex  sage  sdept");

	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(hsno, row[i]); break; }
			case 1:{strcpy(hsname, row[i]); break; }
			case 2:{strcpy(hssex, row[i]); break; }
			case 3:{strcpy(hsage, row[i]); break; }
			case 4:{strcpy(hsdept, row[i]); break; }
			}
		}
		printf("%s", hsno);
		printf(" %s", hsname);
		printf("  %s", hssex);
		printf("   %s", hsage);
		printf("  %s\n", hsdept);
		printf("DELETE ?(y/n/0,y--yes,n--no,0--exit)");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			char strdelete[100] = "delete from student where sno ='";
			strcat(strdelete, hsno);
			strcat(strdelete, "'");
			if (mysql_query(&mysql, strdelete))
			{
				printf("delete table student successfully!\n\n");
			}
			else
			{
				printf("ERROR: delete table student \n\n");
			}
		}
		if (yn[0] == '0') break;
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}
int using_cursor_to_list_student()
{
	char isage[3];
	char issex[3];
	char isno[6];
	char isname[7];
	char isdept[3];
	int i;
	char strquery[100] = "select sno,sname,ssex,sage,sdept from student ";
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	printf("%s\n", "sno  sname  ssex  sage  sdept");
	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(isno, row[i]); break; }
			case 1:{strcpy(isname, row[i]); break; }
			case 2:{strcpy(issex, row[i]); break; }
			case 3:{strcpy(isage, row[i]); break; }
			case 4:{strcpy(isdept, row[i]); break; }
			}
		}
		printf("%s", isno);
		printf(" %s", isname);
		printf("  %s", issex);
		printf("   %s", isage);
		printf("  %s\n", isdept);
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}

int using_cursor_to_list_course()
{
	char hcno[3];
	char hcname[11];
	char hcpno[3];
	char hccredit[3];
	int i;
	char strquery[100] = "select cno,cname,cpno,ccredit from course ";
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	printf("%s\n", "cno  cname      cpno  ccredit");
	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(hcno, row[i]); break; }
			case 1:{strcpy(hcname, row[i]); break; }
			case 2:{strcpy(hcpno, row[i]); break; }
			case 3:{strcpy(hccredit, row[i]); break; }
			}
		}
		printf("%s", hcno);
		printf(" %s", hcname);
		printf("  %s", hcpno);
		printf("   %s\n", hccredit);
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}
int using_cursor_to_list_sc()
{
	char hcno[3];
	char hsno[6];
	char hgrade[3];
	int i;
	char strquery[100] = "select sno,cno,grade from sc ";
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	printf("%s\n", "sno  cno   grade");
	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(hsno, row[i]); break; }
			case 1:{strcpy(hcno, row[i]); break; }
			case 2:{strcpy(hgrade, row[i]); break; }
			}
		}
		printf("%s", hsno);
		printf(" %s", hcno);
		printf("  %s\n", hgrade);
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}

int using_cursor_to_list_s_sc_c()
{
	char hsno[6];
	char hsname[7];
	char hssex[3];
	char hsage[3];
	char hsdept[3];
	char hcno[3];
	char hcname[11];
	char hcpno[3];
	char hccredit[3];
	char hgrade[3];
	int i;
	char strquery[150] = "select student.sno,sname,ssex,sage,sdept,course.cno,cname,cpno,ccredit,grade from student,sc,course where student.sno=sc.sno and sc.cno=course.cno ";

	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	printf("%s\n", "sno  sname     ssex  sage  sdept     cno  cname      cpno  ccredit  grade");
	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(hsno, row[i]); break; }
			case 1:{strcpy(hsname, row[i]); break; }
			case 2:{strcpy(hssex, row[i]); break; }
			case 3:{strcpy(hsage, row[i]); break; }
			case 4:{strcpy(hsdept, row[i]); break; }
			case 5:{strcpy(hcno, row[i]); break; }
			case 6:{strcpy(hcname, row[i]); break; }
			case 7:{strcpy(hcpno, row[i]); break; }
			case 8:{strcpy(hccredit, row[i]); break; }
			case 9:{strcpy(hgrade, row[i]); break; }
			}
		}
		printf("%s", hsno);
		printf(" %s", hsname);
		printf(" %s", hssex);
		printf(" %s", hsage);
		printf(" %s", hsdept);
		printf(" %s", hcno);
		printf(" %s", hcname);
		printf(" %s", hcpno);
		printf(" %s", hccredit);
		printf(" %s\n", hgrade);
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}

int using_cursor_to_total_s_sc()
{
	double isum = 18;
	int icnt = 18;
	double iavg = 18;
	double imin = 18;
	double imax = 18;
	char isno[] = "95001";
	char isname[] = "xxxxxx";
	int i;
	char strquery[200] = "select student.sno,sname,count(grade),sum(grade),avg(grade),MIN(grade),MAX(grade) from student,sc where student.sno=sc.sno group by student.sno,sname";
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	printf("sno  sname  count sum  avg  min  max \n");
	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(isno, row[i]); break; }
			case 1:{strcpy(isname, row[i]); break; }
			case 2:{icnt = atoi(row[i]); break; }
			case 3:{isum = atof(row[i]); break; }
			case 4:{iavg = atof(row[i]); break; }
			case 5:{imin = atof(row[i]); break; }
			case 6:{imax = atof(row[i]); break; }
			}
		}
		printf("%s", isno);
		printf(" %s", isname);
		printf("  %d", icnt);
		printf("  %3.0f", isum);
		printf("  %3.0f", iavg);
		printf("  %3.0f", imin);
		printf("  %3.0f\n", imax);
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}
int using_cursor_to_total_c_sc()
{
	double isum = 18;
	int icnt = 18;
	double iavg = 18;
	double imin = 18;
	double imax = 18;
	char icno[] = "1";
	char icname[] = "xxxxxxxxxx";
	int i;
	char strquery[200] = "select course.cno,cname,count(grade),sum(grade),avg(grade) aa3,MIN(grade),MAX(grade) from course,sc where course.cno=sc.cno group by course.cno,cname";
	mysql_query(&mysql, strquery);
	result = mysql_store_result(&mysql);
	printf("cno  cname  count sum  avg  min  max \n");
	num_fields = mysql_field_count(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		for (i = 0; i<num_fields; i++)
		{
			switch (i)
			{
			case 0:{strcpy(icno, row[i]); break; }
			case 1:{strcpy(icname, row[i]); break; }
			case 2:{icnt = atoi(row[i]); break; }
			case 3:{isum = atof(row[i]); break; }
			case 4:{iavg = atof(row[i]); break; }
			case 5:{imin = atof(row[i]); break; }
			case 6:{imax = atof(row[i]); break; }
			}
		}
		printf("%s", icno);
		printf(" %s", icname);
		printf("  %d", icnt);
		printf("  %3.0f", isum);
		printf("  %3.0f", iavg);
		printf("  %3.0f", imin);
		printf("  %3.0f\n", imax);
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}

int using_cursor_to_list_table_names()
{
	result = mysql_list_tables(&mysql, "%");

	while ((row = mysql_fetch_row(result)) != NULL)
	{
		printf("%s \n", row[0]);
	}
	if (mysql_errno(&mysql))  // mysql_fetch_row() failed due to an error
	{
		fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
	}
	mysql_free_result(result);
	return (0);
}

int create_student_table()
{
	char yn[2];

	char tname[21] = "xxxxxxxxxxx";
	if (mysql_list_tables(&mysql, "student"))//删除表student
	{
		printf("The student table already exists,Do you want to delete it?\n");
		printf("Delete the table?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			if (mysql_query(&mysql, "delete from student;") == 0)
			{
				printf("Drop table student successfully!\n\n");
			}
			else
			{
				printf("ERROR: drop table student \n\n");
			}
		}
	}

	
	if (mysql_query(&mysql, "insert into student values('95001','李斌','男',16,'CS'),('95002','赵霞','女',18,'IS'),('95003','周淘','男',17,'CS'), ('95004', '钱乐','女',18,'IS') ,('95005','孙力','男',16,'MA');") == 0)
	{
		printf("Success to insert rows to student table!\n\n");
	}
	else
	{
		printf("ERROR: insert rows \n\n");
	}

	return(0);
}

int create_sc_table()
{
	char yn[2];

	if (mysql_list_tables(&mysql, "sc"))//删除表sc
	{
		printf("The sc table already exists,Do you want to delete it?\n");
		printf("Delete sc the table?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			if (!mysql_query(&mysql, "drop table sc;"))
			{
				printf("Drop table sc successfully!\n\n");
			}
			else
			{
				printf("ERROR: drop table sc \n\n");
			}
		}
	}

	//创建表sc
	//插入数据
	if (mysql_query(&mysql, "create table sc(sno char(5) not null,cno char(1),grade int,primary key(sno,cno), foreign key(sno) references student(sno), foreign key(cno) references course(cno)) engine=innodb;") == 0)
	{
		printf("create table sc successfully!\n\n");
	}
	else
	{
		printf("ERROR: create table sc \n\n");
	}

	if (mysql_query(&mysql, "insert into sc values('95001','1',66),('95001','2',77),('95001','3',88), ('95002', '1',90) ,('95005','1',94);") == 0)
	{
		printf("Success to insert rows to sc table!\n\n");
	}
	else
	{
		printf("ERROR: insert rows \n\n");
	}
	return(0);
}

int create_course_table()
{
	char yn[2];

	char tname[21] = "xxxxxxxxxxx";
	if (mysql_list_tables(&mysql, "course"))//删除表course
	{
		printf("The course table already exists,Do you want to delete it?\n");
		printf("Delete the table?(y--yes,n--no):");
		scanf("%s", &yn);
		if (yn[0] == 'y' || yn[0] == 'Y'){
			if (!mysql_query(&mysql, "drop table course;"))
			{
				printf("Drop table course successfully!\n\n");
			}
			else
			{
				printf("ERROR: drop table course \n\n");
			}
		}
	}

	//创建表course
	//插入数据
	if (mysql_query(&mysql, "create table course (cno char(1) NOT null primary key,cname char(10) null ,cpno char(1) null ,ccredit int null) engine=innodb;") == 0)
	{
		printf("create table course successfully!\n\n");
	}
	else
	{
		printf("ERROR: create table course \n\n");
	}

	if (mysql_query(&mysql, "insert into course values('1', 'C语言', '',3),('2', '数据库', '1',4),('3', '编译原理', '2',5),('4','数据结构', '3',2),('5', '操作系统','4',3) ;") == 0)
	{
		printf("Success to insert rows to course table!\n\n");
	}
	else
	{
		printf("ERROR: insert rows \n\n");
	}
	return(0);

}
int check_username_password()
{
	int num;
	char tname[21] = "xxxxxxxxxxx";
	char sname[11] = "guest";
	char spass[11] = "guest";
	char strquery[100] = "SELECT uclass FROM users WHERE uname ='";

	mysql_query(&mysql, "SET NAMES latin1;");  // 支持处理汉字  SET NAMES GBK; SET NAMES Gb2312;utf8

	if (mysql_list_tables(&mysql, "users"))//删除表users
	{
		//创建表users
		//插入数据
		if (mysql_query(&mysql, "drop users;create table users(uno char(6) NOT NULL PRIMARY KEY, uname char(10) NOT NULL, upassword varchar(10) NULL, uclass char(1) NULL DEFAULT 'A') engine=innodb;") == 0)
		{
			printf("create table users successfully!\n");
		}
		else
		{
			printf("error happend in table users already exist!\n\n");
		}

		mysql_query(&mysql, "SET NAMES latin1;");  // 支持处理汉字  SET NAMES GBK; SET NAMES Gb2312;utf8

		if (mysql_query(&mysql, "insert into users values('000001','admin','admin', 'Z'),('999999','guest','guest','A') ;") == 0)
		{
			printf("Success to insert rows to users table!\n\n");
		}
		else
		{
			printf("ERROR: insert rows \n\n");
		}
	}
	num = 0;
	while (num<3){  // 最多三次登录尝试
		printf("Please input user name(eg:guest):");
		scanf("%s", sname);
		printf("Please input user password(eg:guest):");
		scanf("%s", spass);
		strcat(strquery, sname);
		strcat(strquery, "' and upassword='");
		strcat(strquery, spass);
		strcat(strquery, "'");
		mysql_query(&mysql, strquery);
		result = mysql_store_result(&mysql);
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			strcpy(tname, row[0]);
		}
		if (strcmp(tname, "A") == 0 || strcmp(tname, "Z") == 0)
		{
			return(0);
		}
		else{
			strcpy(strquery, "SELECT uclass FROM users WHERE uname ='");
		}
		num++;
	}
	return(-1);
}

void pause()
{
	char junk[80], c;
	printf("Press any key to continue!");
	c = getchar();
	gets(junk);
}
