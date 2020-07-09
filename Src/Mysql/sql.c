/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-09-10 15:00:04
 *================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

MYSQL conn;/* 一个数据库结构体 */
MYSQL_RES * result;/* 一个结果集结构体 */
MYSQL_FIELD *field;/* 字段结构指针 */
MYSQL_ROW row;/* char** 二维数组，存放一条条记录 */
int nrow, ncolumn;

const char *g_host_name = "localhost";
const char *g_user_name = "root";
const char *g_password = "p@s#0fSPV";
const char *g_db_name = "pvault";
const unsigned int g_db_port = 3306;

void menu()
{
  //system("clear"); //清屏 
  printf("\n\t\t\t         主菜单\n"); 
  printf("\t\t\t#***************************#\n"); 
  printf("\t\t\t#       1--insert           #\n"); 
  printf("\t\t\t#       2--select           #\n"); 
  printf("\t\t\t#       3--delete           #\n"); 
  printf("\t\t\t#       4--update           #\n"); 
  printf("\t\t\t#***************************#\n"); 
  printf("\t\t\t      请选择(1 ~ 4) =:");
}

int main() {
    mysql_init(&conn);/* 初始化数据库 */
    //mysql_options(&conn, MYSQL_SET_CHARSET_NAME, "utf-8");/* 设置编码方式 */
        
    if (mysql_real_connect(&conn, g_host_name,g_user_name,g_password,g_db_name,g_db_port,NULL,0)) {/* 连接数据库 */
        int choose, res;
        char str1[20], str2[20];
        char insert_query[80];
        char delete_query[50] = "delete from person where name='";
        char select_query[] = "select * from person";

        while(1) { 
            menu();

            scanf("%d", &choose);

            switch (choose) {
                case 1:    //insert
                    printf("姓名 年龄：");
                    memset(insert_query, 0, sizeof(insert_query));
                    scanf("%s %s", str1, str2);
                    strcat(insert_query, "insert into person(name,age) values('");
                    strcat(insert_query, str1);
                    strcat(insert_query, "',");
                    strcat(insert_query, str2);
                    strcat(insert_query, ")");
                    printf("SQL语句: %s\n", insert_query);
                    res = mysql_query(&conn, insert_query);
                    if (!res) {
                        printf("insert %lu rows\n", (unsigned long)mysql_affected_rows(&conn));
                    }
                    else {
                        printf("insert error\n");
                    }
                    break;
                case 2:    //select            
                    printf("SQL语句: %s\n", select_query);
                    if (mysql_query(&conn, select_query) != 0) {
                        fprintf(stderr, "查询失败\n");
                        exit(1);
                    }
                    else {
                    if ((result = mysql_store_result(&conn)) == NULL) {// 获取结果集
                            fprintf(stderr, "保存结果集失败\n");
                            exit(1);
                        }
                        else {
                            ncolumn = mysql_num_fields(result);
                            nrow = mysql_num_rows(result);
                            printf("查到%d行\n",nrow);
                            int i,j;
                            for(i = 0;field = mysql_fetch_field(result);i++) {
                                printf("%10s",field->name);
                            }
                            puts("");
                            for(i = 1;i < nrow+1;i++){//按行输出结果
                                row = mysql_fetch_row(result);
                                for(j = 0;j< ncolumn;j++) {
                                    printf("%10s",row[j]);
                                }
                                puts("");
                            }

                            /*
                            while ((row = mysql_fetch_row(result)) != NULL) {//显示数据
                                printf("name is %s , ", row[0]);
                                printf("age is %s\n", row[1]);
                            }
                            */
                            mysql_free_result(result); /* 释放结果集 */
                        }
                    }
                    break;
                case 3:    //delete
                printf("姓名\n");
                    scanf("%s", str1);
                    strcat(delete_query, str1);
                    strcat(delete_query, "'");            
                    printf("SQL语句: %s\n", delete_query);
                res = mysql_real_query(&conn, delete_query, (unsigned int)strlen(delete_query));
                    if (!res) {
                        printf("delete successful\n");
                    }
                    else {
                        printf("delete error\n");
                    }
                    break;
                }
        }
        mysql_close(&conn);
    }
    return 0;
}

