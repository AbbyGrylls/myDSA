#include <stdio.h>
int main(){
char ch;
FILE *source,*target;
source=fopen("input.txt","r");
target=fopen("output.txt","w");
while((ch=fgetc(source))!=EOF){
fputc(ch,target);
}
fclose(source);
fclose(target);
}
