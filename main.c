#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include"head.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, m, i;
	struct book *head_sign = NULL, *head_name = NULL, *head_writer = NULL, *head_publish = NULL, *head_price = NULL, *p = NULL;
	char name[20];
	FILE* fp;
	while(1){
		static unsigned int sum = 0;
		printf("ִ����Ӧ�����������Ӧ���:\n");
		printf("\t[0]	���ص���һ��\n");
		printf("\t[1]	���ͼ��\n");
		printf("\t[2]	����ͼ��\n"); 
		printf("\t[3]	����ͼ��\n");
		printf("\t[4]	��ʾȫ��ͼ��\n");
		printf("\t[5]	����\n");
		printf("\t[6]	����\n");
		scanf("%d", &n);
		if(n != 5 && n != 6)system("cls");
		if(n == 0)	break;
		switch(n){
			case 1:
//				if(()) == NULL){
//					printf("�ռ䲻�㣡\n");
//					continue;
//				}
				printf("������ٱ�ͼ����Ϣ\n");
				scanf("%d", &n);
				for(i = 0; i < n; i++){
					p = (struct book*)malloc(sizeof(struct book));
					printf("������ͼ����Ϣ:���������ߣ������磬�۸�, ���\n");
					p->sign = sum++;
					scanf("%s%s%s%d%s", p->name, p->writer, p->publish, &p->price, p->intr);
					add_loop(&head_sign, p, next_sign, befo_sign);
					add_loop(&head_name, p, next_name, befo_name);
					add_loop(&head_writer, p, next_writer, befo_writer);
					add_loop(&head_publish, p, next_publish, befo_publish);
					add_loop(&head_price, p, next_price, befo_price);
					InsertIndex(p, 0);
					InsertIndex(p, 1);
				}
				SortAny(&head_sign, sum, next_sign, befo_sign, comp_sign, exch);
				SortAny(&head_name, sum, next_name, befo_name, comp_name, exch);
				SortAny(&head_writer, sum, next_writer, befo_writer, comp_writer, exch);
				SortAny(&head_publish, sum, next_publish, befo_publish, comp_publish, exch);
				SortAny(&head_price, sum, next_price, befo_price, comp_price, exch);
				system("cls");
				continue;
			case 2:
			 	while(1){
			 		if(m != 3){
			 			printf("��ѡ�����\������ѯ\n");
			 			printf("\t[0]	���ص���һ��\n");
						printf("\t[1]	���\n");
						printf("\t[2]	����\n");
						scanf("%d", &m);
						system("cls");
					}
					if(m == 0)	break;
					switch(m){
						case 1:
							printf("��������ţ�");
							scanf("%d", &m);
							p = Search(&m, 0);
							if(p == NULL){
								printf("û��������\n");
								continue;
							} 
							m = 3;
							continue;
						case 2:
							printf("������������");
							scanf("%s", name);
							p = Search(name, 1);
							if(p == NULL){
								printf("û��������\n");
								continue;
							}
							m = 3;
							continue;
						 case 3:
							while(1){
								printf("ִ����Ӧ�����������Ӧ���:\n");
								printf("\t[0]	���ص���һ��\n");
								printf("\t[1]	��ʾͼ����Ϣ\n");
								printf("\t[2]	ɾ��ͼ��\n");
								printf("\t[3]	�޸�ͼ��\n");
								scanf("%d", &m);
								if(m == 0)	break;
								switch(m){
									case 1:
										printf("��ţ�	%d\n", p->sign);
										printf("������	%s\n", p->name);
										printf("���ߣ�	%s\n", p->writer);
										printf("�����磺%s\n", p->publish);
										printf("�۸�	%d\n", p->price);
										printf("��飺	%s\n", p->intr);
										continue;
									case 2:
										delete_loop(&head_sign, p);
										Delete_hash(p, 0);
										Delete_hash(p, 1);
										sum--;
										free(p);
										continue;
									case 3:
										while(1){
											printf("ִ����Ӧ�����������Ӧ���:\n");
											printf("\t[0]	���ص���һ��\n");
											printf("\t[1]	�޸�����\n");
											printf("\t[2]	�޸�����\n");
											printf("\t[3]	�޸ĳ�����\n");
											printf("\t[4]	�޸ļ۸�\n"); 
											printf("\t[5]	�޸�ͼ����\n");
											printf("\t[6]	�޸�ͼ��ȫ����Ϣ\n");
											printf("\t[7]	��ʾͼ��ȫ����Ϣ\n");
											scanf("%d", &m);
											if(m == 0)	break;
											switch(m){
												case 1:
													scanf("%s", p->name);
													continue;
												case 2:
													scanf("%s", p->writer);
													continue;
												case 3:
													scanf("%s", p->publish);
													continue;
												case 4:
													scanf("%d", p->price);
													continue;
												case 5:
													scanf("%s", p->intr);
													continue;
												case 6:
													printf("�������������������ߣ������磬�۸����������\n");
													scanf("%s%s%s%d%s", p->name, p->writer, p->publish, p->price, p->intr);
													system("cls");
													continue;
												case 7:
													printf("��ţ�	%d\n", p->sign);
													printf("������	%s\n", p->name);
													printf("���ߣ�	%s\n", p->writer);
													printf("�����磺%s\n", p->publish);
													printf("�۸�	%d\n", p->price);
													printf("��飺	%s\n", p->intr);
													continue;
											}
										}
								}
							}
					} 
				}
				continue; 
//			case 3:
//				SortAny(&head_sign, sum, next_sign, comp_sign, exch);
//				SortAny(&head_name, sum, next_name, comp_name, exch);
//				SortAny(&head_writer, sum, next_writer, comp_writer, exch);
//				SortAny(&head_publish, sum, next_publish, comp_publish, exch);
//				SortAny(&head_price, sum, next_price, comp_price, exch);
//				continue;
			case 4:
				while(1){
					printf("ִ����Ӧ�����������Ӧ���:\n");
					printf("\t[0]	���ص���һ��\n");
					printf("\t[1]	�������ʾ\n");
					printf("\t[2]	��������ʾ\n");
					printf("\t[3]	��������ʾ\n");
					printf("\t[4]	����������ʾ\n");
					printf("\t[5]	���۸���ʾ\n");
					scanf("%d", &n);
					system("cls");
					if(n == 0) break;
					switch(n){
						case 1:
							for(i = 0, p = head_sign; i < sum; i++, p = p->next){
								printf("[%d]%s	���ߣ�%s	�����磺%s	�۸�%d\n", p->sign, p->name, p->writer, p->publish, p->price);
								printf("\t��飺%s\n", p->intr);
							}
							continue;
						case 2:
							for(i = 0, p = head_name; i < sum; i++, p = p->next_name){
								printf("[%d]%s	���ߣ�%s	�����磺%s	�۸�%d\n", p->sign, p->name, p->writer, p->publish, p->price);
								printf("\t��飺%s\n", p->intr);
							}
							continue;
						case 3:
							for(i = 0, p = head_writer; i < sum; i++, p = p->next_writer){
								printf("[%d]%s	���ߣ�%s	�����磺%s	�۸�%d\n", p->sign, p->name, p->writer, p->publish, p->price);
								printf("\t��飺%s\n", p->intr);
							}
							continue;
						case 4:
							for(i = 0, p = head_publish; i < sum; i++, p = p->next_publish){
								printf("[%d]%s	���ߣ�%s	�����磺%s	�۸�%d\n", p->sign, p->name, p->writer, p->publish, p->price);
								printf("\t��飺%s\n", p->intr);
							}
							continue;
						case 5:
							for(i = 0, p = head_price; i < sum; i++, p = p->next_price){
								printf("[%d]%s	���ߣ�%s	�����磺%s	�۸�%d\n", p->sign, p->name, p->writer, p->publish, p->price);
								printf("\t��飺%s\n", p->intr);
							}
							continue;
					}
				}
				continue;
			case 5:
				if((fp = fopen("books", "w+")) == NULL){
					printf("�洢����\n");
					continue; 
				}
				fprintf(fp, "%d\n", sum);
				for(i = 0, p = head_sign; i < sum; i++, p = p->next){
					fprintf(fp,"%d %s %s %s %d \n", p->sign, p->name, p->writer, p->publish, p->price);
					fprintf(fp,"%s\n", p->intr);
				}
				fclose(fp);
				continue;
			case 6:
				if((fp = fopen("books", "r")) == NULL){
					printf("��ȡ����\n");
					continue; 
				}
				fscanf(fp, "%d", &sum);
				for(i = 0; i < sum; i++){
					p = (struct book*)malloc(sizeof(struct book));
					fscanf(fp,"%d%s%s%s%d", &p->sign, p->name, p->writer, p->publish, &p->price);
					fscanf(fp,"%s", p->intr);
					add_loop(&head_sign, p, next_sign, befo_sign);
					add_loop(&head_name, p, next_name, befo_name);
					add_loop(&head_writer, p, next_writer, befo_writer);
					add_loop(&head_publish, p, next_publish, befo_publish);
					add_loop(&head_price, p, next_price, befo_price);
					InsertIndex(p, 0);
					InsertIndex(p, 1);
				}
				SortAny(&head_sign, sum, next_sign, befo_sign, comp_sign, exch);
				SortAny(&head_name, sum, next_name, befo_name, comp_name, exch);
				SortAny(&head_writer, sum, next_writer, befo_writer, comp_writer, exch);
				SortAny(&head_publish, sum, next_publish, befo_publish, comp_publish, exch);
				SortAny(&head_price, sum, next_price, befo_price, comp_price, exch);
				fclose(fp);
				continue;
		}
	}
	free(head_sign);	
}
