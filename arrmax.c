// gcc -Wall arrmax.c -o arrmax && ./arrmax || echo $?
int main(){int a[]={12,7,3,4,5},m=a[0],i=1;while((i<7)&&(a[i]>m)&&((m=a[i++])||1));return m;}
