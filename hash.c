#include<stdio.h>
#include<string.h>
#include"head.h"

static int hash(void *s);
static struct book* sertIndex[2][16];
void InsertIndex(struct book* p, int n){//n = 0�����ŵĹ�ϣ��n = 1��������Ĺ�ϣ�� 
	int i;
	switch(n){
		case 0:{
			i = hash(&p->sign);
			if(sertIndex[n][i] == NULL){
				sertIndex[n][i] = p;
				p->next_hash_sign = NULL;
			} 
			p->next_hash_sign =  sertIndex[n][i]->next_hash_sign;
			sertIndex[n][i]->next_hash_sign = p;	
			break;
		}	
		
		case 1:{
			i = hash(p->name);
			if(sertIndex[n][i] == NULL){
				sertIndex[n][i] = p;
				p->next_hash_name = NULL;
			} 
			p->next_hash_name =  sertIndex[n][i]->next_hash_name;
			sertIndex[n][i]->next_hash_name = p;	
			break;
		}	
	}
}

struct book* Search(void* s, int n){//n = 0����Ų��ң�n = 1���������� 
	int i;
	struct book* np;
	switch(n){
		case 0:{
			i = hash(s);
			np = sertIndex[n][i];
			while(np != NULL && np->sign != *(unsigned int*)s)	np = np->next_hash_sign;
			break;
		} 	
		case 1:{
			i = hash(s);
			np = sertIndex[n][i];
			while(np != NULL && strcmp(np->name, (char*)s))	np = np->next_hash_name;
			break;
		} 	
	}
	return np;
}

void Delete_hash(struct book* p, int n){
	int i;
	struct book** np;
	switch(n){
		case 0:{
			i = hash(&p->sign);
			np = &sertIndex[n][i];
			if(np == NULL || *np == NULL)	return NULL;
			if((*np) == p){
				*np = NULL;
				return;
			} 
			while((*np)->next_hash_sign != p){
				np = &(*np)->next_hash_sign;
				if(*np == NULL)	return NULL;
			} 
			(*np)->next_hash_sign = p->next_hash_sign;
			break;
		}
		case 1:{
			i = hash(p->name);
			np = &sertIndex[n][i];
			if(np == NULL || *np == NULL)	return NULL;
			if((*np) == p){
				*np = NULL;
				return;
			}
			while((*np)->next_hash_name != p){
				np = &(*np)->next_hash_name;
				if(*np == NULL)	return NULL;
			} 
			(*np)->next_hash_name = p->next_hash_name;
			break;
		}
	}
}

static int hash(void* s){
	unsigned char c, sum = 0, *p;
	p = (unsigned char*)s;
	while(c = *p++)	sum += c;
	return (sum & 0x0f) ^ ((sum >> 4) & 0x0f);
}



