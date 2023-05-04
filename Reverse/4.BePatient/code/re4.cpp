#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include<cstring>
#include<string.h>
int love = 15;
uint32_t  k[4]={2,2,3,4};
uint32_t v[2]={3322276257,3274301584};
__attribute((constructor)) void before_main()
{
	love -= 1;
}
void encrypt (uint32_t *v,uint32_t *k ){
	uint32_t v0=v[0],v1=v[1],sum=0,i;
	uint32_t delta=0x9e3779b9;
	uint32_t k0=k[0],k1=k[1],k2=k[2],k3=k[3];
	for(i=0;i<32;i++){
		sum+=delta;
		v0+=((v1<<4)+k0)^(v1+sum)^((v1>>5)+k1);
		v1+=((v0<<4)+k2)^(v0+sum)^((v0>>5)+k3);
	} 
	v[0]=v0;v[1]=v1;
} 
__int64 gift(int n)
{
   if (n == 0|| n == 1)
   {
	   return 2;
   }
   else
   {
	   return gift(n-1)+ gift(n-2);
   }
}

void CCC(){
	char c[20];
	char b[20] = "zecdObe~";
	char s[100];
	printf("input whatever you want to input\n");
	scanf("%s",&c);
	strcpy(s,c);
	for(int i=0;i<strlen(c);i++){
		c[i] = c[i]^love+2;
	}
	printf("\n");
	if (strcmp(c,b)==0){
		printf("Done!\n");
	}else{
		printf("wrong!\n");
		exit(0);
	}
	printf("your gift is the flag!");
	printf("here is your flag %s_%lld",s,gift(114));
	printf("\n");
}
int main()
{		
	uint32_t data[2];
	printf("please start your performance.\nGive me two number to confirm your identity.\n");
	scanf("%d %d",&data[0],&data[1]);	
	encrypt(data,k);
	if (data[0] == v[0] && data[1] == v[1]){
		printf("OK!Be patient,you shoule solve the next challenge first and then i will give the gift to you!\n");
		CCC();	
	}else{
		printf("wrong!");
		exit(0);
	}
	return 0;
}
